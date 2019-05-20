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
public:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	float getTimeLimit();
	Vector2f getStartPosition();
	int** nextLevel(VertexArray& rVaLevel);
	Vector2i getLevelSize();
	int getCurrentLevel();
};