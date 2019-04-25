#include "GameModel.h"

void GameModel::addBubble(Bubble toAdd) {
	bubbles.push_back(toAdd);
}

void GameModel::addScreenBubble(Bubble toAdd) {
	screenBubbles.push_back(toAdd);
}

void GameModel::removeFirstBubble() {
	bubbles.pop_front();
}

void GameModel::removeAScreenBubble(int pos) {
	if (pos < 0 || pos > screenBubbles.size() - 1) {
		return;
	}
	screenBubbles.erase(screenBubbles.begin() + pos);
}

void GameModel::sortBubbles() {
	std::sort(bubbles.begin(), bubbles.end());
}

std::deque<Bubble> GameModel::getBubblesList() {
	std::deque<Bubble> bubblesCopy = bubbles;
	return bubblesCopy;
}

std::deque<Bubble> GameModel::getScreenBubblesList() {
	std::deque<Bubble> screenBubblesCopy = screenBubbles;
	return screenBubblesCopy;
}
