#include "Wraith.hpp"
#include <iostream>

Wraith::Wraith(Level *pLevel, string pTextureLocation, int pRows, int pColumns) : Enemy(pLevel, pTextureLocation, pRows, pColumns)
{
	level = pLevel;
	counter = 0;
	explosionCounter = 0;
	speedX = 0.0f;
	speedY = 0.0f;
	targetSpeedX = 0.0f;
	targetSpeedY = 0.0f;
	explosionCreated = false;
}

void Wraith::Update(float pFrameTime)
{
	counter++;

	if (counter >= 10000)
	{
		counter = 0;
	}

	srand(time(NULL));
	if (explosionCreated == false)
	{
		moveAndAnimate();
	}
}

void Wraith::moveAndAnimate()
{
	if (counter % 120 == 0)
	{
		targetSpeedX = 1 - (rand() % 3);
		targetSpeedY = 1 - (rand() % 3);
		//cout << "x: " << speedX << " y: " << speedY << endl;
	}

	//x
	if (speedX < targetSpeedX)
	{
		speedX += ACCELERATION_CONTROL;
	}
	else if (speedX > targetSpeedX)
	{
		speedX -= ACCELERATION_CONTROL;
	}

	//y
	if (speedY < targetSpeedY)
	{
		speedY += ACCELERATION_CONTROL;
	}
	else if (speedY > targetSpeedY)
	{
		speedY -= ACCELERATION_CONTROL;
	}

	move(speedX, speedY);
	if (speedX > 0)
	{
		Animate(0, 0, 0, 2, 250);
	}
	else
	{
		Animate(1, 0, 1, 2, 250);
	}
}