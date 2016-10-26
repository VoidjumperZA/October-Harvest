#include "Gun.hpp"
#include <iostream>

Gun::Gun(string pTextureLocation, int pRows, int pColumns, GameObject *pAttachedObject, Player *pPlayer, BulletManager *pBulletManager, sf::Vector2i pPositionalOffset) : GameObject(pTextureLocation, pRows, pColumns)
{
	attachedObject = pAttachedObject;
	player = pPlayer;
	bulletManager = pBulletManager;
	positionalOffset = pPositionalOffset;
}

void Gun::Update(float pFrameTime)
{
	//give the bullet manager the correct position of the gun to spawn bullets from
	bulletManager->SetGunPosition(player->GetPlayerIdentifier(), getPosition() + GetCentrePoint());
	
	//have the gun stick to the player model
	FollowAt(attachedObject, positionalOffset.x, positionalOffset.y, true);

	controlAnimation();
}

void Gun::controlAnimation()
{
	switch (player->GetPlayerState())
	{
		//LEFT
	case 0:
	case 4:
		SetFrame(3);
		break;
		//RIGHT
	case 1:
	case 5:
		SetFrame(2);
		break;
		//SOUTH
	case 2:
	case 6:
		if (player->IsFacingRight())
		{
			SetFrame(0);
		}
		else
		{
			SetFrame(5);
		}
		break;
		//NORTH
	case 3:
	case 7:
		if (player->IsFacingRight())
		{
			SetFrame(1);
		}
		else
		{
			SetFrame(4);
		}
		break;
		//DEFAULT
	default:

		break;
	}
}