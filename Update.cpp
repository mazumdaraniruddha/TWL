#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dtAsSeconds) {
	if (mNewLevelRequired) {
		loadLevel();
	}

	if (mIsPlaying) {
		// Update Thomas
		mThomas.update(dtAsSeconds);
		// Update Bob
		mBob.update(dtAsSeconds);
		// Timer coutdown
		mTimeRemaining -= dtAsSeconds;
		// Player time ran out?
		if (mTimeRemaining <= 0) {
			mNewLevelRequired = true;
		}
	} // END IF PLAYING

	if (mSplitScreen) {
		mLeftView.setCenter(mThomas.getCenter());
		mRightView.setCenter(mBob.getCenter());
	} else {
		if (mCharacter1) {
			mMainView.setCenter(mThomas.getCenter());
		} else {
			mMainView.setCenter(mBob.getCenter());
		}
	}
}