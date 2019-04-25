#include "ofApp.h"
#include "Bubble.h"

#include <vector> 
#include <list>
#include <stdlib.h>

void ofApp::setup() {
    std::string file = "example.json";
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << result.getRawString();
    } else {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }

	verdana.load("verdana.ttf", FONT_SIZE, true, true);
	verdana.setLineHeight(34.0f);
	verdana.setLetterSpacing(1.035);

	for (Json::ArrayIndex i = 0; i < result["circles"].size(); ++i) {
		int radius = result["circles"][i]["radius"].asInt();
		int color = result["circles"][i]["color"].asInt();

		for (auto t : result["circles"][i]["times"]) {
			int randomX = rand() % ofGetWidth();
			int randomY = rand() % ofGetHeight();
			float time = t.asFloat();
			Bubble b(randomX, randomY, radius, color, time);
			gm.addBubble(b);
		}
	}
	gm.sortBubbles();

	startTime = ofGetElapsedTimef();
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
}


void ofApp::draw() {
	ofSetHexColor(0x00FF00);
	std::stringstream ss;

	if (gm.getScreenBubblesList().size() > MAX_SCREEN_BUBBLES) {
		printGameOver();
		gameEnded = true;
		return;
	}

	if (gm.getBubblesList().size() == 0 && gm.getScreenBubblesList().size() == 0) {
		printWin();
		gameEnded = true;
		return;
	}

	std::deque<Bubble> bubbles = gm.getBubblesList();
	if (bubbles.size() > 0) {
		Bubble bubble = bubbles[0];
		if (ofGetElapsedTimef() - startTime >= bubble.getTime()) {
			ofSetColor(bubble.getColor());
			ofDrawCircle(bubble.getX(), bubble.getY(), bubble.getRadius());
			gm.addScreenBubble(bubble); //adds the current bubble to GM's screenBubble list
			gm.removeFirstBubble(); //removes the bubble from GM's total bubble list
		}
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	if (gameEnded) {
		return;
	}
	std::deque<Bubble> bubbles = gm.getScreenBubblesList();
	for (int i = bubbles.size() - 1; i >= 0; i--) {
		Bubble bubble = bubbles[i];
		int bR = bubble.getRadius();
		int bX = bubble.getX();
		int bY = bubble.getY();
		if (std::abs(x - bX) <= bR && std::abs(y - bY) <= bR) {
			ofSetColor(0,0,0);
			ofDrawCircle(bubble.getX(), bubble.getY(), bubble.getRadius());
			gm.removeAScreenBubble(i);
			numBubblesPopped++;
		}
	}
}

void ofApp::printGameOver() {
	verdana.drawString(GAME_OVER_MESSAGE,
		PADDING,
		PADDING + FONT_SIZE);
	string bubblesPopped = std::to_string(numBubblesPopped) + " BUBBLES";
	verdana.drawString(bubblesPopped,
		PADDING,
		PADDING + 3 * FONT_SIZE);
	string numBubblesLeft = "YOU HAD " +
		std::to_string(gm.getBubblesList().size() + MAX_SCREEN_BUBBLES + 1) + 
		" BUBBLES LEFT";
	verdana.drawString(numBubblesLeft,
		PADDING,
		PADDING + 5 * FONT_SIZE);
}

void ofApp::printWin() {
	verdana.drawString(YOU_WIN_MESSAGE,
		PADDING,
		PADDING + FONT_SIZE);
	string bubblesPopped = std::to_string(numBubblesPopped) + " BUBBLES";
	verdana.drawString(bubblesPopped,
		PADDING,
		PADDING + 3 * FONT_SIZE);
	return;
}