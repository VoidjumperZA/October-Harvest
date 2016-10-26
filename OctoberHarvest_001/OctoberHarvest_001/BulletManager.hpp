#ifndef BULLETMANAGER_HEADER
#define BULLETMANAGER_HEADER

#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "Bullet.hpp"

using namespace std;
class BulletManager 
{
public:
	BulletManager(Level *pLevel);
	void AddBullet(int pPlayerState, int pPlayerID, bool pFacingRight, int pLayer);
	void SetGunPosition(int pPlayerID, sf::Vector2f pPosition);
private:
	Level *level;
	sf::Vector2f bulletVelocity;
	sf::Vector2f gunPos_001;
	sf::Vector2f gunPos_002;
	sf::Vector2f activeGunPos;
};
#endif
