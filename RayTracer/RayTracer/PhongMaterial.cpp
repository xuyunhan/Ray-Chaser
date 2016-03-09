#include "stdafx.h"
#include "PhongMaterial.h"
#include "Color.h"
#include "Vector3.h"
#include "Ray3.h"

PhongMaterial::PhongMaterial()
{
	this->diffuse = Color::Black();
	this->specular = Color::Black();
	this->shininess = 0;
	this->reflectiveness = 0;
}

PhongMaterial::PhongMaterial(Color diffuse, Color specular, double shininess, double reflectiveness)
{
	this->diffuse = diffuse.Copy();
	this->specular = specular.Copy();
	this->shininess = shininess;
	this->reflectiveness = reflectiveness;
}

PhongMaterial::~PhongMaterial()
{
}


//��ʱ�ƹ�
Vector3	lightDirection = Vector3(1, 1, 1).Normalize();
Color lightColor = Color::White();

// �򵥵�Phong���ʣ���Ϊδ�й�Դϵͳ��ֻ��ȫ���������һ����ʱ�Ĺ�Դ���򣬲�ֻ��������(diffuse)�;���(specular)��
Color PhongMaterial::Sample(Ray3 ray, Vector3 position, Vector3 normal)
{
	double NdotL = normal.Dot(lightDirection);
	Vector3 H = (lightDirection.Subtract(ray.direction)).Normalize();
	double NdotH = normal.Dot(H);
	Color diffuseTerm = this->diffuse.Multiply(max(NdotL, 0));
	Color specularTerm = this->specular.Multiply(pow(max(NdotH, 0), this->shininess));
	return lightColor.Modulate(diffuseTerm.Add(specularTerm));
}
