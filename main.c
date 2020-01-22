#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"
#include "gauss.h"
#include "holdvar.h"
#include "tinyexpr.h"
#include "helpfunction.h"
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <windows.h>
#include <omp.h>

char *version = "3.0";

//Это новая итерация?
bool isNewIteration[1000];

typedef enum {
	Black = 0,
	Grey = FOREGROUND_INTENSITY,
	LightGrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Blue = FOREGROUND_BLUE,
	Green = FOREGROUND_GREEN,
	Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
	Red = FOREGROUND_RED,
	Purple = FOREGROUND_RED | FOREGROUND_BLUE,
	LightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	LightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	LightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	LightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
	LightPurple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Orange = FOREGROUND_RED | FOREGROUND_GREEN,
	Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
} ConsoleColor;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	double Mx;
	double Sigma;
	bool isError;
	double epsilon;
	long long N;
	double secondsFirstsNComputing;
} expressionResult;

double gradToRad(double grad) {
	return 3.1415926535897932384626433832795 * grad / 180.0;
}

double radToGrad(double rad) {
	return rad / 3.1415926535897932384626433832795 * 180.0;
}



int userFuncCount = 140;
te_variable vars[] = {
	{"gauss", gaussFromRange, TE_FUNCTION2}, /* TE_FUNCTION2 used because my_sum takes two arguments. */
	{"gmm", gaussFromRange, TE_FUNCTION2},
	{"nominal_g", nominal_gaussFromMinMax, TE_FUNCTION2},
	{"deg2rad", gradToRad, TE_FUNCTION1},
	{"rad2deg", radToGrad, TE_FUNCTION1},
	{"gauss_percents", gaussFromNominalAndPercentDeviations, TE_FUNCTION3},
	{"gpp", gaussFromNominalAndPercentDeviations, TE_FUNCTION3},
	{"nominal_g_percents", nominal_gaussFromNominalAnd2Deviations, TE_FUNCTION3},
	{"gauss_down_up", gaussFromNominalAndUpDownDeviations, TE_FUNCTION3},
	{"gdu", gaussFromNominalAndUpDownDeviations, TE_FUNCTION3},
	{"nominal_g_down_up", nominal_gaussFromNominalAnd2Deviations, TE_FUNCTION3},
	{"link1", link1, TE_FUNCTION1},
	{"link2", link2, TE_FUNCTION1},
	{"link3", link3, TE_FUNCTION1},
	{"link4", link4, TE_FUNCTION1},
	{"link5", link5, TE_FUNCTION1},
	{"link6", link6, TE_FUNCTION1},
	{"link7", link7, TE_FUNCTION1},
	{"link8", link8, TE_FUNCTION1},
	{"link9", link9, TE_FUNCTION1},
	{"link10", link10, TE_FUNCTION1},
	{"link11", link11, TE_FUNCTION1},
	{"link12", link12, TE_FUNCTION1},
	{"link13", link13, TE_FUNCTION1},
	{"link14", link14, TE_FUNCTION1},
	{"link15", link15, TE_FUNCTION1},
	{"link16", link16, TE_FUNCTION1},
	{"link17", link17, TE_FUNCTION1},
	{"link18", link18, TE_FUNCTION1},
	{"link19", link19, TE_FUNCTION1},
	{"link20", link20, TE_FUNCTION1},
	{"link21", link21, TE_FUNCTION1},
	{"link22", link22, TE_FUNCTION1},
	{"link23", link23, TE_FUNCTION1},
	{"link24", link24, TE_FUNCTION1},
	{"link25", link25, TE_FUNCTION1},
	{"link26", link26, TE_FUNCTION1},
	{"link27", link27, TE_FUNCTION1},
	{"link28", link28, TE_FUNCTION1},
	{"link29", link29, TE_FUNCTION1},
	{"link30", link30, TE_FUNCTION1},
	{"link31", link31, TE_FUNCTION1},
	{"link32", link32, TE_FUNCTION1},
	{"link33", link33, TE_FUNCTION1},
	{"link34", link34, TE_FUNCTION1},
	{"link35", link35, TE_FUNCTION1},
	{"link36", link36, TE_FUNCTION1},
	{"link37", link37, TE_FUNCTION1},
	{"link38", link38, TE_FUNCTION1},
	{"link39", link39, TE_FUNCTION1},
	{"link40", link40, TE_FUNCTION1},
	{"link41", link41, TE_FUNCTION1},
	{"link42", link42, TE_FUNCTION1},
	{"link43", link43, TE_FUNCTION1},
	{"link44", link44, TE_FUNCTION1},
	{"link45", link45, TE_FUNCTION1},
	{"link46", link46, TE_FUNCTION1},
	{"link47", link47, TE_FUNCTION1},
	{"link48", link48, TE_FUNCTION1},
	{"link49", link49, TE_FUNCTION1},
	{"link50", link50, TE_FUNCTION1},
	{"link51", link51, TE_FUNCTION1},
	{"link52", link52, TE_FUNCTION1},
	{"link53", link53, TE_FUNCTION1},
	{"link54", link54, TE_FUNCTION1},
	{"link55", link55, TE_FUNCTION1},
	{"link56", link56, TE_FUNCTION1},
	{"link57", link57, TE_FUNCTION1},
	{"link58", link58, TE_FUNCTION1},
	{"link59", link59, TE_FUNCTION1},
	{"link60", link60, TE_FUNCTION1},
	{"link61", link61, TE_FUNCTION1},
	{"link62", link62, TE_FUNCTION1},
	{"link63", link63, TE_FUNCTION1},
	{"link64", link64, TE_FUNCTION1},
	{"link65", link65, TE_FUNCTION1},
	{"link66", link66, TE_FUNCTION1},
	{"link67", link67, TE_FUNCTION1},
	{"link68", link68, TE_FUNCTION1},
	{"link69", link69, TE_FUNCTION1},
	{"link70", link70, TE_FUNCTION1},
	{"link71", link71, TE_FUNCTION1},
	{"link72", link72, TE_FUNCTION1},
	{"link73", link73, TE_FUNCTION1},
	{"link74", link74, TE_FUNCTION1},
	{"link75", link75, TE_FUNCTION1},
	{"link76", link76, TE_FUNCTION1},
	{"link77", link77, TE_FUNCTION1},
	{"link78", link78, TE_FUNCTION1},
	{"link79", link79, TE_FUNCTION1},
	{"link80", link80, TE_FUNCTION1},
	{"link81", link81, TE_FUNCTION1},
	{"link82", link82, TE_FUNCTION1},
	{"link83", link83, TE_FUNCTION1},
	{"link84", link84, TE_FUNCTION1},
	{"link85", link85, TE_FUNCTION1},
	{"link86", link86, TE_FUNCTION1},
	{"link87", link87, TE_FUNCTION1},
	{"link88", link88, TE_FUNCTION1},
	{"link89", link89, TE_FUNCTION1},
	{"link90", link90, TE_FUNCTION1},
	{"link91", link91, TE_FUNCTION1},
	{"link92", link92, TE_FUNCTION1},
	{"link93", link93, TE_FUNCTION1},
	{"link94", link94, TE_FUNCTION1},
	{"link95", link95, TE_FUNCTION1},
	{"link96", link96, TE_FUNCTION1},
	{"link97", link97, TE_FUNCTION1},
	{"link98", link98, TE_FUNCTION1},
	{"link99", link99, TE_FUNCTION1},
	{"link100", link100, TE_FUNCTION1},
	{"v_vruncated_cone", volumeOfTruncatedCone_diameter, TE_FUNCTION3},
	{"v_vruncated_cone_r", volumeOfTruncatedCone_radius, TE_FUNCTION3},
	{"v_truncated_conical_shell", volumeOfTruncatedConicalShell_diameter, TE_FUNCTION5},
	{"v_truncated_conical_shell_r", volumeOfTruncatedConicalShell_radius, TE_FUNCTION5},
	{"v_cone", volumeOfCone_diameter, TE_FUNCTION2},
	{"v_cone_r", volumeOfCone_radius, TE_FUNCTION2},
	{"v_cylinder", volumeOfCylinder_diameter, TE_FUNCTION2},
	{"v_cylinder_r", volumeOfCylinder_radius, TE_FUNCTION2},
	{"v_cylindrical_shell", volumeOfCylindricalShell_diameter, TE_FUNCTION3},
	{"v_cylindrical_shell_r", volumeOfCylindricalShell_radius, TE_FUNCTION3},
	{"v_sphere", volumeOfSphere_diameter, TE_FUNCTION1},
	{"v_sphere_r", volumeOfSphere_radius, TE_FUNCTION1},
	{"v_spherical_shell", volumeOfSphericalShell_diameter, TE_FUNCTION2},
	{"v_spherical_shell_r", volumeOfSphericalShell_radius, TE_FUNCTION2},
	{"v_wedge_rotation",   volumeOfWedgeRotation_diameter, TE_FUNCTION3},
	{"v_wedge_rotation_r", volumeOfWedgeRotation_radius, TE_FUNCTION3},
	{"v_spherical_segment",   volumeOfSphericalSegment_diameter, TE_FUNCTION2},
	{"v_spherical_segment_r", volumeOfSphericalSegment_radius, TE_FUNCTION2},
	{"v_spherical_layer",   volumeOfSphericalLayer_diameter, TE_FUNCTION3},
	{"v_spherical_layer_r", volumeOfSphericalLayer_radius, TE_FUNCTION3},
	{"v_spherical_sector",   volumeOfSphericalSector_diameter, TE_FUNCTION2},
	{"v_spherical_sector_r", volumeOfSphericalSector_radius, TE_FUNCTION2},
	{"v_intersection_cylinders",   volumeOfIntersectionCylinders_diameter, TE_FUNCTION2},
	{"v_intersection_cylinders_r", volumeOfIntersectionCylinders_radius, TE_FUNCTION2},
	{"s_circle",   squareOfCircle_diameter, TE_FUNCTION1},
	{"s_circle_r", squareOfCircle_radius, TE_FUNCTION1},
	{"l_reamer90", lengthOfReamer90, TE_FUNCTION5},
	{"ost_bevel_and_rounded_radius", gauss_OST_BevelAndRoundedRadius, TE_FUNCTION1},
	{"ost_not_hole_and_shaft", gauss_OST_NotHoleAndShaft, TE_FUNCTION1},
};
//te_expr *n = te_compile( "mysum( 5, 6) ", vars, 1, 0) ;
//{"comment", userComment, TE_FUNCTION1},

