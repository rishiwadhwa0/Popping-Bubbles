#include "ofApp.h"
#include "../Bubble.h"
#include <vector> 
#include <list>
#include <stdlib.h>

void ofApp::setup()
{
    std::string file = "example.json";
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << result.getRawString();
    } else {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }

	for (Json::ArrayIndex i = 0; i < result["circles"].size(); ++i)
	{
		int radius = result["circles"][i]["radius"].asInt();
		int color = result["circles"][i]["color"].asInt();

		for (auto t : result["circles"][i]["times"]) {
			int randomX = rand() % ofGetWidth();
			int randomY = rand() % ofGetHeight();
			float time = t.asFloat();
			Bubble b(randomX, randomY, radius, color, time);
			bubbles.push_back(b);
		}
	}
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetHexColor(0x00FF00);
    std::stringstream ss;
	
	for (Bubble bubble : bubbles) {
		ss << bubble;
	}

	ofDrawBitmapString(ss.str(), 10, 14);
}
