#include "stdafx.h"
#include "Engine.h"

Engine::Engine() {
	// Get screen resolution and create SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	mRenderWindow.create(VideoMode(resolution.x, resolution.y), "ThomasWasLate", Style::Fullscreen);
	// Init Fullscreen view
	mMainView.setSize(resolution);
	mHUDView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	// Init splitscreen views
	mLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	mRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	mBGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	mBGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	mTextureBackground = TextureHolder::GetTexture("graphics/background.png");
	mSpriteBackground.setTexture(mTextureBackground);
}

void Engine::run() {
	Clock clock;

	while (mRenderWindow.isOpen()) {
		Time dt = clock.restart();
		// Update game total time;
		mGameTimeTotal += dt;
		// Get the current time delta
		float dtAsSeconds = dt.asSeconds();
		input();
		update(dtAsSeconds);
		draw();
	}
}