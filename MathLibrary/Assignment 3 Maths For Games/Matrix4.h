#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float m1, float  m2, float m3, float m4, float m5, float  m6, float m7, float m8, float m9, float m10, float  m11, float m12, float m13, float m14, float  m15, float m16);
	~Matrix4();

	float& operator () (int index1, int index2);
	Vector4  operator * (Vector4& RHS);
	Matrix4 operator* (Matrix4& RHS);
	operator float*();
	void setRotateX(float degree);
	void setRotateY(float degree);
	void setRotateZ(float degree);

	float Matrix[4][4];
};
