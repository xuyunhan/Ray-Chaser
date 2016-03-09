#pragma once
#include "Vector3.h"
class Color
{
public:
	Color();
	Color::Color(double pr, double pg, double pb);
	~Color();

	double r, g, b;

	static Color Black()
	{
		return Color(0,0,0);
	}

	static Color White()
	{
		return Color(1, 1, 1);
	}

	static Color Blue()
	{
		return Color(0, 0, 1);
	}

	static Color Green()
	{
		return Color(0, 1, 0);
	}
	
	static Color Red()
	{
		return Color(1, 0, 0);
	}

	Color Copy()
	{
		return Color(this->r, this->g, this->b);
	}

	Color Add(Color c)
	{
		return Color(this->r + c.r, this->g + c.g, this->b + c.b);
	}

	Color Multiply(double s)
	{
		return Color(this->r*s, this->g*s, this->b*s);
	}

	// 调制(modulate)操作，其意义为两个颜色中每个颜色通道相乘
	Color Modulate(Color c)
	{
		return Color(this->r * c.r, this->g * c.g, this->b * c.b);
	}
	void Round();
};

