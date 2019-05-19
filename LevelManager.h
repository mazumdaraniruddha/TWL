#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class LevelManager {
private:
	Vector2i mLevelSize;
	Vector2f mStartPosition;
	float mTimeModifier = 1;
	float mBaseTimeLimit = 0;
	int mCurrentLevel = 0;
	const int NUM_LEVELS = 4;

};