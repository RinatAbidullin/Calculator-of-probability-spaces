#include "holdvar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

extern bool isNewIteration[1000];

void newIteration() {
	for (int i = 0; i < 1000; i++) {
		isNewIteration[i] = true;
	}
}

double link1 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[1]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[1] = false;
		result = number;
	}
	return result;
}

double link2 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[2]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[2] = false;
		result = number;
	}
	return result;
}

double link3 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[3]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[3] = false;
		result = number;
	}
	return result;
}

double link4 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[4]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[4] = false;
		result = number;
	}
	return result;
}

double link5 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[5]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[5] = false;
		result = number;
	}
	return result;
}

double link6 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[6]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[6] = false;
		result = number;
	}
	return result;
}

double link7 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[7]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[7] = false;
		result = number;
	}
	return result;
}

double link8 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[8]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[8] = false;
		result = number;
	}
	return result;
}

double link9 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[9]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[9] = false;
		result = number;
	}
	return result;
}

double link10 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[10]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[10] = false;
		result = number;
	}
	return result;
}

double link11 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[11]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[11] = false;
		result = number;
	}
	return result;
}

double link12 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[12]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[12] = false;
		result = number;
	}
	return result;
}

double link13 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[13]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[13] = false;
		result = number;
	}
	return result;
}

double link14 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[14]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[14] = false;
		result = number;
	}
	return result;
}

double link15 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[15]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[15] = false;
		result = number;
	}
	return result;
}

double link16 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[16]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[16] = false;
		result = number;
	}
	return result;
}

double link17 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[17]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[17] = false;
		result = number;
	}
	return result;
}

double link18 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[18]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[18] = false;
		result = number;
	}
	return result;
}

double link19 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[19]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[19] = false;
		result = number;
	}
	return result;
}

double link20 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[20]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[20] = false;
		result = number;
	}
	return result;
}

double link21 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[21]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[21] = false;
		result = number;
	}
	return result;
}

double link22 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[22]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[22] = false;
		result = number;
	}
	return result;
}

double link23 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[23]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[23] = false;
		result = number;
	}
	return result;
}

double link24 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[24]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[24] = false;
		result = number;
	}
	return result;
}

double link25 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[25]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[25] = false;
		result = number;
	}
	return result;
}

double link26 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[26]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[26] = false;
		result = number;
	}
	return result;
}

double link27 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[27]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[27] = false;
		result = number;
	}
	return result;
}

double link28 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[28]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[28] = false;
		result = number;
	}
	return result;
}

double link29 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[29]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[29] = false;
		result = number;
	}
	return result;
}

double link30 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[30]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[30] = false;
		result = number;
	}
	return result;
}

double link31 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[31]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[31] = false;
		result = number;
	}
	return result;
}

double link32 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[32]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[32] = false;
		result = number;
	}
	return result;
}

double link33 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[33]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[33] = false;
		result = number;
	}
	return result;
}

double link34 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[34]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[34] = false;
		result = number;
	}
	return result;
}

double link35 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[35]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[35] = false;
		result = number;
	}
	return result;
}

double link36 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[36]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[36] = false;
		result = number;
	}
	return result;
}

double link37 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[37]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[37] = false;
		result = number;
	}
	return result;
}

double link38 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[38]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[38] = false;
		result = number;
	}
	return result;
}

double link39 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[39]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[39] = false;
		result = number;
	}
	return result;
}

double link40 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[40]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[40] = false;
		result = number;
	}
	return result;
}

double link41 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[41]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[41] = false;
		result = number;
	}
	return result;
}

double link42 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[42]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[42] = false;
		result = number;
	}
	return result;
}

double link43 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[43]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[43] = false;
		result = number;
	}
	return result;
}

double link44 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[44]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[44] = false;
		result = number;
	}
	return result;
}

double link45 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[45]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[45] = false;
		result = number;
	}
	return result;
}

double link46 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[46]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[46] = false;
		result = number;
	}
	return result;
}

double link47 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[47]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[47] = false;
		result = number;
	}
	return result;
}

double link48 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[48]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[48] = false;
		result = number;
	}
	return result;
}

double link49 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[49]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[49] = false;
		result = number;
	}
	return result;
}

double link50 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[50]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[50] = false;
		result = number;
	}
	return result;
}

