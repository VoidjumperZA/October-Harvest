#include "GameObject.hpp"
#include <iostream>

using namespace std;

GameObject::GameObject(string pTextureLocation, int pRows, int pColumns) : AnimatedSprite(pTextureLocation, pRows, pColumns)
{
	count = 0;
}


void GameObject::Update(float pFrameTime)
{
	
}

void GameObject::OnCollision(GameObject *pTargetObject)
{

}

void GameObject::Destroy()
{

}

void GameObject::FollowAt(GameObject *pTargetObject, int pXOffset, int pYOffset, bool pMimicRotation)
{
	setPosition(pTargetObject->getPosition().x + pXOffset, pTargetObject->getPosition().y + pYOffset);
	if (pMimicRotation == true)
	{
		setRotation(pTargetObject->getRotation());
	}
}

void GameObject::AddToLevel(GameObject *pChildObject)
{

}

int GameObject::GetPlayerIdentifier()
{
	return 999;
}

void GameObject::Translate(float pXTranslation, float pYTranslation)
{
	move(pXTranslation, pYTranslation);
}

void GameObject::DeleteGameObject()
{
	delete this;
}