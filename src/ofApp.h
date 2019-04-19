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

	public:
		void setup();
		void draw();
};
