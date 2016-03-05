#include "stdafx.h"
#include "Vector3.h"
#include <math.h> 

Vector3::Vector3()
{
	this->x = 0; this->y = 0; this->z = 0;
}

Vector3::Vector3(double px,double py,double pz)
{
	this->x = px; this->y = py; this->z = pz;
}

Vector3::~Vector3()
{
}

double Vector3::Length()
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3 Vector3::Copy()
{
	return Vector3(this->x, this->y, this->z);
}

double Vector3::SqrLength()
{
	return (this->x * this->x + this->y * this->y + this->z * this->z);
}


Vector3 Vector3::Normalize()
{
	double inv = 1.0 / this->Length(); return Vector3(this->x * inv, this->y * inv, this->z * inv);
}


Vector3 Vector3::Negate()
{
	return Vector3(-this->x, -this->y, -this->z);
}


Vector3 Vector3::Add(Vector3 v)
{
	return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
}


Vector3 Vector3::Subtract(Vector3 v)
{
	return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
}


Vector3 Vector3::Multiply(double f)
{
	return Vector3(this->x * f, this->y * f, this->z * f);
}

Vector3 Vector3::Divide(double f)
{
	double invf = 1.0 / f; return Vector3(this->x * invf, this->y * invf, this->z * invf);
}

Vector3 Vector3::Cross(Vector3 v)
{
	return Vector3(-this->z * v.y + this->y * v.z, this->z * v.x - this->x * v.z, -this->y * v.x + this->x * v.y);
}

double Vector3::Dot(Vector3 v)
{
	return (this->x * v.x + this->y * v.y + this->z * v.z);
}


Vector3 Vector3::Zero()
{
	return Vector3(0,0,0);
}
