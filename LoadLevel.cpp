#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel() {
	mIsPlaying = false;
	// Delete previously allocated memory
	for (int i = 0; i < mLevelManager.getLevelSize().y; i++) {
		delete[] mArrayLevel[i];
	}
	delete[] mArrayLevel;
	// Load next 2d array/Repopulate the vertex array
	mArrayLevel = mLevelManager.nextLevel(mVALevel);
	// New time limit;
	mTimeRemaining = mLevelManager.getTimeLimit();
	// Spawn players
	mThomas.spawn(mLevelManager.getStartPosition(), GRAVITY);
	mBob.spawn(mLevelManager.getStartPosition(), GRAVITY);
	mNewLevelRequired = false;
}