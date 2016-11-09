#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(Level *pLevel, string pTextureLocation, int pRows, int pColumns) : GameObject(pTextureLocation, pRows, pColumns)
{
	level = pLevel;
}

void Enemy::Update(float pFrameTime)
{
	//if (getPostion().x < )
	//{

	//}
	//setPosition(oldPosition);
}

void Enemy::recordOldPosition()
{
	oldPosition = getPosition();
}

