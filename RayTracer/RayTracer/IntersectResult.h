#pragma once
// #include "Sphere.h"
#include "Vector3.h"
#include "Geometry.h"
class Geometry;

class IntersectResult//光线与几何体相交的结果。
{
public:
	IntersectResult();
	~IntersectResult();
	// 相交几何体
	Geometry* geometry;
	// 交点距光源（光线原点）的距离
	double distance;
	// 交点位置
	Vector3 position;
	// 归一化的交点法向量（球体球心到交点的向量）
	Vector3 normal;
	// 无交点
	static IntersectResult NoHit();
};

