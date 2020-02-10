#pragma once

//--------------------------------------
// ������
//--------------------------------------

//����� ���������� ������
double volumeOfTruncatedCone_radius(double r, double R, double H);
double volumeOfTruncatedCone_diameter(double d, double D, double H);

//����� ��������� ���������� �������
//(�������� ������� ���� ��������� �������)
double volumeOfTruncatedConicalShell_radius(double r1, double R1, double r2, double R2, double H);
double volumeOfTruncatedConicalShell_diameter(double d1, double D1, double d2, double D2, double H);

//����� ������
double volumeOfCone_radius(double R, double H);
double volumeOfCone_diameter(double D, double H);

//����� ��������
double volumeOfCylinder_radius(double R, double H);
double volumeOfCylinder_diameter(double D, double H);

//����� �������������� ��������
double volumeOfCylindricalShell_radius(double r, double R, double H);
double volumeOfCylindricalShell_diameter(double d, double D, double H);

//����� �����
double volumeOfSphere_radius(double R);
double volumeOfSphere_diameter(double D);

//����� ����������� ��������
double volumeOfSphericalShell_radius(double r, double R);
double volumeOfSphericalShell_diameter(double d, double D);

//����� ����� ��������
double volumeOfWedgeRotation_radius(double r, double R, double H);
double volumeOfWedgeRotation_diameter(double d, double D, double H);

//����� �������� ��������
double volumeOfSphericalSegment_radius(double R, double H);
double volumeOfSphericalSegment_diameter(double D, double H);

//����� �������� ����
double volumeOfSphericalLayer_radius(double R, double h, double H);
double volumeOfSphericalLayer_diameter(double D, double h, double H);

//����� �������� �������
double volumeOfSphericalSector_radius(double R, double H);
double volumeOfSphericalSector_diameter(double D, double H);

//����� ����������� ���� ��������� (��������, ��������� � ����)
double volumeOfIntersectionCylinders_radius(double r, double R);
double volumeOfIntersectionCylinders_diameter(double d, double D);

//����� ����

//����� ������������� ���� �������� �������� ������� S � ����������� �� ������ ���� ������� �� ��� �������� R

//����� ����

//����� ���������������

//����� ���� ����������� �������� ����������� ������� S � ������ ����������� L

//����� ��������



//--------------------------------------
// �������
//--------------------------------------

//������� �����
void squareOfCircle_radius(double R);
void squareOfCircle_diameter(double D);

//������� ��������������

//������� ��������

//������� �������������� ������������

//������� ������������� ������������

//������� �����

//������� ��������



//--------------------------------------
// �����
//--------------------------------------

//����� ��������� ����������, ��������� ��� ����� 90 �������� � ���������� �������� ����� r � ����. k ���������� �����
double lengthOfReamer90(double a, double b, double r, double s, double k);



//--------------------------------------
// ���������� �������� n ���
//--------------------------------------
double manySum(double var, int count);
double manyMult(double var, int count);
