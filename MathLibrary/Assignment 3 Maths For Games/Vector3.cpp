#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float Vx, float Vy, float Vz)
{
	x = Vx;
	y = Vy;
	z = Vz;
}

Vector3::~Vector3()
{

}

Vector3 Vector3::operator+(Vector3 & RHS)
{
	return Vector3(x + RHS.x, y + RHS.y, z + RHS.z);
}

Vector3 Vector3::operator-(Vector3 & RHS)
{
	return Vector3(x - RHS.x, y - RHS.y, z - RHS.z);
}

Vector3 Vector3::operator*(float RHS)
{
	return Vector3(x * RHS, y * RHS, z * RHS);
}

Vector3 operator*(float LHS, Vector3 & RHS)
{
	return Vector3(LHS * RHS.x, LHS * RHS.y, LHS * RHS.z);
}

Vector3::operator float*()
{
	return (float*)this;
}

float Vector3::dot(Vector3 RHS)
{
	return float((x * RHS.x) + (y * RHS.y) + (z * RHS.z));
}

Vector3 Vector3::cross(Vector3 & RHS)
{
	return Vector3(y * RHS.z - z * RHS.y, z * RHS.x - x * RHS.z, x * RHS.y - y * RHS.x);
}

float Vector3::magnitude(Vector3 RHS)
{
	float a = pow(RHS.x - x, 2);
	float b = pow(RHS.y - y, 2);
	float c = pow(RHS.z - z, 2);
	return float(sqrtf(a + b + c));
}

 void Vector3::normalise()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	float c = pow(z, 2);
	float length = sqrtf(a + b + c);
	x /= length;
	y /= length;
	z /= length;
}

float Vector3::magnitude()
{
	float a = pow(x, 2);
	float b = pow(y, 2);
	float c = pow(z, 2);
	return(sqrtf(a + b + c));
}

float * Vector3::operator[](int index)
{
	if (index == 0) { return &x; }
	else if (index == 1) { return &y; }
	else if (index == 2) { return &z; }
	else { return nullptr; }
}
