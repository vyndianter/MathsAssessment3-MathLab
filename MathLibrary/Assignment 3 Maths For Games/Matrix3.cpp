#include "Matrix3.h"
#include <Math.h>

Matrix3::Matrix3()
{
	Matrix[0][0] = 1;
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;
	Matrix[1][0] = 0;
	Matrix[1][1] = 1;
	Matrix[1][2] = 0;
	Matrix[2][0] = 0;
	Matrix[2][1] = 0;
	Matrix[2][2] = 1;
}

Matrix3::Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	Matrix[0][0] = m1;
	Matrix[0][1] = m2;
	Matrix[0][2] = m3;
	Matrix[1][0] = m4;
	Matrix[1][1] = m5;
	Matrix[1][2] = m6;
	Matrix[2][0] = m7;
	Matrix[2][1] = m8;
	Matrix[2][2] = m9;
}

Matrix3::~Matrix3()
{
}

float & Matrix3::operator()(int index1, int index2)
{
	return Matrix[index1][index2];
}

Vector3 Matrix3::operator*(Vector3 & RHS)
{
	return Vector3(Vector3(Matrix[0][0], Matrix[1][0], Matrix[2][0]).dot(RHS), Vector3(Matrix[0][1], Matrix[1][1], Matrix[2][1]).dot(RHS), Vector3(Matrix[0][2], Matrix[1][2], Matrix[2][2]).dot(RHS));
}

Matrix3 Matrix3::operator*(Matrix3 & RHS)
{
	Vector3 a = *this * Vector3(RHS(0, 0), RHS(0, 1), RHS(0, 2));
	Vector3 b = *this * Vector3(RHS(1, 0), RHS(1, 1), RHS(1, 2));
	Vector3 c = *this * Vector3(RHS(2, 0), RHS(2, 1), RHS(2, 2));
	return Matrix3(*a[0], *a[1], *a[2], *b[0], *b[1], *b[2], *c[0], *c[1], *c[2]);
}

Matrix3::operator float*()
{
	return &Matrix[0][0];
}

void Matrix3::setRotateX(float degree)
{
	Matrix[1][1] = cos(degree);
	Matrix[1][2] = sin(degree);
	Matrix[2][1] = -sin(degree);
	Matrix[2][2] = cos(degree);
}

void Matrix3::setRotateY(float degree)
{
	Matrix[0][0] = cos(degree);
	Matrix[2][0] = sin(degree);
	Matrix[0][2] = -sin(degree);
	Matrix[2][2] = cos(degree);
}

void Matrix3::setRotateZ(float degree)
{
	Matrix[0][0] = cos(degree);
	Matrix[1][0] = -sin(degree);
	Matrix[0][1] = sin(degree);
	Matrix[1][1] = cos(degree);
}