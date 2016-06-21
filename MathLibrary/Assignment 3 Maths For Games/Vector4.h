#pragma

class Vector4
{
public:

	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator + (Vector4& RHS);
	Vector4 operator - (Vector4& RHS);
	Vector4 operator * (float RHS);
	float* operator [] (int index);
	friend Vector4 operator * (float LHS, Vector4& RHS);
	operator float*();
	float dot(Vector4 RHS);
	Vector4 cross(Vector4& RHS);
	float magnitude(Vector4 RHS);
	void normalise();
	float magnitude();

	float x;
	float y;
	float z;
	float w;
};