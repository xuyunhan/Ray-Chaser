#pragma once
// #include "Color.h"
// #include "Vector3.h"
// #include "Ray3.h"
#include "Material.h"

class CheckerMaterial : public Material
{
public:
	CheckerMaterial();
	CheckerMaterial(double pScale, double pReflectiveness);
	~CheckerMaterial();
	
	double scale; // scale������Ϊ1���굥λ�ж��ٸ����ӣ�����scale = 0.1��һ�����ӵĴ�СΪ10x10
	double reflectiveness;// ����ϵ��
	// ���ص���ĳ���ȡ��ֵ
	Color Sample(Ray3 ray, Vector3 position, Vector3 normal);
};

