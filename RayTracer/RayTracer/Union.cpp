#include "stdafx.h"
#include "Union.h"

Union::Union()
{
}


Union::~Union()
{
}


IntersectResult Union::Intersect(Ray3 ray)
{
	double minDistance = DBL_MAX;
	IntersectResult minResult = IntersectResult::NoHit();
	for each (Geometry* g in this->geometries)
	{
		IntersectResult result = g->Intersect(ray);
		if (result.geometry != nullptr && result.distance < minDistance)
		{
			minDistance = result.distance;
			minResult = result;
		}
	}
	return minResult;
}


void Union::AddGeometry(Geometry* newGeometry)
{
	this->geometries.push_back(newGeometry);
}
