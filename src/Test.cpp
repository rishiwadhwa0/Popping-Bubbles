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
	gm.removeFirstScreenBubble();
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
