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

void GameObject::OnCollision()
{

}

void GameObject::Destroy()
{

}