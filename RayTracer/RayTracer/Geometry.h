#pragma once
#include "IntersectResult.h"
#include "Ray3.h"
#include "Material.h"
class IntersectResult;
class Geometry
{
public:
	Geometry();
	~Geometry();
	virtual IntersectResult Intersect(Ray3 ray);

	Material* material;
};

