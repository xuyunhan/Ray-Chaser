#include "stdafx.h"
#include "Plane.h"
#include "IntersectResult.h"

Plane::Plane()
{
	normal = Vector3::Zero();
	distance = 0;
}


Plane::Plane(Vector3 n, double d)
{
	normal = n.Copy();
	distance = d;
}

Plane::~Plane()
{
}


// Ïà½»
IntersectResult Plane::Intersect(Ray3 ray)
{
	double a = ray.direction.Dot(normal);
	if (a >= 0)
	{
		return IntersectResult::NoHit();
	}
	double b = normal.Dot(ray.origin.Subtract(this->position));
	IntersectResult result;
	result.geometry = this;
	result.distance = -b / a;
	result.position = ray.GetPoint(result.distance);
	result.normal = this->normal;
	return result;
}
