#ifndef GHOST_HEADER
#define GHOST_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Enemy.hpp"

using namespace std;
class Ghost : public Enemy
{
public:
	Ghost(Level *pLevel, string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
	void OnCollision(GameObject *pTargetObject) override;
private:
	int counter;
	int explosionCounter;
	float speedX;
	float speedY;
	float const ACCELERATION_CONTROL = 0.001f;
	int targetSpeedX;
	int targetSpeedY;

	bool explosionCreated;

	Level *level;
	Explosion *explosion;
	void moveAndAnimate();
};
#endif
