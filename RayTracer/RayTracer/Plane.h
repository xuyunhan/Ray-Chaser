#pragma once
#include "Vector3.h"
#include "Geometry.h"
class Plane : public Geometry
{
public:
	Plane();
	Plane(Vector3 n, double d);
	~Plane();
	Vector3 normal, position;//平面法向量，平面位置
	double distance;//原点至平面最短距离
	// 相交
	IntersectResult Intersect(Ray3 ray);
// 	Material* material;

};

