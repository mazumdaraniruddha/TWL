#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
protected:
	Sprite mSprite;
	// Player jump duration
	float mJumpDuraton;
	// Whether character is jumping or falling
	bool mIsJumping;
	bool mIsFalling;
	// Current jump duration
	float mTimeThisJump;
	// Control presses
	bool mRightPressed;
	bool mLeftPressed;
	// Whether initiated a jump
	bool mJustJumped = false;
private:
	// Current gravity value
	float mGravity;
	// Player speed
	float mSpeed = 400;
	Vector2f mPosition;
	// Player's bodypart positions
	FloatRect mFeet;
	FloatRect mHead;
	FloatRect mRight;
	FloatRect mLeft;
	// Player texture
	Texture mTexture;
public:
	void spawn(Vector2f startPosition, float gravity);
	// Pure Virtual/Abstract function to handle input
	bool virtual handleInput() = 0;
	FloatRect getPosition();
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getLeft();
	FloatRect getRight();
	Sprite getSprite();
	// Movement functions
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	// Player center
	Vector2f getCenter();
	// frame update function
	void update(float elapsedTime);
};