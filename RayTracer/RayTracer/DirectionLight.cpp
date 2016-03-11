#include "stdafx.h"
#include "DirectionLight.h"


DirectionLight::DirectionLight()
{
}

DirectionLight::DirectionLight(Color irradiance, Vector3 direction)
{
	this->direction = direction; this->irradiance = irradiance;
	this->shadow_on = true;//´ò¿ªÒõÓ°

	this->L = this->direction.Normalize().Negate();
}


DirectionLight::~DirectionLight()
{
}

LightSample DirectionLight::Sample(Geometry& scene, Vector3& position)
{
	return LightSample::Zero();//todo
}