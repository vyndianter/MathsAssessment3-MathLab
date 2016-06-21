#include "Matrix4.h"
#include <Math.h>

Matrix4::Matrix4()
{
	Matrix[0][0] = 1;
	Matrix[0][1] = 0;
	Matrix[0][2] = 0;
	Matrix[0][3] = 0;
	Matrix[1][0] = 0;
	Matrix[1][1] = 1;
	Matrix[1][2] = 0;
	Matrix[1][3] = 0;
	Matrix[2][0] = 0; 
	Matrix[2][1] = 0;
	Matrix[2][2] = 1;
	Matrix[2][3] = 0;
	Matrix[3][0] = 0;
	Matrix[3][1] = 0;
	Matrix[3][2] = 0;
	Matrix[3][3] = 1;
}

Matrix4::Matrix4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float  m11, float m12, float m13, float m14, float  m15, float m16)
{
	Matrix[0][0] = m1;
	Matrix[0][1] = m2;
	Matrix[0][2] = m3;
	Matrix[0][3] = m4;
	Matrix[1][0] = m5;
	Matrix[1][1] = m6;
	Matrix[1][2] = m7;
	Matrix[1][3] = m8;
	Matrix[2][0] = m9;
	Matrix[2][1] = m10;
	Matrix[2][2] = m11;
	Matrix[2][3] = m12;
	Matrix[3][0] = m13;
	Matrix[3][1] = m14;
	Matrix[3][2] = m15;
	Matrix[3][3] = m16;
}

Matrix4::~Matrix4()
{
}

float & Matrix4::operator()(int index1, int index2)
{
	return Matrix[index1][index2];
}

Vector4 Matrix4::operator*(Vector4 & RHS)
{
	return Vector4(Vector4(Matrix[0][0], Matrix[1][0], Matrix[2][0], Matrix[3][0]).dot(RHS), Vector4(Matrix[0][1], Matrix[1][1], Matrix[2][1], Matrix[3][1]).dot(RHS), Vector4(Matrix[0][2], Matrix[1][2], Matrix[2][2], Matrix[3][2]).dot(RHS), RHS.w);
}

Matrix4 Matrix4::operator*(Matrix4 & RHS)
{
	Vector4 a = *this * Vector4(RHS(0, 0), RHS(0, 1), RHS(0, 2), RHS(0, 3));
	Vector4 b = *this * Vector4(RHS(1, 0), RHS(1, 1), RHS(1, 2), RHS(1, 3));
	Vector4 c = *this * Vector4(RHS(2, 0), RHS(2, 1), RHS(2, 2), RHS(1, 3));
	Vector4 d = *this * Vector4(RHS(3, 0), RHS(3, 1), RHS(3, 2), RHS(3, 3));
	return Matrix4(*a[0], *a[1], *a[2], *a[3], *b[0], *b[1], *b[2], *b[3], *c[0], *c[1], *c[2], *c[3], *d[0], *d[1], *d[2], *d[3]);
}

Matrix4::operator float*()
{
	return &Matrix[0][0];
}

void Matrix4::setRotateX(float degree)
{
	Matrix[1][1] = cos(degree);
	Matrix[1][2] = sin(degree);
	Matrix[2][1] = -sin(degree);
	Matrix[2][2] = cos(degree);
}

void Matrix4::setRotateY(float degree)
{
	Matrix[0][0] = cos(degree);
	Matrix[2][0] = sin(degree);
	Matrix[0][2] = -sin(degree);
	Matrix[2][2] = cos(degree);
}

void Matrix4::setRotateZ(float degree)
{
	Matrix[0][0] = cos(degree);
	Matrix[1][0] = -sin(degree);
	Matrix[0][1] = sin(degree);
	Matrix[1][1] = cos(degree);
}