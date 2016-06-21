#include "Vector4.h"
#include <math.h>

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;

}

Vector4::Vector4(float Vx, float Vy, float Vz, float Vw)
{
	x = Vx;
	y = Vy;
	z = Vz;
	w = Vw;
}

Vector4::~Vector4()
{

}

Vector4 Vector4::operator+(Vector4 & RHS)
{
	return Vector4(x + RHS.x, y + RHS.y, z + RHS.z, w + RHS.w);
}

Vector4 Vector4::operator-(Vector4 & RHS)
{
	return Vector4(x - RHS.x, y - RHS.y, z - RHS.z, w - RHS.w);
}

Vector4 Vector4::operator*(float RHS)
{
	return Vector4(x * RHS, y * RHS, z * RHS, w);
}

Vector4 operator*(float LHS, Vector4 & RHS)
{
	return Vector4(LHS * RHS.x, LHS * RHS.y, LHS * RHS.z, RHS.w);
}

float * Vector4::operator[](int index)
{
	if (index == 0) { return &x; }
	else if (index == 1) { return &y; }
	else if (index == 2) { return &z; }
	else if (index == 3) { return &w; }
	else { return nullptr; }
}

Vector4::operator float*()
{
	return (float*)this;
}

float Vector4::dot(Vector4 RHS)
{
	return float((x * RHS.x) + (y * RHS.y) + (z * RHS.z) + w);
}
Vector4 Vector4::cross(Vector4 & RHS)
{
	return Vector4(y * RHS.z - z * RHS.y, z * RHS.x - x * RHS.z, x * RHS.y - y * RHS.x, w);
}

float Vector4::magnitude(Vector4 RHS)
{
	float a = pow(RHS.x - x, 2);
	float b = pow(RHS.y - y, 2);
	float c = pow(RHS.z - z, 2);
	return float(sqrtf(a + b + c));
}

void Vector4::normalise()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	float c = pow(z, 2);
	float length = sqrtf(a + b + c);
	x /= length;
	y /= length;
	z /= length;
	w;
}

float Vector4::magnitude()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	float c = pow(z, 2);
	return(sqrtf(a + b + c));
}
