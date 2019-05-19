#include "stdafx.h"
#include "Engine.h"

void Engine::input() {
	Event event;
	while (mRenderWindow.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			// Handle Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				mRenderWindow.close();
            }
			// Handle start game
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				mIsPlaying = true;
			}
			// Switch players
			if (Keyboard::isKeyPressed(Keyboard::Q)) {
				mCharacter1 != mCharacter1;
			}
			// Switch between Fullscreen/Split
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				mSplitScreen = !mSplitScreen;
			}
		}
	}
}