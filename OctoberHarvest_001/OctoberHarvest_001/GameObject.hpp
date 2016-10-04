#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
using namespace std;

class GameObject : public AnimatedSprite
{
public: 
	GameObject(string pTextureLocation, int pRows, int pColumns);
	virtual void Update();
	virtual void OnCollision();
    void Destroy();
private:
	int count;
};

#endif