#include "stdafx.h"
#include "Light.h"


Light::Light()
{
}


Light::~Light()
{
}


LightSample Light::Sample(Geometry& scene, Vector3& position)
{
	return LightSample::Zero();
}
