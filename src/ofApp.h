#pragma once
#include "ofMain.h"
#include "ofxJSON.h"
#include "Bubble.h"
#include "GameModel.h"

#include <deque>
#include <vector> 
#include <list>

class ofApp: public ofBaseApp
{
	ofxJSONElement result;
	GameModel gm;
	float startTime;
	int const MAX_SCREEN_BUBBLES = 3;
	ofTrueTypeFont	verdana;
	int const FONT_SIZE = 60;
	int numBubblesPopped = 0;
	string const GAME_OVER_MESSAGE = "GAME OVER. YOU POPPED:";
	string const YOU_WIN_MESSAGE = "YOU WIN!!! YOU POPPED:";
	int const PADDING = 15;
	bool gameEnded = false;

	public:
		void setup();
		void draw();
		void mousePressed(int x, int y, int button);
		void printGameOver();
		void printWin();
};
