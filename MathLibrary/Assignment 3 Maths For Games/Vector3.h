#pragma once

class Vector3
{
public:

	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator + (Vector3& RHS);
	Vector3 operator - (Vector3& RHS);
	Vector3 operator * (float RHS);
	float* operator [] (int index);
	friend Vector3 operator * (float LHS, Vector3& RHS);
	operator float*();
	float dot(Vector3 RHS);
	Vector3 cross(Vector3& RHS);
	float magnitude(Vector3 RHS);
	void normalise();
	float magnitude();

	float x;
	float y;
	float z;
};

