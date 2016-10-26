#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(string pTextureLocation, int pRows, int pColumns, sf::Vector2f pStartingVelocity) : GameObject(pTextureLocation, pRows, pColumns)
{
	SetFrame(0);
	frameSwitcher = 0;
	inputVelocity = pStartingVelocity;
}

void Bullet::Update(float pFrameTime)
{
	if (frameSwitcher == 15)
	{
		SetFrame(1);
	}
	move(inputVelocity);
	if (frameSwitcher <= 15)
	{
		frameSwitcher++;
	}
}