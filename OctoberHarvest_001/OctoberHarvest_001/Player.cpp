#include "Player.hpp"
#include "AmmoPack.hpp"
#include <iostream>
//#define DEBUG_VOID

Player::Player(GameObject *pAnimSprite, string pHitBoxTextureLocation, int pHitBoxRows, int pHitBoxColumns, BulletManager *pBulletManager, int pPlayerIndentifier) : GameObject(pHitBoxTextureLocation, pHitBoxRows, pHitBoxColumns)
{
	//a unique indentifier, to help with player spesific functions
	playerIdentifier = pPlayerIndentifier;

	animatedGraphics = pAnimSprite;
	bulletManager = pBulletManager;	

	totalAmmo = MAX_TOTAL_AMMO;
	currentAmmoInMag = 0;

	horizontalInertia = 0.0f;
	verticalInertia = 0.0f;

	fireAxisLock = false;
	reloadIndividualRoundLock = false;

    playerState = IdlingRight;
	facingRight = true;

	//store the keybinds relating to player one or two
	north = new sf::Keyboard::Key[2] { sf::Keyboard::W, sf::Keyboard::Numpad8 };
	south = new sf::Keyboard::Key[2] { sf::Keyboard::S, sf::Keyboard::Numpad5 };
	left = new sf::Keyboard::Key[2] { sf::Keyboard::A, sf::Keyboard::Numpad4 };
	right = new sf::Keyboard::Key[2] { sf::Keyboard::D, sf::Keyboard::Numpad6 };
	fire = new sf::Keyboard::Key[2] { sf::Keyboard::Space, sf::Keyboard::Right };
	reloadAction = new sf::Keyboard::Key[2]{ sf::Keyboard::R, sf::Keyboard::Numpad7 };
	interact = new sf::Keyboard::Key[2]{ sf::Keyboard::E, sf::Keyboard::PageUp };
	altinteract = new sf::Keyboard::Key[2] { sf::Keyboard::LShift, sf::Keyboard::Add };

	setUpSound();
}

void Player::Update(float pFrameTime)
{
	recordOldPosition();
	checkForInput();
	movement(horizontalInertia * pFrameTime, verticalInertia * pFrameTime);
	controlAnimation();

    //cout << "interia: [" << horizontalInertia << ", " << verticalInertia << "]" << endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		switchStates(HitRight);
	}
}

//handle all player input
void Player::checkForInput()
{
	//
	//				MOVEMENT
	//

	//left and north (negative)
	if (sf::Keyboard::isKeyPressed(left[playerIdentifier]))
	{
		switchStates(WalkingLeft);
		inputToMovement(horizontalInertia, HORIZONTAL_ACCELERATION, MAX_H_INERTIA, -1);
	}
	if (sf::Keyboard::isKeyPressed(north[playerIdentifier]))
	{
		switchStates(WalkingNorth);
		inputToMovement(verticalInertia, VERTICAL_ACCELERATION, MAX_V_INERTIA, -1);
	}

	//if no key presses
	if (!sf::Keyboard::isKeyPressed(left[playerIdentifier]) && !(sf::Keyboard::isKeyPressed(right[playerIdentifier])) && horizontalInertia != 0)
	{
		applyInertia(horizontalInertia, HORIZONTAL_DECELERATION);
	}

	if (!sf::Keyboard::isKeyPressed(north[playerIdentifier]) && !(sf::Keyboard::isKeyPressed(south[playerIdentifier])) && verticalInertia != 0)
	{
		applyInertia(verticalInertia, VERTICAL_DECELERATION);
	}

	//right and south (positive)
	if (sf::Keyboard::isKeyPressed(right[playerIdentifier]))
	{
		switchStates(WalkingRight);
		inputToMovement(horizontalInertia, HORIZONTAL_ACCELERATION, MAX_H_INERTIA, 1);
	}
	if (sf::Keyboard::isKeyPressed(south[playerIdentifier]))
	{
		switchStates(WalkingSouth);
		inputToMovement(verticalInertia, VERTICAL_ACCELERATION, MAX_V_INERTIA, 1);
	}

	//
	//				INTERACTION
	//

	//firing
	if (sf::Keyboard::isKeyPressed(fire[playerIdentifier]))
	{
		if (chamberingRoundLock == false && currentAmmoInMag >= 1)
		{
			cout << "MAG: " << currentAmmoInMag << " | AMMO: " << totalAmmo << endl;
			bulletManager->AddBullet(playerState, playerIdentifier, facingRight, 0);
			currentAmmoInMag -= 1;
			clock->restart();
			chamberingRoundLock = true;
		}
		else if (chamberingRoundLock == false && currentAmmoInMag <= 0)
		{
			//play sound
		}

		sf::Time &elapsedTime = clock->getElapsedTime();
		if (elapsedTime.asMilliseconds() >= TIME_BETWEEN_SHOTS)
		{
			chamberingRoundLock = false;
		}

		/*

		if (interactAxisLock == false)
		{
			interactAxisLock = true;
		}
		//interactAxisLock = true;
		{
			bulletManager->AddBullet(playerState, playerIdentifier, facingRight, 0);
			clock->restart();
		}*/
	}
	if (!sf::Keyboard::isKeyPressed(fire[playerIdentifier]))
	{
		fireAxisLock = false;
	}

	//manual reloading
	if (sf::Keyboard::isKeyPressed(reloadAction[playerIdentifier]))
	{
		if (reloadLock == false)
		{
			reload();
			reloadLock = true;
		}
	}
	if (!sf::Keyboard::isKeyPressed(reloadAction[playerIdentifier]))
	{
		reloadLock = false;
	}
}

