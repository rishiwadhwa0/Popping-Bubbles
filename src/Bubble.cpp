#include "Bubble.h"

Bubble::Bubble(int setX, int setY, int setSize, int setColor, float setTime)
{
	x = setX;
	y = setY;
	radius = setSize;
	color = setColor;
	time = setTime;
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

float Bubble::getTime()
{
	return time;
}

std::ostream& operator<< (std::ostream &out, Bubble &bubble) {
	out << "X: " << bubble.getX() << ", Y: " << bubble.getY() << ", ";
	out << "Radius: " << bubble.getRadius() << ", Color: " << bubble.getColor() << ", ";
	out << "Time: " << bubble.getTime() << "\n";
	return out;
}

bool operator>(Bubble & b1, Bubble & b2)
{
	return b1.getTime() > b2.getTime();
}

bool operator<=(Bubble & b1, Bubble & b2)
{
	return b1.getTime() <= b2.getTime();
}

bool operator<(Bubble & b1, Bubble & b2)
{
	return b1.getTime() < b2.getTime();
}

bool operator>=(Bubble & b1, Bubble & b2)
{
	return b1.getTime() >= b2.getTime();
}
