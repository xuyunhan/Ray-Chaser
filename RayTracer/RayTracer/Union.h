#pragma once
#include "Geometry.h"
#include <vector>

class Union :
	public Geometry
{
public:
	Union();
	~Union();
	IntersectResult Intersect(Ray3 ray);
	std::vector<Geometry*> geometries;
	void AddGeometry(Geometry* newGeometry);
};

