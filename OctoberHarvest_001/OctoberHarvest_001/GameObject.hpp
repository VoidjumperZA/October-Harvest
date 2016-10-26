#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
using namespace std;

class GameObject : public AnimatedSprite
{
public: 
	GameObject(string pTextureLocation, int pRows, int pColumns);
	virtual void Update(float pFrameTime);
    virtual void OnCollision(GameObject *pTargetObject);
	//virtual void CheckCollisions();
    virtual void Destroy();
    void FollowAt(GameObject *pTargetObject, int pXOffset, int pYOffset, bool pMimicRotation);
	virtual void AddToLevel(GameObject *pChildObject);
	virtual void Translate(float pXTranslation, float pYTranslation);
	virtual int GetPlayerIdentifier();
	void Delete();
private:
	int count;
};

#endif