double cumulativeMovingAverage(double a_n, double CMA, long long n) {
	return (a_n + (n-1) * CMA) / (double)n;
}

void getText(char *variable, int size) {
	fgets(variable, sizeof(char)*size, stdin);
	sscanf(variable, "%[^\n]", variable);
}

bool setcolor(ConsoleColor color)
{
   static HANDLE handle = NULL;
 
   if (handle == NULL)
   {
      handle = GetStdHandle(STD_OUTPUT_HANDLE);
   }
 
   return SetConsoleTextAttribute(handle, color);
}

void setConsoleDefaultColor() {
	//setcolor(LightGrey);
	setcolor(White);
}

void setConsoleInputColor() {
	//setcolor(Green);
	setcolor(LightGreen);
}

// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int readFileExpression(char *filepath, char **resultExpression) {
	int MAXCHAR2 = 1000;
	FILE *fp;
    char str[MAXCHAR2];
    
    char *expression = "";
 
    fp = fopen(filepath, "r");
    if (fp == NULL){
        printf("Could not open file %s",filepath);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        expression = concat(expression, str);
    fclose(fp);
    //printf("expression = %s\n", expression);
    *resultExpression = expression;
    
    return 0;
}


void printErrorPosition(char *str, ConsoleColor errorColor, ConsoleColor mainColor, int errorPosition) { 
	for (int i = 0; i < strlen(str); i++) {
		if (i == errorPosition) {
			setcolor(errorColor);
		}
		else {
			setcolor(mainColor);
		}
		printf("%c", str[i]);
	}
}