void Player::inputToMovement(float &pInertiaAxis, float const &pAccelerationAxis, float const &pMaxInertia, int pPolarity)
{
	pInertiaAxis += pAccelerationAxis * pPolarity;
	if (pPolarity < 0)
	{
		if (pInertiaAxis <= pMaxInertia * pPolarity)
		{
			pInertiaAxis = pMaxInertia * pPolarity;
		}
	}
	else
	{
		if (pInertiaAxis >= pMaxInertia * pPolarity)
		{
			pInertiaAxis = pMaxInertia * pPolarity;
		}
	}
	
}

void Player::applyInertia(float &pInertiaAxis, float const &pDecelerationAxis)
{
	//if we have a positive inertia, decrease it
	if (pInertiaAxis > 0)
	{
		pInertiaAxis -= pDecelerationAxis;
		//once it drops below the threshold of deceleration, zero it
		if (pInertiaAxis < pDecelerationAxis)
		{
			//set the correct idling states based on the last state the player was in
			walkToIdle();
			pInertiaAxis = 0;
		}
	}
	//if we have a negative inertia, increase it
	if (pInertiaAxis < 0)
	{
		pInertiaAxis += pDecelerationAxis;
		//once it drops below the threshold of deceleration, zero it
		if (pInertiaAxis > -pDecelerationAxis)
		{
			//set the correct idling states based on the last state the player was in
			walkToIdle();
			pInertiaAxis = 0;
		}
	}
}

void Player::OnCollision(GameObject *pTargetObject)
{	
		//if that object is of type:
		//A) PLAYER
		if (dynamic_cast<Player*>(pTargetObject) != NULL)
		{
			setPosition(oldPosition);
			reflectInertia(0.3f);		
		}

		//B) AMMOPACK
		if (dynamic_cast<AmmoPack*>(pTargetObject) != NULL)
		{
			totalAmmo += MAGAZINE_SIZE;
			if (totalAmmo > MAX_TOTAL_AMMO)
			{
				totalAmmo = MAX_TOTAL_AMMO;
			}
		}
}

