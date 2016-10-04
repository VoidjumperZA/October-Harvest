#include "GameObject.hpp"
#include <iostream>

using namespace std;

GameObject::GameObject(sf::Texture pTexture, int pRows, int pColumns) : AnimatedSprite(pTexture, pRows, pColumns)
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