char* strToOEM(char *str, int bufSize) {
	char bufout[bufSize];
	CharToOemBuff(str, bufout, bufSize);
	return bufout;
}

char* strToOEMEasy(char *str) {
	int bufSize = 4*strlen(str);
	if (bufSize < 150) {
		bufSize = 150;
	}
	return strToOEM(str, bufSize);
}

int getNumberOnPositionAfterPoint(double var, int position) {
	int intPart = (int)var;
	double fractionPart = var - (double)intPart;
	double newVar = fractionPart * pow(10, position);
	int intPartNewVar = (int)newVar;
//	double fractionParNewVatNewVar = newVar - (double)intPartNewVar;
//	double resultVarWithFrac = fractionParNewVatNewVar * 10;
//	int resultVar = (int)resultVarWithFrac;
//	return resultVar;
	return newVar;
}

//bool isNumberOnPositionChanged(double var, int position, int maxCount) {
//	static int count = 0;
//	static int previousValue;
//	int currentValue = getNumberOnPositionAfterPoint(var, position);
//	if (count == 0) {
//		previousValue = currentValue;
//		count++;
//		//printf("%d\n", count);
//		return true;
//	}
//	else {
//		if (previousValue == currentValue ) {
//			if (count >= maxCount) {
//				return false;
//			}
//			count++;
//		} else {
//			count = 0;
//		}
//		//printf("%d\n", count);
//		previousValue = currentValue;
//		return true;
//	}
//}

/*
Q	0.99  0.999  0.9999
F2	6.61  10.9   15.2
*/
double F2 = 10.9;

double epsilonForAccuracy(double sigma_x, long long N) {
 	double epsilon = sigma_x / sqrt(N / F2);
 	return epsilon;
}

long long countNumberForAccuracy(double sigma_x, double epsilon) {
	double N = F2 * pow( (sigma_x / epsilon), 2);
	//printf("%f\n", N);
	return (long long)N;
}

