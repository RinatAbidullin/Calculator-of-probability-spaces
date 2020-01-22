#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"
#include "gauss.h"
//#include <stdbool.h>

const double PI = 3.1415926535897932384626433832795;

double gauss(double Mx, double Sigma) {
	return Sigma * cos(randFromRange(0, 2 * PI)) * sqrt(-2 * log(randFromRange(0.000001, 0.99999))) + Mx;
}

//static double secondValue;
//static bool isExistSecondValue = false;

double boxMuller(double Mx, double Sigma) {
	double u, v, s, X, Y;
//	if (isExistSecondValue) {
//		isExistSecondValue = false;
//		return Mx + Sigma * secondValue;
//	}
	do {
		u = randFromRange(-1, 1);
		v = randFromRange(-1, 1);
		s = u*u + v*v;
	} while (s >= 1 || s == 0);
	X = u * sqrt(-2 * log(s) / s);
	Y = v * sqrt(-2 * log(s) / s);
//	secondValue = Y;
//	isExistSecondValue = true;
	return Mx + Sigma * X;
}

double randFromRange(double a, double b) {
	return (double)rand() * (b - a) / RAND_MAX + a;
}

double gaussFromRange(double a, double b) {
	double Mx = (a + b) / 2.0;
	double Sigma = (b - Mx) / 3.0;
	//return gauss(Mx, Sigma);
	return boxMuller(Mx, Sigma);
}

double gaussFromNominalAndPercentDeviations(double nominal, double downDeviationPercent, double upDeviationPercent) {
	return gaussFromRange(nominal*(1+downDeviationPercent/100.0), nominal*(1+upDeviationPercent/100.0));
}

double gaussFromNominalAndUpDownDeviations(double nominal, double downDeviation, double upDeviation) {
	return gaussFromRange(nominal + downDeviation, nominal + upDeviation);
}

double nominal_gaussFromNominalAnd2Deviations(double nominal, double dev1, double dev2) {
	return nominal;
}

double nominal_gaussFromMinMax(double min, double max) {
	return (min + max) / 2;
}

//Male - охватываемый (отверстия, Hole), Female - охватывающий (валы, Shaft)

/*
double gauss_OST_Diameter_Hole(double Diameter) {
	
}

double gauss_OST_Diameter_Shaft(double diameter) {
	
}

double gauss_OST_Other_Hole(double Diameter) {
	
}

double gauss_OST_Other_Shaft(double diameter) {
	
}
*/

//Размеры элементов, не относящихся к отверстиям и валам
double gauss_OST_NotHoleAndShaft(double size) {
	if (size < 0.1) {
		return gaussFromRange(size, size);
	}
	else if (size >= 0.1 && size <= 0.3) {
		return gaussFromRange(size-0.05, size+0.05);
	}
	else if (size > 0.3 && size <= 0.5) {
		return gaussFromRange(size-0.07, size+0.07);
	}
	else if (size > 0.5 && size <= 3) {
		return gaussFromRange(size-0.15, size+0.15);
	}
	else if (size > 3 && size <= 30) {
		return gaussFromRange(size-0.2, size+0.2);
	}
	else if (size > 30 && size <= 120) {
		return gaussFromRange(size-0.3, size+0.3);
	}
	else if (size > 120 && size <= 315) {
		return gaussFromRange(size-0.5, size+0.5);
	}
	else if (size > 315 && size <= 1000) {
		return gaussFromRange(size-0.8, size+0.8);
	}
	else if (size > 1000 && size <= 2000) {
		return gaussFromRange(size-1.2, size+1.2);
	}
	else if (size > 2000 && size <= 3150) {
		return gaussFromRange(size-2.0, size+2.0);
	}
	else if (size > 3150 && size <= 5000) {
		return gaussFromRange(size-3.0, size+3.0);
	}
	else if (size > 5000 && size <= 8000) {
		return gaussFromRange(size-5.0, size+5.0);
	}
	else if (size > 8000 && size <= 10000) {
		return gaussFromRange(size-8.0, size+8.0);
	}
	else {
		return gaussFromRange(size-8, size+8);
	}
}


//ОСТ Фаски и радиусы закруглений
double gauss_OST_BevelAndRoundedRadius(double size) {
	if (size < 0.1) {
		return gaussFromRange(size, size);
	}
	else if (size == 0.1) {
		return gaussFromRange(size-0.07, size+0.07);
	}
	else if (size > 0.1 && size < 0.3) {
		return gaussFromRange(size-0.1, size+0.1);
	}
	else if (size >= 0.3 && size <= 0.5) {
		return gaussFromRange(size-0.2, size+0.2);
	}
	else if (size >= 0.5 && size <= 3) {
		return gaussFromRange(size-0.3, size+0.3);
	}
	else if (size >= 3 && size <= 6) {
		return gaussFromRange(size-0.5, size+0.5);
	}
	else if (size >= 6 && size <= 30) {
		return gaussFromRange(size-1, size+1);
	}
	else if (size >= 30 && size <= 120) {
		return gaussFromRange(size-2, size+2);
	}
	else if (size >= 120 && size <= 1000) {
		return gaussFromRange(size-4, size+4);
	}
	else {
		return gaussFromRange(size-4, size+4);
	}
}

