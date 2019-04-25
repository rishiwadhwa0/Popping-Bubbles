#pragma once
#include "Bubble.h"

#include <deque>
#include <vector> 
#include <list>
#include <stdlib.h>
#include <algorithm>

class GameModel {
	std::deque<Bubble> bubbles;
	std::deque<Bubble> screenBubbles;

	public:
		void addBubble(Bubble toAdd);
		void addScreenBubble(Bubble toAdd);
		void removeFirstBubble();
		void removeAScreenBubble(int pos);
		void sortBubbles();
		std::deque<Bubble> getBubblesList();
		std::deque<Bubble> getScreenBubblesList();
};