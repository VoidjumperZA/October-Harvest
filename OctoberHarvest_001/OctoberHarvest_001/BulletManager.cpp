#include "BulletManager.hpp"
#include <iostream>

BulletManager::BulletManager(Level *pLevel)
{
	level = pLevel;
}

void BulletManager::AddBullet(int pPlayerState, int pPlayerID, bool pFacingRight, int pLayer)
{
	//pick the right image for the bullet's direction
	string bulletImageLocation = "";
	int bulletRows = 0;
	int bulletColumns = 0;
	sf::Vector2f bulletVelocity(0.0f, 0.0f);
	if (pPlayerID == 0)
	{
		activeGunPos = gunPos_001;
	}
	else
	{
		activeGunPos = gunPos_002;
	}

	//sets precise details for bullets based on the player and it's state
	switch (pPlayerState)
	{
		//LEFT
	case 0:
	case 4:
		bulletImageLocation = "Assets/Sprites/Anim/Final/Bullet_Left_FullSheet.png";
		bulletVelocity.x = -10.0f;
		bulletVelocity.y = 0.0f;
		bulletRows = 1;
		bulletColumns = 3;

		//manual offset to account for gun sprite
		activeGunPos.y -= 25;
		activeGunPos.x -= 65;
		break;
		//RIGHT
	case 1:
	case 5:
		bulletImageLocation = "Assets/Sprites/Anim/Final/Bullet_Right_FullSheet.png";
		bulletVelocity.x = 10.0f;
		bulletVelocity.y = 0.0f;
		bulletRows = 1;
		bulletColumns = 3;

		//manual offset to account for gun sprite
		activeGunPos.y -= 25;
		activeGunPos.x += 25;
		break;
		//SOUTH
	case 2:
	case 6:
		bulletImageLocation = "Assets/Sprites/Anim/Final/Bullet_Backward_FullSheet.png";
		bulletVelocity.x = 0.0f;
		bulletVelocity.y = 10.0f;
		bulletRows = 3;
		bulletColumns = 1;

		//manual offset to account for gun sprite
		activeGunPos.y += 35;
		activeGunPos.x -= 35;
		break;
		//NORTH
	case 3:
	case 7:
		bulletImageLocation = "Assets/Sprites/Anim/Final/Bullet_Forward_FullSheet.png";
		bulletVelocity.x = 0.0f;
		bulletVelocity.y = -10.0f;
		bulletRows = 3;
		bulletColumns = 1;

		//manual offset to account for gun sprite
		activeGunPos.y -= 80;
		if (pFacingRight == true)
		{
			activeGunPos.x -= 50;
		}
		else
		{
			activeGunPos.x -= 20;
		}
		break;
		//DEFAULT
	default:
		bulletImageLocation = "Assets/Sprites/Anim/Final/Bullet_Right_FullSheet.png";
		bulletVelocity.x = 10.0f;
		bulletVelocity.y = 0.0f;
		bulletRows = 1;
		bulletColumns = 3;

		//manual offset to account for gun sprite
		activeGunPos.y -= 25;
		activeGunPos.x += 25;
		break;
	}

	Bullet *newBullet = new Bullet(bulletImageLocation, bulletRows, bulletColumns, bulletVelocity);
	//set position
	newBullet->setPosition(activeGunPos);	 

	level->AddToLayer(newBullet, pLayer, false);
}

void BulletManager::SetGunPosition(int pPlayerID, sf::Vector2f pPosition)
{
	if (pPlayerID == 0)
	{
		gunPos_001 = pPosition;
	}
	else
	{
		gunPos_002 = pPosition;
	}
}
