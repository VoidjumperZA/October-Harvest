#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Explosion.hpp"

using namespace std;
class Enemy : public GameObject
{
public:
	Enemy(Level *pLevel, string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
private:
	sf::Vector2f oldPosition;
	Level *level;
	void recordOldPosition();
};
#endif
