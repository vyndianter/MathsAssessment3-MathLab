#pragma once

class Vector2
{
public:

	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator + (Vector2& RHS);
	Vector2 operator - (Vector2& RHS);
	Vector2 operator * (float RHS);
	float* operator [] (int index);
	friend Vector2 operator * (float LHS, Vector2& RHS);
	operator float*();
	float dot(Vector2& RHS);
	float magnitude(Vector2& RHS);
	void normalise();
	float magnitude();

	float x;
	float y;
};
