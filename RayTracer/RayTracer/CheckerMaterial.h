#pragma once
// #include "Color.h"
// #include "Vector3.h"
// #include "Ray3.h"
#include "Material.h"

class CheckerMaterial : public Material
{
public:
	CheckerMaterial();
	CheckerMaterial(double pScale, double pReflectiveness);
	~CheckerMaterial();
	
	double scale; // scale的意义为1坐标单位有多少个格子，例如scale = 0.1即一个格子的大小为10x10
	double reflectiveness;// 反射系数
	// 返回地面某点的取样值
	Color Sample(Ray3 ray, Vector3 position, Vector3 normal);
};

