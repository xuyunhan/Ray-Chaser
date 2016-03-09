#include "stdafx.h"
#include "CheckerMaterial.h"
#include "Color.h"
#include "Vector3.h"
#include "Ray3.h"

CheckerMaterial::CheckerMaterial()
{
	scale = 0;
	reflectiveness = 0;
}

CheckerMaterial::CheckerMaterial(double pScale, double pReflectiveness)
{
	scale = pScale;
	reflectiveness = pReflectiveness;
}

CheckerMaterial::~CheckerMaterial()
{
}

// 返回地面某点的取样值
Color CheckerMaterial::Sample(Ray3 ray, Vector3 position, Vector3 normal)
{
	return  abs( fmod(floor(position.x * 0.1) + floor(position.z * this->scale), 2.0) ) < 1 ? Color::Black() : Color::White();
}
