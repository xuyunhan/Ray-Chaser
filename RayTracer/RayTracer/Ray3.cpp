#include "stdafx.h"
#include "Ray3.h"


Ray3::Ray3()
{
}

Ray3::Ray3(Vector3 po, Vector3 pd)
{
	this->origin = po.Copy();
	this->direction = pd.Copy();
}

Ray3::~Ray3()
{
}


// 假设d为单位向量，因此t为距离，返回从光发射点origin沿direction方向距离为t的点
Vector3 Ray3::GetPoint(double t)
{
	return this->origin.Add(this->direction.Multiply(t));
// 	return Vector3();
}
