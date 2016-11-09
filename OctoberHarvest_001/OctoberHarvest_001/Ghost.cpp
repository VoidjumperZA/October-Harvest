#include "Ghost.hpp"
#include <iostream>
#include <random>
Ghost::Ghost(Level *pLevel, string pTextureLocation, int pRows, int pColumns) : Enemy(pLevel, pTextureLocation, pRows, pColumns)
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

void Ghost::Update(float pFrameTime)
{/*
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(-1, 1);*/
	counter++;

	if (counter >= 10000)
	{
		counter = 0;
	}

	if (explosionCreated == true)
	{
		explosionCounter++;
		cout << "exp Counter: " << explosionCounter << endl;
		if (explosionCounter >= 100)
		{
			level->RemoveFromLayer(explosion, 1);
			explosion->DeleteGameObject();
			level->RemoveFromLayer(this, 0);
			DeleteGameObject();
		}
	}

	srand(time(NULL));
	if (explosionCreated == false)
	{
		moveAndAnimate();
	}
}

void Ghost::moveAndAnimate()
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

void Ghost::OnCollision(GameObject *pTargetObject)
{
	//if that object is of type:

	//A)  BULLET
	if (dynamic_cast<Bullet*>(pTargetObject) != NULL && explosionCreated == false)
	{
		explosion = new Explosion("Assets/Sprites/Anim/Final/Explosion_FullSheet.png", 1, 2);
		explosion->setPosition(getPosition());
		level->AddToLayer(explosion, 1, false);
		explosionCreated = true;
	}
}