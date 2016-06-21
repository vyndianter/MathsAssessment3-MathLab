#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float Vx, float Vy)
{
	x = Vx;
	y = Vy;
}

Vector2::~Vector2()
{

}

Vector2 Vector2::operator+(Vector2 & RHS)
{
	return Vector2(x + RHS.x, y + RHS.y);
}

Vector2 Vector2::operator-(Vector2 & RHS)
{
	return Vector2(x - RHS.x, y - RHS.y);
}

Vector2 Vector2::operator*(float RHS)
{
	return Vector2(x * RHS, y * RHS);
}

float* Vector2::operator[](int index)
{
	if (index == 0) { return &x; }
	else if (index == 1) { return &y; }
	else { return nullptr; }
}

Vector2 operator*(float LHS, Vector2 & RHS)
{
	return Vector2(LHS * RHS.x, LHS * RHS.y);
}


Vector2::operator float*()
{
	return (float*)this;
}

float Vector2::dot(Vector2& RHS)
{
	return float((x * RHS.x) + (y * RHS.y));
}

float Vector2::magnitude(Vector2& RHS)
{
	float a = pow(RHS.x - x, 2);
	float b = pow(RHS.y - y, 2);
	return float(sqrtf(a + b));
}

void Vector2::normalise()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	float length = sqrtf(a + b);
	x /= length;
	y /= length;
}

float Vector2::magnitude()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	return(sqrtf(a + b));
}


