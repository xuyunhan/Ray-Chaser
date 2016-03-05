#include "stdafx.h"
#include "IntersectResult.h"


IntersectResult::IntersectResult()
{
	this->geometry = nullptr;
	this->distance = 0;
	this->normal = Vector3::Zero();
	this->position = Vector3::Zero();
}


IntersectResult::~IntersectResult()
{
}


// ÎÞ½»µã
IntersectResult IntersectResult::NoHit()
{
	return IntersectResult();
}
