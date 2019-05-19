#include "stdafx.h"
#include "Engine.h"

void Engine::draw() {
	mRenderWindow.clear(Color::White);

	if (!mSplitScreen) {
		// Switch to Main background view
		mRenderWindow.setView(mBGMainView);
		mRenderWindow.draw(mSpriteBackground);
		// Switch to main view
		mRenderWindow.setView(mMainView);
	} else {
		// Split screen active
		// Draw Thomas's side
		mRenderWindow.setView(mBGLeftView);
		mRenderWindow.draw(mSpriteBackground);
		mRenderWindow.setView(mLeftView);
		// DRaw Bob's side
		mRenderWindow.setView(mBGRightView);
		mRenderWindow.draw(mSpriteBackground);
		mRenderWindow.setView(mRightView);
	}

	mRenderWindow.setView(mHUDView);
	mRenderWindow.display();
}