#include "stdafx.h"
#include "LightSample.h"


LightSample::LightSample()
{
}


LightSample::~LightSample()
{
}

LightSample::LightSample(Vector3 position, Color elColor)
{
	this->L = position;
	this->EL = elColor;
}
LightSample LightSample::Zero()
{
	return LightSample(Vector3::Zero(),Color::Black());
}
