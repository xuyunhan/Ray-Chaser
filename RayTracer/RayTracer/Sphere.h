#pragma once
#include "Vector3.h"
#include "IntersectResult.h"
#include "Ray3.h"

class IntersectResult;
class Sphere
{
public:
	Sphere();
	Sphere::Sphere(Vector3 pv, double pr);

	~Sphere();
	// 球体中心
	Vector3 center;
	// 球体半径
	double radius;
	double sqrRadius;//半径平方
	Sphere Copy();
	// 求ray和球体的交点
	IntersectResult Intersect(Ray3 ray);
};

