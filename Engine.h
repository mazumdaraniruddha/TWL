#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"

using namespace sf;

class Engine {
private:
	TextureHolder mTextureHolder;
	// Player variables
	Thomas mThomas;
	Bob mBob;
	// The level manager
	LevelManager mLevelManager;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	// Force of gravity
	const int GRAVITY = 300;
	// Rendering Window
	RenderWindow mRenderWindow;
	// Main views;
	View mMainView;
	View mLeftView;
	View mRightView;
	// Views for background
	View mBGMainView;
	View mBGLeftView;
	View mBGRightView;
	// View for the HUD
	View mHUDView;
	// Texture/Sprites for background
	Sprite mSpriteBackground;
	Texture mTextureBackground;
	// Is game on?
	bool mIsPlaying = false;
	// Character 1/2 is in focus?
	bool mCharacter1 = true;
	// Strat fullscreen?
	bool mSplitScreen = false;
	// Time left in current level
	float mTimeRemaining = 10;
	Time mGameTimeTotal;
	bool mNewLevelRequired = true;
	// Vertext Array for Level tiles
	VertexArray mVALevel;
	// 2D array map for the level
	int** mArrayLevel = NULL;
	// Texture for the level tiles
	Texture mTextureTiles;
	// PRIVATE FUNCTIONS FOR UPDATING THE GAME
	void input();
	void update(float dtAsSeconds);
	void draw();
	// Load new level
	void loadLevel();

public:
	Engine();
	void run();
};

