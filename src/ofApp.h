#pragma once
#include "ofMain.h"
#include "ofxJSON.h"
#include <vector> 
#include <list>

class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();

    ofxJSONElement result;
	std::vector<vector<double>> circles;
};