char* timeFormat(double seconds) {
	char result[300];
	if (seconds < 60) {
		sprintf(result, "%.1f %s", seconds, strToOEMEasy("секунды"));
	}
	else if (seconds < 60*60) {
		sprintf(result, "%.1f %s", seconds/60, strToOEMEasy("минуты"));
	}
	else if (seconds < 60*60*24) {
		sprintf(result, "%.1f %s", seconds/3600, strToOEMEasy("часа"));
	}
	else if (seconds < 60*60*24*365) {
		sprintf(result, "%.1f %s", seconds/86400, strToOEMEasy("дня"));
	}
	else {
		sprintf(result, "%.1f %s", seconds/86400/365, strToOEMEasy("года"));
	}
	return result;
}

double digitsForRoundFromEpsilon(double epsilon) {
	int intPart = (int)epsilon;
	if (intPart > 0) {
		return 0;
	}
	for (int position = 1; position <= 63; position++) {
		int value = getNumberOnPositionAfterPoint(epsilon, position);
		//printf("%d\n", value);
		if (value != 0) {
			return position;
		}
	}
	return 6;
}

double fround(double value, int digitsAfterPoint) {
	return round(value*pow(10,digitsAfterPoint))/pow(10,digitsAfterPoint);
}

expressionResult computingExpression(char *expression, double epsilon, char *filePath, bool estimation) {
	int isError = 0;
	
	long long minimum_computingCount = 5001;
	long long computingCount = minimum_computingCount;
	
	expressionResult result = {0, 0, FALSE};
	
	double CMA = 0;
	//double previousCMA = 0;
	double CMA_square = 0;
	
	double exit_CMA = 0;
	double exit_CMA_square = 0;
	
	long long numberOfCalc;
    
//    if (estimation) {
//    	printf("%s\n", strToOEMEasy("Создаю подсказку по времени выполнения и точности вычислений"));
//	}
	
    int percentComplete = 0;
    clock_t percentTimeCurrent, percentTimePrevious, startTimeComputing; //В миллисекундах
    double  timeToEstimation, timeToComplite; //В секундах
    percentTimeCurrent = clock();
	
	int err;
	double resultIter;
	
	///int max_threads = omp_get_max_threads();
	///#pragma omp parallel for reduction(+:CMA, CMA_square)
	///for (long long j = 0; j < max_threads; j++) {
		te_expr *n = te_compile(expression, vars, userFuncCount, &err);
		
		for (long long i = 1; i <= computingCount; i++) {
			
			//expression = "gauss(7-0.3,7+0.3) + gauss(15-0.3,15+0.3);
			//printf("i = %d\n", i);
			newIteration();
			
			if (n) {
				resultIter = te_eval(n);
				//printf("%f\n", resultIter);			
			} else {
				isError = 1;
				setcolor(LightRed);
	        	printf("\n%s %d ", strToOEMEasy("Ошибка на"), err-1);
	        	printf("%s\n", strToOEMEasy("символе \(подсвечена красным цветом шрифта\):"), err-1);
	        	printErrorPosition(expression, LightRed, Grey, err-1);
	        	printf("\n\n");
	        	setConsoleDefaultColor();
	        	break;
	    	}
	    	
	    	if (!isError) {
	    		CMA = cumulativeMovingAverage(resultIter, CMA, i);
				CMA_square = cumulativeMovingAverage(resultIter * resultIter, CMA_square, i);
				
				//Прогресс сознания подсказки
	//			if (estimation) {
	//				if( (int)(0.8 * i * 100 / (minimum_computingCount-1)) != percentComplete) {
	//					percentComplete = (int)(0.8*i * 100 / (minimum_computingCount-1));
	//					setcolor(Yellow);
	//					printf("#");
	//				setConsoleDefaultColor();
	//				}
	//			}
				
				if (i == 1) {
					if (!estimation) {
						system("cls");
						printf("%s", strToOEMEasy("Определяю необходимое количество итераций для достижения заданной точности.\n"));
					}
					startTimeComputing = clock();
				} else if (i == minimum_computingCount-1) {
					double std_deviation = sqrt(CMA_square - CMA * CMA);
					computingCount = countNumberForAccuracy(std_deviation, epsilon);
					timeToEstimation = ( (double)(clock() - startTimeComputing) / 1000000.0 ) * 1000; //Время выполнения для оценки кол-ва итераций
					timeToComplite = timeToEstimation * (double)computingCount / (double)minimum_computingCount;
					if (!estimation) {
						printf("%s %lli", strToOEMEasy("Необходимо произвести"), computingCount);
						printf(" %s\n", strToOEMEasy("вычислений."));
						printf("%s", strToOEMEasy("До окончания рассчетов осталось примерно"));
						printf(" %s\n", timeFormat(timeToComplite));
					} else {
						result.secondsFirstsNComputing = timeToEstimation;
						result.N = i;
						break;
					}
				} else if (i > minimum_computingCount-1) {
					//Прогресс выполнения
					if (!estimation) {
						if( (i * 100 / computingCount) != percentComplete) {
							percentComplete = i * 100 / computingCount;
							percentTimePrevious = percentTimeCurrent;
							percentTimeCurrent = clock();
							double diff = ( (double)(percentTimeCurrent - percentTimePrevious) / 1000000.0 ) * 1000;
							timeToComplite = diff * (100 - percentComplete);
							
							system("cls");
							setcolor(Yellow);
							for(int j=0; j <= (0.78*percentComplete); j++) {
								printf("#");
							}
							setConsoleDefaultColor();
							printf("\n");
							printf("%d%%, ", percentComplete);
							printf("%s", strToOEMEasy("до окончания расчетов осталось примерно"));
							printf(" %s\n", timeFormat(timeToComplite));
						}
					}
				}
				
				
			}
			
			numberOfCalc = i;
		}
		
		te_free(n);
	//}
	
	
	
	double diff = ((double)(clock() - startTimeComputing) / 1000000.0 ) * 1000;
	
	if (!isError) {
		double std_deviation_square = CMA_square - CMA * CMA;
		double std_deviation = sqrt(std_deviation_square);
		
		double epsilonReal = epsilonForAccuracy(std_deviation, numberOfCalc);
		int digitsForRound = digitsForRoundFromEpsilon(epsilonReal);
		
		result.Mx = CMA;
		result.Sigma = std_deviation;
		result.epsilon = epsilonReal;
		
		if (estimation) {
			return result;
		}
		
		system("cls");
		setConsoleDefaultColor();
		
		printf("===============================================================================");
		printf(strToOEMEasy("\n--------------------------------ИСХОДНЫЕ ДАННЫЕ--------------------------------\n"));
		printf("===============================================================================\n");
		printf("%s %s\n", strToOEMEasy("ВЕРСИЯ ПРИЛОЖЕНИЯ:"), version);
		printf("\n%s%s\n", strToOEMEasy("ФАЙЛ С ВЫРАЖЕНИЕМ ДЛЯ РАСЧЕТОВ: "), strToOEMEasy(filePath));
		printf("\n%s", strToOEMEasy("ВЫРАЖЕНИЕ: "));
		printf("%s\n", expression);
		printf("\n%s%lli", strToOEMEasy("Выражение было вычислено "), numberOfCalc);
		printf("%s", strToOEMEasy(" раз за "));
		printf("%s\n", timeFormat(diff));
		printf("%s%g\n", strToOEMEasy("Заданная точность вычислений (epsilon): "), epsilon);
		setcolor(Yellow);
		printf("%s%g\n", strToOEMEasy("Фактическая точность вычислений (epsilon): "), epsilonReal);
		printf("%s\n", strToOEMEasy("Уровень доверия Q = 0.999"));
		setConsoleDefaultColor();
		printf("\n===============================================================================");
		printf(strToOEMEasy("\n-----------------------------РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ-----------------------------\n"));
		printf("===============================================================================\n");
		//printf("\n%s%f\n", strToOEMEasy("Математическое ожидание (Mx) = "), CMA);
		printf("\n%s%g\n", strToOEMEasy("Математическое ожидание (Mx) = "), fround(CMA, digitsForRound) );
		printf("%s%g\n", strToOEMEasy("|mx - Mx| < "), epsilonReal );
		//printf("\n%s%f\n", strToOEMEasy("Среднеквадратическое отклонение (sigma) = "), std_deviation);
		printf("\n%s%g\n", strToOEMEasy("Среднеквадратическое отклонение (sigma) = "), fround(std_deviation, digitsForRound));
		//printf("\n%s%f\n", strToOEMEasy("Поле допуска (6*sigma) = "), 6 * std_deviation);
		printf("\n%s%g\n", strToOEMEasy("Поле допуска (6*sigma) = "), fround(6 * std_deviation, digitsForRound));
		printf("%s%g\n", strToOEMEasy("Поле допуска c учетом epsilon = "), fround(6 * std_deviation + 2* epsilonReal, digitsForRound));
		printf("\n-------------------------------------------------------------------------------");
		setcolor(Yellow);
		printf("\n=> %s %.*f +- %.*f\n", strToOEMEasy("Результат по мат. ожиданию:      "), digitsForRound, fround(CMA, digitsForRound), digitsForRound, fround(3 * std_deviation, digitsForRound));
		printf("=> %s %.*f +- %.*f\n",   strToOEMEasy("C учетом epsilon:                "), digitsForRound, fround(CMA, digitsForRound), digitsForRound, fround(3 * std_deviation + epsilonReal, digitsForRound));
		double percentSimmEps = fround(100 * (3 * std_deviation + epsilonReal) / CMA, digitsForRound);
		if (percentSimmEps > 0) {
			printf("=> %s %.*f +- %.*f%%\n",   strToOEMEasy("C учетом epsilon и допусками в %:"), digitsForRound, fround(CMA, digitsForRound), digitsForRound, percentSimmEps);
		}
		setConsoleDefaultColor();
		printf("-------------------------------------------------------------------------------\n");
		
		//Вычисление номинального значения
		double nominalValue;
		newIteration();
		char *expressionNominal = str_replace(expression,  "gauss_down_up",  "nominal_g_down_up");
		expressionNominal = str_replace(expressionNominal, "gdu",            "nominal_g_down_up");
		expressionNominal = str_replace(expressionNominal, "gauss_percents", "nominal_g_percents");
		expressionNominal = str_replace(expressionNominal, "gpp",            "nominal_g_percents");
		expressionNominal = str_replace(expressionNominal, "gauss",          "nominal_g");
		expressionNominal = str_replace(expressionNominal, "gmm",            "nominal_g");
		//printf("%s\n", expressionNominal);
		te_expr *n = te_compile(expressionNominal, vars, userFuncCount, &err);
		if (n) {
			nominalValue = te_eval(n);
			te_free(n);
			double correction = result.Mx - nominalValue;
			double upDeviation = fround(3 * result.Sigma + correction, digitsForRound);
			double downDeviation = fround(-3 * result.Sigma + correction, digitsForRound);
			double upDeviationEps = fround(3 * result.Sigma + correction + result.epsilon, digitsForRound);
			double downDeviationEps = fround(-3 * result.Sigma + correction - result.epsilon, digitsForRound);
			double upDeviationEpsCent =  fround(100 * upDeviationEps / nominalValue, digitsForRound);
			double downDeviationEpsCent =  fround(100 * downDeviationEps / nominalValue, digitsForRound);
//			char *plusUp = "+";
//			char *plusDown = "+";
//			char *plusUpEps = "+";
//			char *plusDownEps = "+";
//			if (upDeviation < 0) {
//				plusUp = "";
//			}
//			if (downDeviation < 0) {
//				plusDown = "";
//			}
//			if (upDeviationEps < 0) {
//				plusUpEps = "";
//			}
//			if (downDeviationEps < 0) {
//				plusDownEps = "";
//			}
			printf("\n-------------------------------------------------------------------------------");
			setcolor(Yellow);
			int digitsForRound = digitsForRoundFromEpsilon(result.epsilon);
			nominalValue = fround(nominalValue, digitsForRound);
			printf("\n=> %s %.*f (%+.*f, %+.*f)\n",   strToOEMEasy("Результат по номиналу:           "), digitsForRound, nominalValue, digitsForRound, upDeviation, digitsForRound, downDeviation );
			printf("=> %s %.*f (%+.*f, %+.*f)\n",     strToOEMEasy("C учетом epsilon:                "), digitsForRound, nominalValue, digitsForRound, upDeviationEps, digitsForRound, downDeviationEps );
			if (upDeviationEpsCent != 0 || downDeviationEpsCent != 0) {
				printf("=> %s %.*f (%+.*f%%, %+.*f%%)\n", strToOEMEasy("C учетом epsilon и допусками в %:"), digitsForRound, nominalValue, digitsForRound, upDeviationEpsCent, digitsForRound, downDeviationEpsCent );
			}
			
			setConsoleDefaultColor();
			printf("-------------------------------------------------------------------------------\n");			
		} else {
			isError = 1;
        	printf("%s %d ", strToOEMEasy("Ошибка на"), err-1);
        	printf("%s\n", strToOEMEasy("символе \(подсвечена красным цветом шрифта\):"), err-1);
        	printErrorPosition(expressionNominal, LightRed, Grey, err-1);
        	printf("\n\n");
        	setConsoleDefaultColor();
    	}
		
	}
	else {
		result.isError = TRUE;
	}
	
	return result;
}

