#include "GameObject.hpp"
#include <iostream>

using namespace std;

GameObject::GameObject(string pTextureLocation, int pRows, int pColumns) : AnimatedSprite(pTextureLocation, pRows, pColumns)
{
	count = 0;

}


void GameObject::Update()
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