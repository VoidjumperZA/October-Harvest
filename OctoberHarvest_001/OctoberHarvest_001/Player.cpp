#include "Player.hpp"
#include <iostream>

Player::Player(string pTextureLocation, int pRows, int pColumns, int pPlayerIndentifier) : GameObject(pTextureLocation, pRows, pColumns)
{
	//a unique indentifier, to help with player spesific functions
	playerIndentifier = pPlayerIndentifier;

	horizontalInertia = 0.0f;
	verticalInertia = 0.0f;
	maxHInertia = 0.7f;
	maxVInertia = 0.7f;
	horizontalAcceleration = 0.003f;
	horizontalDeceleration = 0.0023f;
	verticalAcceleration = 0.003f;
	verticalDeceleration = 0.0023f;

	//store the keybinds relating to player one or two
	forward = new sf::Keyboard::Key[2] { sf::Keyboard::W, sf::Keyboard::Numpad8 };
	backward = new sf::Keyboard::Key[2] { sf::Keyboard::S, sf::Keyboard::Numpad5 };
	left = new sf::Keyboard::Key[2] { sf::Keyboard::A, sf::Keyboard::Numpad4 };
	right = new sf::Keyboard::Key[2] { sf::Keyboard::D, sf::Keyboard::Numpad6 };
	interact = new sf::Keyboard::Key[2] { sf::Keyboard::Space, sf::Keyboard::Right };
	altinteract = new sf::Keyboard::Key[2] { sf::Keyboard::LShift, sf::Keyboard::Add };
}

void Player::Update()
{
	checkForInput();
	//Animate(2, 5, 1000);
	Animate(0, 2, 1, 2, 1000 / (playerIndentifier + 1));
	movement(horizontalInertia, verticalInertia);
	cout << "(" << horizontalInertia << ", " << verticalInertia << ")" << endl;
}

//handle all player input
void Player::checkForInput()
{
	//
	if (sf::Keyboard::isKeyPressed(left[playerIndentifier]))
	{
		inputToMovement(horizontalInertia, horizontalAcceleration, maxHInertia, -1);
	}
	if (sf::Keyboard::isKeyPressed(forward[playerIndentifier]))
	{
		inputToMovement(verticalInertia, verticalAcceleration, maxVInertia, -1);
	}

	//
	if (!sf::Keyboard::isKeyPressed(left[playerIndentifier]) && !(sf::Keyboard::isKeyPressed(right[playerIndentifier])) && horizontalInertia != 0)
	{
		applyInertia(horizontalInertia, horizontalDeceleration);
	}

	if (!sf::Keyboard::isKeyPressed(forward[playerIndentifier]) && !(sf::Keyboard::isKeyPressed(backward[playerIndentifier])) && verticalInertia != 0)
	{
		applyInertia(verticalInertia, verticalDeceleration);
	}

	//
	if (sf::Keyboard::isKeyPressed(right[playerIndentifier]))
	{
		inputToMovement(horizontalInertia, horizontalAcceleration, maxHInertia, 1);
	}
	if (sf::Keyboard::isKeyPressed(backward[playerIndentifier]))
	{
		inputToMovement(verticalInertia, verticalAcceleration, maxVInertia, 1);
	}
}

void Player::inputToMovement(float &pInertiaAxis, float &pAccelerationAxis, float &pMaxInertia, int pPolarity)
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

void Player::applyInertia(float &pInertiaAxis, float &pDecelerationAxis)
{
	/*
	if (horizontalInertia > 0)
	{
	horizontalInertia -= horizontalDeceleration;
	if (horizontalInertia < horizontalDeceleration)
	{
	horizontalInertia = 0;
	}
	}
	if (horizontalInertia < 0)
	{
	horizontalInertia += horizontalDeceleration;
	if (horizontalInertia > horizontalDeceleration)
	{
	horizontalInertia = 0;
	}
	}
 */
	if (pInertiaAxis > 0)
	{
		pInertiaAxis -= pDecelerationAxis;
		if (pInertiaAxis < pDecelerationAxis)
		{
			pInertiaAxis = 0;
		}
	}
	if (pInertiaAxis < 0)
	{
		pInertiaAxis += pDecelerationAxis;
		if (pInertiaAxis > pDecelerationAxis)
		{
			pInertiaAxis = 0;
		}
	}
}
void Player::OnCollision(GameObject *pTargetObject)
{

}

void Player::movement(float pHSpeed, float pVSpeed)
{
	move(sf::Vector2f(pHSpeed, pVSpeed));
}