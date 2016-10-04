#include "Player.hpp"
#include <iostream>

Player::Player(string pTextureLocation, int pRows, int pColumns, int pPlayerIndentifier) : GameObject(pTextureLocation, pRows, pColumns)
{
	//a unique indentifier, to help with player spesific functions
	playerIndentifier = pPlayerIndentifier;

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
}

//handle all player input
void Player::checkForInput()
{
	if (sf::Keyboard::isKeyPressed(left[playerIndentifier]))
	{
		move(sf::Vector2f(-1, 0));
		movement();
	}
	if (sf::Keyboard::isKeyPressed(right[playerIndentifier]))
	{
		move(sf::Vector2f(1, 0));
	}
}

void Player::OnCollision(GameObject *pTargetObject)
{

}

void Player::movement()
{

}