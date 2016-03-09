#include "stdafx.h"
#include "Color.h"


Color::Color()
{
	r = g = b = 0;
}

Color::Color(double pr, double pg, double pb)
{
	r = pr;
	g = pg;
	b = pb;
}

Color::~Color()
{
}


void Color::Round()
{
	if (r>1)
	{
		r = 1;
	}
	if (g > 1)
	{
		g = 1;
	}
	if (b > 1)
	{
		b = 1;
	}
// 	return;
// 
// 	double l =  sqrt(this->r * this->r + this->g* this->g + this->b * this->b);
// 	double m = max(r, g);
// 	m = max(m, b);
// 	double inv = 1.0 / m;
// 	this->r *= inv;
// 	this->g *= inv;
// 	this->b *= inv;
}
