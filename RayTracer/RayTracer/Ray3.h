#pragma once
#include "Vector3.h"
class Ray3
{
public:
	Ray3();
	Ray3(Vector3 po, Vector3 pd);
	~Ray3();
	// �������
	Vector3 origin;
	// ���߷���
	Vector3 direction;
	// ����dΪ��λ���������tΪ���룬���شӹⷢ���origin��direction�������Ϊt�ĵ�
	Vector3 GetPoint(double t);
};

