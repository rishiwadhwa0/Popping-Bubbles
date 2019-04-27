#pragma once
#include "ofMain.h"
#include "ofxJSON.h"
#include "Bubble.h"
#include "GameModel.h"

#include <deque>
#include <vector> 
#include <list>

enum GameState { WelcomeScreen, GameScreen, EndScreen };

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
	string const WELCOME_MESSAGE = "~BUBBLEZ~";
	string const WELCOME_MESSAGE2 = "Press the space-bar to continue.";
	int const PADDING = 15;
	/*bool gameended = false;
	bool gamestarted = false;*/
	GameState gameState = WelcomeScreen;
	const int OF_KEY_SPACE = 32;
	float speedFactor = 1;

	public:
		void setup();
		void draw();
		void mousePressed(int x, int y, int button);
		void keyPressed(int key);
		void printGameOver();
		void printWin();
		void printWelcomeScreen();
		void setUpParseJson();
		void loadJson();
};
