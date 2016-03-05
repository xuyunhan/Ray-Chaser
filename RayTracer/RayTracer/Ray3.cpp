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


// ����dΪ��λ���������tΪ���룬���شӹⷢ���origin��direction�������Ϊt�ĵ�
Vector3 Ray3::GetPoint(double t)
{
	return this->origin.Add(this->direction.Multiply(t));
// 	return Vector3();
}
