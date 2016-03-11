#pragma once
#include "Color.h"
#include "Vector3.h"

class LightSample
{
private:
	LightSample();
public:
	LightSample(Vector3 position, Color elColor);
	~LightSample();

	Vector3 L;//��Դ
	Color EL;// �����
	static LightSample Zero();
};