void Player::controlAnimation()
{
	switch(playerState)
	{
	case 0:
		//walking left
		animatedGraphics->Animate(1, 23, 1, 29, 145);
		break;
	case 1:
		//walking right
		animatedGraphics->Animate(0, 23, 0, 29, 145);
		break;
	case 2:
	case 3:
		//walking south or north
		if (facingRight == true)
		{
			animatedGraphics->Animate(0, 23, 0, 29, 145);
		}
		else
		{
			animatedGraphics->Animate(1, 23, 1, 29, 145);
		}
		break;
	case 4:
		//idling left
		animatedGraphics->Animate(1, 1, 1, 10, 145);
		break;
	case 5:
		//idling right
		animatedGraphics->Animate(0, 1, 0, 10, 145); //145 death 50
		break;
	case 6:
	case 7:
		if (facingRight == true)
		{
			animatedGraphics->Animate(0, 1, 0, 10, 145);
		}
		else
		{
			animatedGraphics->Animate(1, 1, 1, 10, 145);
		}
		break;
	case 8:
		animatedGraphics->Animate(1, 0, 1, 1, 50);
		break;
	case 9:
		animatedGraphics->Animate(0, 0, 0, 1, 50);
		break;
	}
}

void Player::Translate(float pXTranslation, float pYTranslation)
{
	move(pXTranslation, pYTranslation);
}

void Player::movement(float pHSpeed, float pVSpeed)
{
	move(sf::Vector2f(pHSpeed, pVSpeed));
}

void Player::reload()
{
	int availableSlotsInMag = MAGAZINE_SIZE - currentAmmoInMag;
	for (size_t i = 0; i < availableSlotsInMag; i++)
	{
		if (totalAmmo > 0)
		{
			if (reloadIndividualRoundLock == false)
			{
				reloadIndividualRoundLock = true;
				reloadSound->play();
				currentAmmoInMag += 1;
				totalAmmo -= 1;
				cout << "MAG: " << currentAmmoInMag << " | AMMO: " << totalAmmo << endl;
			}
			if (reloadSound->getStatus() != reloadSound->Playing)
			{
				cout << "good" << endl;
				reloadIndividualRoundLock = false;
			}
		}
		else
		{
			break;
		}
	}

}

int Player::GetPlayerIdentifier()
{
	return playerIdentifier;
}

int Player::GetPlayerState()
{
	return playerState;
}

bool Player::IsFacingRight()
{
	return facingRight;
}

int Player::invert(int pOther)
{
	int x = -pOther;
	return x;
}

void Player::recordOldPosition()
{
	oldPosition = getPosition();
}

void Player::reflectInertia(float pScalar)
{
	horizontalInertia *= pScalar;
	verticalInertia *= pScalar;

	horizontalInertia = -horizontalInertia;
	verticalInertia = -verticalInertia;
}

void Player::switchStates(State pState)
{
	if (pState != playerState)
	{
		previousPlayerState = playerState;
		playerState = pState;
		if (pState == WalkingRight || pState == IdlingRight || pState == HitRight)
		{
			facingRight = true;
		}
		else if (pState == WalkingLeft || pState == IdlingLeft || pState == HitLeft)
		{
			facingRight = false;
		}
#ifdef DEBUG_VOID
		cout << "Input state is State " << pState << "making it also previous State (" << previousPlayerState << ") while the new State is " << playerState << " and 'facingRight' is " << facingRight << endl;
#endif
	}
	else 
	{
#ifdef DEBUG_VOID
		cout << "The input state was the same as the output state. Returning." << endl;
#endif
		return;
	}
}

void Player::setUpSound()
{
	//reloadSoundBuffer->loadFromFile("Assets/Sounds/Shotgun_Reload.ogg");
	reloadSoundBuffer->loadFromFile("Assets/Sounds/Shotgun_Reload.ogg");
	reloadSound->setBuffer(*reloadSoundBuffer);
}

//moves from a walking state to an idling state, regardless of velocity
//this is to account for knockback, which has the opposite velocity
//of the state we want to be in
void Player::walkToIdle()
{
	if (playerState == WalkingRight)
	{
		switchStates(IdlingRight);
	}
	if (playerState == WalkingSouth)
	{
		switchStates(IdlingSouth);
	}
	if (playerState == WalkingLeft)
	{
		switchStates(IdlingLeft);
	}
	if (playerState == WalkingNorth)
	{
		switchStates(IdlingNorth);
	}
}