#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ofApp.h"
#include <vector>

TEST_CASE("test adding bubble and removing") {
	GameModel gm;
	gm.addBubble(Bubble(1, 1, 1, 1, 1));
	std::deque<Bubble> bubbles = gm.getBubblesList();
	REQUIRE(bubbles.size() == 1);
	gm.removeFirstBubble();
	bubbles = gm.getBubblesList();
	REQUIRE(bubbles.size() == 0);
}

TEST_CASE("test adding bubble to screen and removing") {
	GameModel gm;
	gm.addScreenBubble(Bubble(1, 1, 1, 1, 1));
	std::deque<Bubble> sBubbles = gm.getScreenBubblesList();
	REQUIRE(sBubbles.size() == 1);
	gm.removeAScreenBubble(0);
	sBubbles = gm.getBubblesList();
	REQUIRE(sBubbles.size() == 0);
}

TEST_CASE("test sorting mechanism") {
	GameModel gm;
	gm.addBubble(Bubble(1, 1, 1, 1, 2));
	gm.addBubble(Bubble(2, 2, 2, 2, 3));
	gm.addBubble(Bubble(2, 2, 2, 2, 1));
	gm.sortBubbles();
	std::deque<Bubble> bubbles = gm.getBubblesList();
	for (int i = 1; i < bubbles.size(); i++) {
		REQUIRE(bubbles[i].getTime() >= bubbles[i - 1].getTime());
	}
}

TEST_CASE("test removing a bubble mechanism") {
	GameModel gm;
	gm.addScreenBubble(Bubble(1, 1, 1, 1, 2));
	gm.addScreenBubble(Bubble(2, 2, 2, 2, 3));
	gm.addScreenBubble(Bubble(2, 2, 2, 2, 1));
	gm.removeAScreenBubble(1); //removes bubble with time = 3
	std::deque<Bubble> bubbles = gm.getScreenBubblesList();
	REQUIRE(bubbles.size() == 2);
	REQUIRE(bubbles[0].getTime() == 2);
	REQUIRE(bubbles[1].getTime() == 1);
}

TEST_CASE("test removing a bubble not in list") {
	GameModel gm;
	gm.addScreenBubble(Bubble(1, 1, 1, 1, 2));
	gm.addScreenBubble(Bubble(2, 2, 2, 2, 3));
	gm.addScreenBubble(Bubble(2, 2, 2, 2, 1));
	REQUIRE(gm.removeAScreenBubble(-1) == false);
	REQUIRE(gm.removeAScreenBubble(3) == false);
	std::deque<Bubble> bubbles = gm.getScreenBubblesList();
	REQUIRE(bubbles.size() == 3);
}