#include "Bubble.h"

Bubble::Bubble(int setX, int setY, int setSize, int setColor)
{
	x = setX;
	y = setY;
	radius = setSize;
	color = setColor;
}

int Bubble::getX()
{
	return x;
}

int Bubble::getY()
{
	return y;
}

int Bubble::getRadius()
{
	return radius;
}

int Bubble::getColor()
{
	return color;
}
