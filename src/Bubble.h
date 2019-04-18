#pragma once

class Bubble {
	int x;
	int y;
	int radius;
	int color;

	public:
		Bubble(int setX, int setY, int setRadius, int setColor);
		int getX();
		int getY();
		int getRadius();
		int getColor();
};