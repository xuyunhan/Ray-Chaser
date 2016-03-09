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


//临时灯光
Vector3	lightDirection = Vector3(1, 1, 1).Normalize();
Color lightColor = Color::White();

// 简单的Phong材质，因为未有光源系统，只用全域变量设置一个临时的光源方向，并只计算漫射(diffuse)和镜射(specular)。
Color PhongMaterial::Sample(Ray3 ray, Vector3 position, Vector3 normal)
{
	double NdotL = normal.Dot(lightDirection);
	Vector3 H = (lightDirection.Subtract(ray.direction)).Normalize();
	double NdotH = normal.Dot(H);
	Color diffuseTerm = this->diffuse.Multiply(max(NdotL, 0));
	Color specularTerm = this->specular.Multiply(pow(max(NdotH, 0), this->shininess));
	return lightColor.Modulate(diffuseTerm.Add(specularTerm));
}
