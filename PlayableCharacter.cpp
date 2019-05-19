#include "stdafx.h"
#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity) {
	mPosition.x = startPosition.x;
	mPosition.y = startPosition.y;

	mGravity = gravity;

	mSprite.setPosition(mPosition);
}

void PlayableCharacter::update(float elapsedTime) {
	if (mRightPressed) {
		mPosition.x += elapsedTime * mSpeed;
	}
	if (mLeftPressed) {
		mPosition.x -= elapsedTime * mSpeed;
	}
	// Handle jump
	if (mIsJumping) {
		mTimeThisJump += elapsedTime;
		// If jump going up
		if (mTimeThisJump < mJumpDuraton) {
			mPosition.y -= mGravity * 2 * elapsedTime;
		} else {
			mIsJumping = false;
			mIsFalling = true;
		}
	}
	// Handle fall
	if (mIsFalling) {
		mPosition.y += mGravity * elapsedTime;
	}
	// Update all body part rects
	FloatRect r = getPosition();

	mFeet.left = r.left + 3;
	mFeet.top = r.top + r.height - 1;
	mFeet.width = r.width - 6;
	mFeet.height = 1;

	mHead.left = r.left;
	mHead.top = r.top + (r.height * 0.3);
	mHead.width = r.width;
	mHead.height = 1;

	mRight.left = r.left + r.width - 2;
	mRight.top = r.top + r.height * 0.35;
	mRight.width = 1;
	mRight.height = r.height * 0.3;

	mLeft.left = r.left;
	mLeft.top = r.top + r.height * 0.5;
	mLeft.width = 1;
	mLeft.height = r.height * 0.3;

	mSprite.setPosition(mPosition);
}

FloatRect PlayableCharacter::getPosition() {
	return mSprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter() {
	return Vector2f(mPosition.x + mSprite.getGlobalBounds().width / 2, 
		mPosition.y + mSprite.getGlobalBounds().height / 2);
}

FloatRect PlayableCharacter::getFeet() {
	return mFeet;
}

FloatRect PlayableCharacter::getHead() {
	return mHead;
}

FloatRect PlayableCharacter::getLeft() {
	return mLeft;
}

FloatRect PlayableCharacter::getRight() {
	return mRight;
}

Sprite PlayableCharacter::getSprite() {
	return mSprite;
}

void PlayableCharacter::stopFalling(float position) {
	mPosition.y = position - getPosition().height;
	mSprite.setPosition(mPosition);
	mIsFalling = false;
}

void PlayableCharacter::stopRight(float position) {
	mPosition.x = position - getPosition().width;
	mSprite.setPosition(mPosition);
}

void PlayableCharacter::stopLeft(float position) {
	mPosition.x = position + getPosition().width;
	mSprite.setPosition(mPosition);
}

void PlayableCharacter::stopJump() {
	mIsJumping = false;
	mIsFalling = true;
}