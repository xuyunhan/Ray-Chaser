#pragma once
#include "Light.h"
class DirectionLight :
	public Light
{
private:
	DirectionLight();
public:
	~DirectionLight();
	DirectionLight::DirectionLight(Color irradiance, Vector3 direction);
	Color irradiance;
	Vector3 direction;
	LightSample Sample(Geometry& scene, Vector3& position);

};

