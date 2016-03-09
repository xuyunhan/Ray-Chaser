#pragma once
#include "Vector3.h"
#include "Color.h"
#include "Ray3.h"
#include "Material.h"
class PhongMaterial : public Material
{
public:
	PhongMaterial();
	~PhongMaterial();
	double shininess, reflectiveness;
	Color  diffuse, specular;
	PhongMaterial(Color diffuse, Color specular, double shininess, double reflectiveness);

	// �򵥵�Phong���ʣ���Ϊδ�й�Դϵͳ��ֻ��ȫ���������һ����ʱ�Ĺ�Դ���򣬲�ֻ��������(diffuse)�;���(specular)��
	Color Sample(Ray3 ray, Vector3 position, Vector3 normal);
};


