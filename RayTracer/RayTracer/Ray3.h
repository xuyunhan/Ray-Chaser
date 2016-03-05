#pragma once
#include "Vector3.h"
class Ray3
{
public:
	Ray3();
	Ray3(Vector3 po, Vector3 pd);
	~Ray3();
	// 发射起点
	Vector3 origin;
	// 光线方向
	Vector3 direction;
	// 假设d为单位向量，因此t为距离，返回从光发射点origin沿direction方向距离为t的点
	Vector3 GetPoint(double t);
};

