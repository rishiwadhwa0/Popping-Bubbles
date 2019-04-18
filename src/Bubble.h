#pragma once
#include <iostream>

class Bubble {
	int x;
	int y;
	int radius;
	int color;
	float time;

	public:
		Bubble(int setX, int setY, int setRadius, int setColor, float setTime);
		int getX();
		int getY();
		int getRadius();
		int getColor();
		float getTime();
		friend std::ostream& operator<< (std::ostream &out, Bubble &bubble);
};