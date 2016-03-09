#pragma once
// #include "Sphere.h"
#include "Vector3.h"
#include "Geometry.h"
class Geometry;

class IntersectResult//�����뼸�����ཻ�Ľ����
{
public:
	IntersectResult();
	~IntersectResult();
	// �ཻ������
	Geometry* geometry;
	// ������Դ������ԭ�㣩�ľ���
	double distance;
	// ����λ��
	Vector3 position;
	// ��һ���Ľ��㷨�������������ĵ������������
	Vector3 normal;
	// �޽���
	static IntersectResult NoHit();
};

