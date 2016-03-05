#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
	: radius(0)
{
	radius = 0; center = Vector3(0, 0, 0); sqrRadius = radius*radius;
}

Sphere::Sphere(Vector3 pv, double pr)
{
	this->center = pv; this->radius = pr;
	sqrRadius = radius*radius;
}

Sphere::~Sphere()
{
}


Sphere Sphere::Copy()
{
	return Sphere(this->center, this->radius);
}


// 求ray和球体的交点
IntersectResult Sphere::Intersect(Ray3 ray)
{
	Vector3 v = ray.origin.Subtract(this->center);
	double a0 = v.SqrLength() - this->sqrRadius;
	double DdotV = ray.direction.Dot(v);

	if (DdotV<=0	)
	{
		double discr = DdotV*DdotV - a0;
		if (discr>=0)
		{
			IntersectResult result;
			result.geometry = this;
			result.distance = -DdotV - sqrt(discr);
			result.position = ray.GetPoint(result.distance);
			result.normal = result.position.Subtract(this->center).Normalize();
			return result;
		}
	}
	return IntersectResult::NoHit();
}
