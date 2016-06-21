#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float m1, float  m2, float m3, float m4, float m5, float  m6, float m7, float m8, float m9);
	~Matrix3();

	float& operator () (int index1, int index2);
	Vector3  operator * (Vector3& RHS);
	Matrix3 operator* (Matrix3& RHS);
	operator float*();
	void setRotateX(float degree);
	void setRotateY(float degree);
	void setRotateZ(float degree);

	float Matrix[3][3];
};

