#pragma once
#include "Color.h"
#include "Ray3.h"
#include "Vector3.h"
class Material
{
public:
	Material();
	~Material();
	double reflectiveness;// ·´ÉäÏµÊý

	virtual Color Sample(Ray3 ray, Vector3 position, Vector3 normal) { return Color(); }
};

