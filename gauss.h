#pragma once

double gauss(double Mx, double Sigma);
double randFromRange(double a, double b);
double gaussFromRange(double a, double b);
double gaussFromNominalAndPercentDeviations(double nominal, double downDeviationPercent, double upDeviationPercent);
double gaussFromNominalAndUpDownDeviations(double nominal, double downDeviation, double upDeviation);

double nominal_gaussFromNominalAnd2Deviations(double nominal, double dev1, double dev2);
double nominal_gaussFromMinMax(double min, double max);

double gauss_OST_BevelAndRoundedRadius(double size);
double gauss_OST_NotHoleAndShaft(double size);
double gauss_OST_Diameter_Hole(double Diameter);
double gauss_OST_Diameter_Shaft(double diameter);
double gauss_OST_Other_Hole(double Diameter);
double gauss_OST_Other_Shaft(double diameter);
