#include "ofApp.h"
#include "Bubble.h"

#include <vector> 
#include <list>
#include <stdlib.h>

void ofApp::setup() {
	//json setup
	setUpParseJson();
 
	//font setup
	verdana.load("verdana.ttf", FONT_SIZE, true, true);
	verdana.setLineHeight(34.0f);
	verdana.setLetterSpacing(1.035);

	//setup new game data
	gm.clearEverything();
	numBubblesPopped = 0;
	
	//setup background
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
}


void ofApp::draw() {
	ofSetHexColor(0x00FF00);

	if (!gameStarted) {
		printWelcomeScreen();
		return;
	}

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
	if (gameEnded || !gameStarted) {
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
		PADDING + 3*FONT_SIZE);
	string numBubblesLeft = "YOU HAD " +
		std::to_string(gm.getBubblesList().size() + MAX_SCREEN_BUBBLES + 1) + 
		" BUBBLES LEFT.";
	verdana.drawString(numBubblesLeft,
		PADDING,
		PADDING + 5*FONT_SIZE);
	verdana.drawString("Press the space-bar to try-again.",
		PADDING,
		PADDING + 7*FONT_SIZE);

}

void ofApp::printWin() {
	verdana.drawString(YOU_WIN_MESSAGE,
		PADDING,
		PADDING + FONT_SIZE);
	string bubblesPopped = std::to_string(numBubblesPopped) + " BUBBLES";
	verdana.drawString(bubblesPopped,
		PADDING,
		PADDING + 3*FONT_SIZE);
	verdana.drawString("Press the space-bar to try-again.",
		PADDING,
		PADDING + 5*FONT_SIZE);
}

void ofApp::printWelcomeScreen() {
	ofSetHexColor(0x00FF00);
	verdana.drawString(WELCOME_MESSAGE,
		PADDING,
		PADDING + FONT_SIZE);
	verdana.drawString(WELCOME_MESSAGE2,
		PADDING,
		PADDING + 3*FONT_SIZE);
	ofSetHexColor(0xffff00);
	verdana.drawString("Press 1, for easy",
		PADDING,
		PADDING + 5*FONT_SIZE);
	ofSetHexColor(0x0000FF);
	verdana.drawString("Press 2, for medium",
		PADDING,
		PADDING + 7*FONT_SIZE);
	ofSetHexColor(0xff0000);
	verdana.drawString("Press 3, for hard",
		PADDING,
		PADDING + 9*FONT_SIZE);
}

void ofApp::keyPressed(int key) {
	//CONTROLING SPEED OF GAME
	if (key == '1') {
		speedFactor = 1;
		ofBackground(255, 255, 0);
	}
	if (key == '2') {
		speedFactor = 0.75;
		ofBackground(0, 0, 255);
	}
	if (key == '3') {
		speedFactor = 0.5;
		ofBackground(255, 0, 0);
	}

	//START GAME
	if (key == OF_KEY_SPACE && !gameStarted) {
		gameStarted = true;
		loadJson();
		startTime = ofGetElapsedTimef();
		ofBackground(0, 0, 0);
	}

	//GO TO WELCOME SCREEN
	if (key == OF_KEY_SPACE && gameEnded) {
		gameStarted = false;
		gameEnded = false;
		setup();
	}
}

void ofApp::setUpParseJson() {
	std::string file = "gameJSON.json";
	// Now parse the JSON
	bool parsingSuccessful = result.open(file);
	if (parsingSuccessful) {
		ofLogNotice("ofApp::setup") << result.getRawString();
	}
	else {
		ofLogError("ofApp::setup") << "Failed to parse JSON" << endl;
	}
}

void ofApp::loadJson() {
	for (Json::ArrayIndex i = 0; i < result["circles"].size(); ++i) {
		int radius = result["circles"][i]["radius"].asInt();
		int color = result["circles"][i]["color"].asInt();

		for (auto t : result["circles"][i]["times"]) {
			int randomX = rand() % ofGetWidth();
			int randomY = rand() % ofGetHeight();
			float time = t.asFloat() * speedFactor;
			Bubble b(randomX, randomY, radius, color, time);
			gm.addBubble(b);
		}
	}
	gm.sortBubbles();
}
