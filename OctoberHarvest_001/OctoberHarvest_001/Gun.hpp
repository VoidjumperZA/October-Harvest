#ifndef GUN_HEADER
#define GUN_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
#include "BulletManager.hpp"
using namespace std;
class Gun : public GameObject
{
public:
	Gun(string pTextureLocation, int pRows, int pColumns, GameObject *pAttachedObject, Player *pPlayer, BulletManager *pBulletManager, sf::Vector2i pPositionalOffset);
	void Update(float pFrameTime) override;
private:
	Player *player;
	GameObject *attachedObject;
	BulletManager *bulletManager;
	sf::Vector2i positionalOffset;
	void controlAnimation();
};
#endif
