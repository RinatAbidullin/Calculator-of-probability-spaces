#include "helpfunction.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const double h_PI = 3.1415926535897932384626433832795;

//Объем усеченного конуса
double volumeOfTruncatedCone_radius(double r, double R, double H) {
	double V = 1 / 3.0 * h_PI * H * (R*R + r*r + R*r);
	return fabs(V);
}

double volumeOfTruncatedCone_diameter(double d, double D, double H) {
	return volumeOfTruncatedCone_radius(d/2, D/2, H);
}

//Объем усеченной конической оболочи
//(разность объемов двух усеченных конусов)
double volumeOfTruncatedConicalShell_radius(double r1, double R1, double r2, double R2, double H) {
	double V2 = volumeOfTruncatedCone_radius(r2, R2, H);
	double V1 = volumeOfTruncatedCone_radius(r1, R1, H);
	double V = V2 - V1;
	return fabs(V);
}

double volumeOfTruncatedConicalShell_diameter(double d1, double D1, double d2, double D2, double H) {
	return volumeOfTruncatedConicalShell_radius(d1/2, D1/2, d2/2, D2/2, H);
}

//Объем конуса
double volumeOfCone_radius(double R, double H) {
	double V = 1 / 3.0 * h_PI * H * R*R;
	return V;
}

double volumeOfCone_diameter(double D, double H) {
	return volumeOfCone_radius(D/2, H);
}

//Объем цилиндра
double volumeOfCylinder_radius(double R, double H) {
	double V = h_PI * H * R*R;
	return V;
}

double volumeOfCylinder_diameter(double D, double H) {
	return volumeOfCylinder_radius(D/2, H);
}

//Объем цилиндрической оболочки
double volumeOfCylindricalShell_radius(double r, double R, double H) {
	double V2 = volumeOfCylinder_radius(R, H);
	double V1 = volumeOfCylinder_radius(r, H);
	double V = V2 - V1;
	return fabs(V);
}

double volumeOfCylindricalShell_diameter(double d, double D, double H) {
	return volumeOfCylindricalShell_radius(d/2, D/2, H);
}

//Объем сферы
double volumeOfSphere_radius(double R) {
	double V = 4.0 / 3.0 * h_PI * R*R*R;
	return V;
}

double volumeOfSphere_diameter(double D) {
	return volumeOfSphere_radius(D/2);
}

//Объем сферической оболочки
double volumeOfSphericalShell_radius(double r, double R) {
	double V2 = volumeOfSphere_radius(R);
	double V1 = volumeOfSphere_radius(r);
	double V = V2 - V1;
	return fabs(V);
}

double volumeOfSphericalShell_diameter(double d, double D) {
	return volumeOfSphericalShell_radius(d/2, D/2);
}

//Объем клина вращения
double volumeOfWedgeRotation_radius(double r, double R, double H) {
	return volumeOfCylindricalShell_radius(r, R, H) / 2;
}

double volumeOfWedgeRotation_diameter(double d, double D, double H) {
	return volumeOfWedgeRotation_radius(d/2, D/2, H);
}

//Объем шарового сегмента
double volumeOfSphericalSegment_radius(double R, double H) {
	double V = h_PI * H*H * (R - 1/3.0 * H);
	return V;
}

double volumeOfSphericalSegment_diameter(double D, double H) {
	return volumeOfSphericalSegment_radius(D/2, H);
}

//Объем шарового слоя
double volumeOfSphericalLayer_radius(double R, double h, double H) {
	double V2 = volumeOfSphericalSegment_radius(R, H);
	double V1 = volumeOfSphericalSegment_radius(R, h);
	double V = V2 - V1;
	return fabs(V);
}

double volumeOfSphericalLayer_diameter(double D, double h, double H) {
	return volumeOfSphericalLayer_radius(D/2, h, H);
}

//Объем шарового сектора
double volumeOfSphericalSector_radius(double R, double H) {
	double V = 2.0 * h_PI / 3.0 * R*R * H;
	return V;
}

double volumeOfSphericalSector_diameter(double D, double H) {
	return volumeOfSphericalSector_radius(D/2, H);
}

//Объем пересечения двух цилиндров (например, отверстие в вале)
double volumeOfIntersectionCylinders_radius(double r, double R) {
	double h = R - sqrt(R*R - r*r);
	double alfa = 0.76;
	double V = 2 * h_PI * r*r * (R + h * (alfa - 1));
	return V;
}

double volumeOfIntersectionCylinders_diameter(double d, double D) {
	return volumeOfIntersectionCylinders_radius(d/2, D/2);
}



//--------------------------------------
// Площади
//--------------------------------------

//Площадь круга
void squareOfCircle_radius(double R) {
	double S = h_PI * R*R;
	return S;
}

void squareOfCircle_diameter(double D) {
	return squareOfCircle_radius(D/2);
}



//--------------------------------------
// Длины
//--------------------------------------

//Длина развертки кронштейна толщиной s, согнутого под углом 90 градусов с внутренним радиусом гибки r и коэф. k нормальной линии
double lengthOfReamer90(double a, double b, double r, double s, double k) {
	double L = a + b - 2 * r - 2 * s + h_PI / 2 * (r + k * s);
	return L;
}
