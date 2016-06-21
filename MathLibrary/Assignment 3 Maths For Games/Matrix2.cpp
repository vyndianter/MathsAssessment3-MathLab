#include "Matrix2.h"
#include <Math.h>

Matrix2::Matrix2()
{
	Matrix[0][0] = 1;
	Matrix[0][1] = 0; 
	Matrix[1][0] = 0;
	Matrix[1][1] = 1;
}

Matrix2::Matrix2(float m1, float m2, float m3, float m4)
{
	Matrix[0][0] = m1;
	Matrix[0][1] = m2;
	Matrix[1][0] = m3;
	Matrix[1][1] = m4;
}

Matrix2::~Matrix2()
{
}

float & Matrix2::operator()(int index1, int index2)
{
	return Matrix[index1][index2];
}

Vector2 Matrix2::operator*(Vector2 & RHS)
{
	return Vector2(Vector2(Matrix[0][0], Matrix[1][0]).dot(RHS), Vector2(Matrix[0][1], Matrix[1][1]).dot(RHS));
}

Matrix2 Matrix2::operator*(Matrix2 & RHS)
{
	Vector2 a = *this * Vector2(RHS(0, 0), RHS(0, 1));
	Vector2 b = *this * Vector2(RHS(1, 0), RHS(1, 1));
	return Matrix2(*a[0], *a[1], *b[0], *b[1]);
}

Matrix2::operator float*()
{
	return &Matrix[0][0];
}

void Matrix2::setRotateZ(float degree)
{
	Matrix[0][0] = cos(degree);
	Matrix[1][0] = -sin(degree);
	Matrix[0][1] = sin(degree);
	Matrix[1][1] = cos(degree);
}



