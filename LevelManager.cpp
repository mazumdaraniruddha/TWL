#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>
#include "LevelManager.h"

using namespace sf;
using namespace std;

int** LevelManager::nextLevel(VertexArray& rVaLevel) {
	mLevelSize.x = 0;
	mLevelSize.y = 0;

	mCurrentLevel++;
	if (mCurrentLevel > NUM_LEVELS) {
		mCurrentLevel = 1;
		mTimeModifier -= 0.1f;
	}

	string levelToLoad;
	switch (mCurrentLevel) {
	case 1:
		levelToLoad = "levels/level1.txt";
		mStartPosition.x = 100;
		mStartPosition.y = 100;
		mBaseTimeLimit = 100.0f;
		break;

	case 2:
		levelToLoad = "levels/level2.txt";
		mStartPosition.x = 100;
		mStartPosition.y = 3600;
		mBaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		mStartPosition.x = 1250;
		mStartPosition.y = 0;
		mBaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		mStartPosition.x = 50;
		mStartPosition.y = 200;
		mBaseTimeLimit = 50.0f;
		break;
	}

	ifstream inputFile(levelToLoad);
	string s;

	while (getline(inputFile, s)) {
		++mLevelSize.y;
	}
	mLevelSize.x = s.length();

	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int** arrayLevel = new int* [mLevelSize.y];
	for (int i = 0; i < mLevelSize.y; i++) {
		arrayLevel[i] = new int[mLevelSize.x];
	}

	string row;
	int y = 0;
	while (inputFile >> row) {
		for (int x = 0; x < row.length(); x++) {
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}
		y++;
	}

	inputFile.close();

	rVaLevel.setPrimitiveType(Quads);

	rVaLevel.resize(mLevelSize.x * mLevelSize.y * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int x = 0; x < mLevelSize.x; x++) {
		for (int y = 0; y < mLevelSize.y; y++) {
			rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f((x + 1) * TILE_SIZE , y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f((x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE);
			rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y + 1) * TILE_SIZE);

			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			currentVertex += VERTS_IN_QUAD;
		}
	}

	return arrayLevel;
}

Vector2i LevelManager::getLevelSize() {
	return mLevelSize;
}

int LevelManager::getCurrentLevel() {
	return mCurrentLevel;
}

float LevelManager::getTimeLimit() {
	return mTimeModifier * mBaseTimeLimit;
}

Vector2f LevelManager::getStartPosition() {
	return mStartPosition;
}
