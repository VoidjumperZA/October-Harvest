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
	if (getGlobalBounds().intersects(pTargetObject->getGlobalBounds()))
	{
		cout << "Collision Occured" << endl;
	}
}

void GameObject::Destroy()
{

}

void GameObject::AddToLevel(GameObject *pChildObject)
{

}

void GameObject::Translate(float pXTranslation, float pYTranslation)
{
	move(pXTranslation, pYTranslation);
}