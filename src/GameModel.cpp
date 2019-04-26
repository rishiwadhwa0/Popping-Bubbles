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

bool GameModel::removeAScreenBubble(int pos) {
	if (pos < 0 || pos > screenBubbles.size() - 1) {
		return false;
	}
	screenBubbles.erase(screenBubbles.begin() + pos);
	return true;
}

void GameModel::sortBubbles() {
	std::sort(bubbles.begin(), bubbles.end());
}

void GameModel::clearEverything() {
	bubbles.clear();
	screenBubbles.clear();
}

std::deque<Bubble> GameModel::getBubblesList() {
	std::deque<Bubble> bubblesCopy = bubbles;
	return bubblesCopy;
}

std::deque<Bubble> GameModel::getScreenBubblesList() {
	std::deque<Bubble> screenBubblesCopy = screenBubbles;
	return screenBubblesCopy;
}
