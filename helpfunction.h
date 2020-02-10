#pragma once

//--------------------------------------
// Объемы
//--------------------------------------

//Объем усеченного конуса
double volumeOfTruncatedCone_radius(double r, double R, double H);
double volumeOfTruncatedCone_diameter(double d, double D, double H);

//Объем усеченной конической оболочи
//(разность объемов двух усеченных конусов)
double volumeOfTruncatedConicalShell_radius(double r1, double R1, double r2, double R2, double H);
double volumeOfTruncatedConicalShell_diameter(double d1, double D1, double d2, double D2, double H);

//Объем конуса
double volumeOfCone_radius(double R, double H);
double volumeOfCone_diameter(double D, double H);

//Объем цилиндра
double volumeOfCylinder_radius(double R, double H);
double volumeOfCylinder_diameter(double D, double H);

//Объем цилиндрической оболочки
double volumeOfCylindricalShell_radius(double r, double R, double H);
double volumeOfCylindricalShell_diameter(double d, double D, double H);

//Объем сферы
double volumeOfSphere_radius(double R);
double volumeOfSphere_diameter(double D);

//Объем сферической оболочки
double volumeOfSphericalShell_radius(double r, double R);
double volumeOfSphericalShell_diameter(double d, double D);

//Объем клина вращения
double volumeOfWedgeRotation_radius(double r, double R, double H);
double volumeOfWedgeRotation_diameter(double d, double D, double H);

//Объем шарового сегмента
double volumeOfSphericalSegment_radius(double R, double H);
double volumeOfSphericalSegment_diameter(double D, double H);

//Объем шарового слоя
double volumeOfSphericalLayer_radius(double R, double h, double H);
double volumeOfSphericalLayer_diameter(double D, double h, double H);

//Объем шарового сектора
double volumeOfSphericalSector_radius(double R, double H);
double volumeOfSphericalSector_diameter(double D, double H);

//Объем пересечения двух цилиндров (например, отверстие в вале)
double volumeOfIntersectionCylinders_radius(double r, double R);
double volumeOfIntersectionCylinders_diameter(double d, double D);

//Объем тора

//Объем произвольного тела вращения площадью сечения S и расстоянием от центра масс сечения до оси вращения R

//Объем куба

//Объем параллелепипеда

//Объем тела вытягивания площадью поперечного сечения S и длиной вытягивания L

//Объем пирамиды



//--------------------------------------
// Площади
//--------------------------------------

//Площадь круга
void squareOfCircle_radius(double R);
void squareOfCircle_diameter(double D);

//Площадь прямоугольника

//Площадь квадрата

//Площадь прямоугольного треугольника

//Площадь произвольного треугольника

//Площадь ромба

//Площадь трапеции



//--------------------------------------
// Длины
//--------------------------------------

//Длина развертки кронштейна, согнутого под углом 90 градусов с внутренним радиусом гибки r и коэф. k нормальной линии
double lengthOfReamer90(double a, double b, double r, double s, double k);



//--------------------------------------
// Повторение операций n раз
//--------------------------------------
double manySum(double var, int count);
double manyMult(double var, int count);
