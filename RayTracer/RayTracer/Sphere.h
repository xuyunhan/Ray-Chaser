#pragma once
#include "Vector3.h"
// #include "IntersectResult.h"
#include "Ray3.h"
#include "Geometry.h"

class IntersectResult;
// class Geometry;
class Sphere : public Geometry
{
public:
	Sphere();
	Sphere::Sphere(Vector3 pv, double pr);

	~Sphere();
	// ��������
	Vector3 center;
	// ����뾶
	double radius;
	double sqrRadius;//�뾶ƽ��
	Sphere Copy();
	// ��ray������Ľ���
	IntersectResult Intersect(Ray3 ray);
// 	Material* material;

};

