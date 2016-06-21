#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float m1, float  m2, float m3, float m4);
	~Matrix2();

	float& operator () (int index1, int index2);
	Vector2  operator * (Vector2& RHS);
	Matrix2 operator * (Matrix2& RHS);
	operator float*();
	void setRotateZ(float degree);

	float Matrix[2][2];
};

