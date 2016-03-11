#pragma once
#include "Color.h"
#include "Vector3.h"
#include "Geometry.h"
#include "LightSample.h"
class Light
{
public:
	Light();
	~Light();
	bool shadow_on;
// 	LightSample = function(L, EL) { this.L = L; this.EL = EL; };
// 	LightSample.zero = new LightSample(Vector3.zero, Color.black);
	Vector3 L;//光源
	Color EL;// 放射光

	virtual LightSample Sample(Geometry& scene, Vector3& position);
};

