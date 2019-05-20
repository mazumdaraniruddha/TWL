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

		mRenderWindow.draw(mVALevel, &mTextureTiles);

		mRenderWindow.draw(mThomas.getSprite());
		mRenderWindow.draw(mBob.getSprite());
	} else {
		// Split screen active
		// Draw Thomas's side
		mRenderWindow.setView(mBGLeftView);
		mRenderWindow.draw(mSpriteBackground);
		mRenderWindow.setView(mLeftView);
		
		mRenderWindow.draw(mVALevel, &mTextureTiles);

		mRenderWindow.draw(mBob.getSprite());
		mRenderWindow.draw(mThomas.getSprite());
		// DRaw Bob's side
		mRenderWindow.setView(mBGRightView);
		mRenderWindow.draw(mSpriteBackground);
		mRenderWindow.setView(mRightView);

		mRenderWindow.draw(mVALevel, &mTextureTiles);

		mRenderWindow.draw(mThomas.getSprite());
		mRenderWindow.draw(mBob.getSprite());
	}

	mRenderWindow.setView(mHUDView);
	mRenderWindow.display();
}