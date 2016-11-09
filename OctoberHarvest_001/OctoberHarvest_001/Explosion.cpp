#include "Explosion.hpp"
#include <iostream>

Explosion::Explosion(string pTextureLocation, int pRows, int pColumns) : GameObject(pTextureLocation, pRows, pColumns)
{

}

void Explosion::Update(float pFrameTime)
{
	Animate(0, 1, 75);
}