double link51 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[51]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[51] = false;
		result = number;
	}
	return result;
}

double link52 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[52]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[52] = false;
		result = number;
	}
	return result;
}

double link53 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[53]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[53] = false;
		result = number;
	}
	return result;
}

double link54 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[54]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[54] = false;
		result = number;
	}
	return result;
}

double link55 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[55]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[55] = false;
		result = number;
	}
	return result;
}

double link56 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[56]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[56] = false;
		result = number;
	}
	return result;
}

double link57 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[57]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[57] = false;
		result = number;
	}
	return result;
}

double link58 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[58]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[58] = false;
		result = number;
	}
	return result;
}

double link59 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[59]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[59] = false;
		result = number;
	}
	return result;
}

double link60 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[60]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[60] = false;
		result = number;
	}
	return result;
}

double link61 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[61]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[61] = false;
		result = number;
	}
	return result;
}

double link62 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[62]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[62] = false;
		result = number;
	}
	return result;
}

double link63 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[63]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[63] = false;
		result = number;
	}
	return result;
}

double link64 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[64]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[64] = false;
		result = number;
	}
	return result;
}

double link65 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[65]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[65] = false;
		result = number;
	}
	return result;
}

double link66 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[66]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[66] = false;
		result = number;
	}
	return result;
}

double link67 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[67]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[67] = false;
		result = number;
	}
	return result;
}

double link68 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[68]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[68] = false;
		result = number;
	}
	return result;
}

double link69 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[69]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[69] = false;
		result = number;
	}
	return result;
}

double link70 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[70]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[70] = false;
		result = number;
	}
	return result;
}

double link71 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[71]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[71] = false;
		result = number;
	}
	return result;
}

double link72 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[72]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[72] = false;
		result = number;
	}
	return result;
}

double link73 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[73]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[73] = false;
		result = number;
	}
	return result;
}

double link74 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[74]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[74] = false;
		result = number;
	}
	return result;
}

double link75 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[75]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[75] = false;
		result = number;
	}
	return result;
}

double link76 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[76]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[76] = false;
		result = number;
	}
	return result;
}

double link77 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[77]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[77] = false;
		result = number;
	}
	return result;
}

double link78 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[78]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[78] = false;
		result = number;
	}
	return result;
}

double link79 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[79]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[79] = false;
		result = number;
	}
	return result;
}

double link80 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[80]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[80] = false;
		result = number;
	}
	return result;
}

double link81 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[81]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[81] = false;
		result = number;
	}
	return result;
}

double link82 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[82]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[82] = false;
		result = number;
	}
	return result;
}

double link83 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[83]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[83] = false;
		result = number;
	}
	return result;
}

double link84 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[84]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[84] = false;
		result = number;
	}
	return result;
}

double link85 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[85]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[85] = false;
		result = number;
	}
	return result;
}

double link86 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[86]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[86] = false;
		result = number;
	}
	return result;
}

double link87 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[87]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[87] = false;
		result = number;
	}
	return result;
}

double link88 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[88]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[88] = false;
		result = number;
	}
	return result;
}

double link89 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[89]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[89] = false;
		result = number;
	}
	return result;
}

double link90 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[90]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[90] = false;
		result = number;
	}
	return result;
}

double link91 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[91]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[91] = false;
		result = number;
	}
	return result;
}

double link92 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[92]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[92] = false;
		result = number;
	}
	return result;
}

double link93 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[93]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[93] = false;
		result = number;
	}
	return result;
}

double link94 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[94]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[94] = false;
		result = number;
	}
	return result;
}

double link95 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[95]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[95] = false;
		result = number;
	}
	return result;
}

double link96 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[96]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[96] = false;
		result = number;
	}
	return result;
}

double link97 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[97]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[97] = false;
		result = number;
	}
	return result;
}

double link98 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[98]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[98] = false;
		result = number;
	}
	return result;
}

double link99 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[99]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[99] = false;
		result = number;
	}
	return result;
}

double link100 (double number) {
	static bool isUsed = false;
	static double result;
	if (!isUsed || isNewIteration[100]) {
		//Первый вызов функции
		isUsed = true;
		isNewIteration[100] = false;
		result = number;
	}
	return result;
}