void printAboutProgram() {
	setcolor(LightGrey);
	printf("\n\n%s %s\n\n", strToOEMEasy("VariableExpressions, версия"), version);
	printf("%s\n", strToOEMEasy("Программа для вычисления выражений вероятностным методом. Позволяет"));
	printf("%s\n", strToOEMEasy("вычислять любые выражения, в которых присутствуют величины с допусками"));
	printf("%s\n", strToOEMEasy("\(например, размерные цепи, определение допуска положения центра масс"));
	printf("%s\n", strToOEMEasy("и т.д.\). Идея приложения заключается в том, чтобы многократно вычислять"));
	printf("%s\n", strToOEMEasy("заданное выражение, каждый раз вычисляя конкретные значения величин"));
	printf("%s\n", strToOEMEasy("с допусками в соответствии с нормальным законом их распределения."));
	printf("%s\n", strToOEMEasy("Имея в распоряжении массив вычисленных значений, можно определить для"));
	printf("%s\n\n", strToOEMEasy("него математическое ожидание и среднеквадратичное отклонение."));
	printf("%s\n\n", strToOEMEasy("Абидуллин Р.Р., 2017"));
	setConsoleDefaultColor();
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	SetConsoleCP (1251); 
    SetConsoleOutputCP (866);
    //system("chcp");
    
    setConsoleDefaultColor();
	
	//----
	char path[10000];
	setcolor(Yellow );
	printf("VariableExpressions, ");
	printf("\%s %s\n\n", strToOEMEasy("версия"), version);
	setConsoleDefaultColor();
	printf("%s", strToOEMEasy("Перенесите файл с выражением на это окно, затем нажмите клавишу Enter.\n"));
	setcolor(Grey);
	printf("%s", strToOEMEasy("О том, как подготовить файл с выражением, читайте в прилагающемся руководстве\nпользователя.\n\n"));
	setConsoleInputColor();
	getText(path, 10000);
	setConsoleDefaultColor();
	
	
	//Удаление ковычек
	//char path1[10000];
	//strcpy(path1, &(path[1]) );
	//char path2[10000];
	//strncpy(path2, path1, strlen(path1)-1);
	char *withoutCommas = str_replace(path, "\"", "");
	
	//printf("path = %s\n", path2);
	
	//Чтение файла
	char *file_contents;
	//char *correctPath = str_replace(path2, "\\", "\\\\");
	char *correctPath = str_replace(withoutCommas, "\\", "\\\\");
	//printf("correctPath = %s\n", correctPath);
	readFileExpression(correctPath, &file_contents);
	//printf("file_contents = %s\n", file_contents);
	
	
	
	
	
	//expressionResult estimatedResult = computingExpression(file_contents, 0, path2, true);
	expressionResult estimatedResult = computingExpression(file_contents, 0, withoutCommas, true);
	//printf("Sigma = %f\n", estimatedResult.Sigma);
	//printf("epsilon = %f\n", estimatedResult.epsilon);
	//printf("N = %lli\n", estimatedResult.N);
	//printf("secondsFirstsNComputing = %f\n", estimatedResult.secondsFirstsNComputing);
	
	if (estimatedResult.isError) {
		system("pause");
		return 0;
	}
	
	
	double estimatedEpsilon_1min = estimatedResult.Sigma / sqrt( (60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_5min = estimatedResult.Sigma / sqrt( (5*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_30min = estimatedResult.Sigma / sqrt( (30*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_1hour = estimatedResult.Sigma / sqrt( (60*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_4hour = estimatedResult.Sigma / sqrt( (4*60*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_8hour = estimatedResult.Sigma / sqrt( (8*60*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_15hour = estimatedResult.Sigma / sqrt( (15*60*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);
	double estimatedEpsilon_1day = estimatedResult.Sigma / sqrt( (24*60*60.0 * estimatedResult.N / estimatedResult.secondsFirstsNComputing) / F2);

	double estimatedTime_0p1 = pow(estimatedResult.Sigma / 0.1, 2) * estimatedResult.secondsFirstsNComputing * F2 / estimatedResult.N;
	double estimatedTime_0p01 = pow(estimatedResult.Sigma / 0.01, 2) * estimatedResult.secondsFirstsNComputing * F2 / estimatedResult.N;
	double estimatedTime_0p001 = pow(estimatedResult.Sigma / 0.001, 2) * estimatedResult.secondsFirstsNComputing * F2 / estimatedResult.N;
	double estimatedTime_0p0001 = pow(estimatedResult.Sigma / 0.0001, 2) * estimatedResult.secondsFirstsNComputing * F2 / estimatedResult.N;
			
	setcolor(Grey);
	printf("\n");
	printf("%s\n", strToOEMEasy("ПОДСКАЗКА:"));
	printf("\n%s", strToOEMEasy("Точность расчета      Время расчета (ориентировочно)"));
	printf("\n%.9f           %s", 0.1, timeFormat(estimatedTime_0p1));
	printf("\n%.9f           %s", 0.01, timeFormat(estimatedTime_0p01));
	printf("\n%.9f           %s", 0.001, timeFormat(estimatedTime_0p001));
	printf("\n%.9f           %s", 0.0001, timeFormat(estimatedTime_0p0001));
	printf("\n%.9f%s", estimatedEpsilon_1min,   strToOEMEasy("           1 минута"));
	printf("\n%.9f%s", estimatedEpsilon_5min,   strToOEMEasy("           5 минут"));
	printf("\n%.9f%s", estimatedEpsilon_30min,  strToOEMEasy("           30 минут"));
	printf("\n%.9f%s", estimatedEpsilon_1hour,  strToOEMEasy("           1 час"));
	printf("\n%.9f%s", estimatedEpsilon_4hour,  strToOEMEasy("           4 часа"));
	printf("\n%.9f%s", estimatedEpsilon_8hour,  strToOEMEasy("           8 часов"));
	printf("\n%.9f%s", estimatedEpsilon_15hour, strToOEMEasy("           15 часов"));
	printf("\n%.9f%s", estimatedEpsilon_1day,   strToOEMEasy("           1 день"));
	
	//system("pause");
	
	setConsoleDefaultColor();
	//----
	double epsilon;
	//printf("\nEnter the number of computing (recommended 10000, ~ 2..3 seconds)\n\n");
	printf("\n\n%s\n", strToOEMEasy("Введите точность расчета, затем нажмите клавишу Enter.\n"));
	//setcolor(Grey);
	//printf("%s\n\n", strToOEMEasy("(рекомендуется ввести 100000 итераций, время расчета составит несколько секунд)"));
	setConsoleInputColor();
	scanf("%lf", &epsilon);
	//printf("epsilon = %f\n", epsilon);
	
	setConsoleDefaultColor();
	
	//expressionResult result = computingExpression(file_contents, epsilon, path2, false);
	int max_threads = omp_get_max_threads();
	#pragma omp parallel for reduction(+:CMA, CMA_square)
	for (long long j = 0; j < max_threads; j++) {
		//.......
	}
	expressionResult result = computingExpression(file_contents, epsilon, withoutCommas, false);
	
	//system("dir | clip");
	
	//printf("\nPress ESC to exit. Press 'n' to enter nominal size if you know it.");
	printf("\n%s", strToOEMEasy("Нажмите клавишу ESC, чтобы закрыть программу."));
	printf("\n%s", strToOEMEasy("Нажмите клавишу 'a', чтобы открыть описание программы."));
	if (!result.isError) {
		printf("\n%s", strToOEMEasy("Нажмите клавишу 's' чтобы пересчитать допуски относительного другого размера."));
	}
	printf("\n");
	char userChar;
	while ((userChar = getch()) != '\e') {
		if (userChar == 's' && !result.isError) {
			double nominal;
			//printf("\n\nEnter the nominal size\n");
			printf("\n%s", strToOEMEasy("Введите новое значение величины, относительно которой нужно пересчитать"));
			printf("\n%s\n\n", strToOEMEasy("поле допуска (используйте точку для отделения десятичной части числа):"));
			setConsoleInputColor();
			scanf("%lf", &nominal);
			//printf("\Nominal: %f\n", nominal);
			double correction = result.Mx - nominal;
			//printf("\ncorrection = %f\n", correction);
			int digitsForRound = digitsForRoundFromEpsilon(result.epsilon);
			double upDeviation = fround(3 * result.Sigma + correction, digitsForRound);
			double downDeviation = fround(-3 * result.Sigma + correction, digitsForRound);
			double upDeviationEps = fround(3 * result.Sigma + correction + result.epsilon, digitsForRound);
			double downDeviationEps = fround(-3 * result.Sigma + correction - result.epsilon, digitsForRound);
			double upDeviationEpsCent =  fround(100 * upDeviationEps / nominal, digitsForRound);
			double downDeviationEpsCent =  fround(100 * downDeviationEps / nominal, digitsForRound);
			setConsoleDefaultColor();
			printf("\n-------------------------------------------------------------------------------");
			//printf("\n=> Result value with nominal size: %f (%f, %f)\n", nominal, upDeviation, downDeviation);
			setcolor(Yellow );
//			char *plusUp = "+";
//			char *plusDown = "+";
//			char *plusUpEps = "+";
//			char *plusDownEps = "+";
//			if (upDeviation < 0) {
//				plusUp = "";
//			}
//			if (downDeviation < 0) {
//				plusDown = "";
//			}
//			if (upDeviationEps < 0) {
//				plusUpEps = "";
//			}
//			if (downDeviationEps < 0) {
//				plusDownEps = "";
//			}
			printf("\n=> %s %.*f (%+.*f, %+.*f)\n",   strToOEMEasy("Результат пересчета:             "), digitsForRound, nominal, digitsForRound, upDeviation, digitsForRound, downDeviation );
			printf("=> %s %.*f (%+.*f, %+.*f)\n",     strToOEMEasy("C учетом epsilon:                "), digitsForRound, nominal, digitsForRound, upDeviationEps, digitsForRound, downDeviationEps );
			if (upDeviationEpsCent != 0 || downDeviationEpsCent != 0) {
				printf("=> %s %.*f (%+.*f%%, %+.*f%%)\n", strToOEMEasy("C учетом epsilon и допусками в %:"), digitsForRound, nominal, digitsForRound, upDeviationEpsCent, digitsForRound, downDeviationEpsCent );
			}
			setConsoleDefaultColor();
			printf("-------------------------------------------------------------------------------\n");
		}
		else if (userChar == 'a') {
			printAboutProgram();
		}
	}
	return 0;
}
