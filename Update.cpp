#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dtAsSeconds) {
	if (mIsPlaying) {
		// Timer coutdown
		mTimeRemaining -= dtAsSeconds;
		// Player time ran out?
		if (mTimeRemaining <= 0) {
			mNewLevelRequired = true;
		}
	} // END IF PLAYING
}