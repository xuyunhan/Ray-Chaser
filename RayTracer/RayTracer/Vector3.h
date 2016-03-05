#pragma once
class Vector3
{
public:
	Vector3();
	Vector3::Vector3(double px, double py, double pz);
	~Vector3();

	double x, y, z;
	double Length();
	Vector3 Copy();
	double SqrLength();
	Vector3 Normalize();
	Vector3 Negate();
	Vector3 Add(Vector3 v);
	Vector3 Subtract(Vector3 v);
	Vector3 Multiply(double f);
	Vector3 Divide(double f);
	Vector3 Cross(Vector3 v);
	double Dot(Vector3 v);
	static Vector3 Zero();
};

