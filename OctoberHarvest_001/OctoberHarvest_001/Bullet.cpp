#include "Bullet.hpp"
#include "Enemy.hpp"
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

void Bullet::OnCollision(GameObject *pTargetObject)
{
	//B) AMMOPACK
	if (dynamic_cast<Enemy*>(pTargetObject) != NULL)
	{

	}
}