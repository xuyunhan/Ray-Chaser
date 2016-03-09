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

	// 简单的Phong材质，因为未有光源系统，只用全域变量设置一个临时的光源方向，并只计算漫射(diffuse)和镜射(specular)。
	Color Sample(Ray3 ray, Vector3 position, Vector3 normal);
};


