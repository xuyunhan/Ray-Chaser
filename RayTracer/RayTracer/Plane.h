#pragma once
#include "Vector3.h"
#include "Geometry.h"
class Plane : public Geometry
{
public:
	Plane();
	Plane(Vector3 n, double d);
	~Plane();
	Vector3 normal, position;//ƽ�淨������ƽ��λ��
	double distance;//ԭ����ƽ����̾���
	// �ཻ
	IntersectResult Intersect(Ray3 ray);
// 	Material* material;

};

