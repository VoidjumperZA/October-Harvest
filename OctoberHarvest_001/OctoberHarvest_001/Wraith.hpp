#ifndef WRAITH_HEADER
#define WRAITH_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Enemy.hpp"

using namespace std;
class Wraith : public Enemy
{
public:
	Wraith(Level *pLevel, string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
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

	void moveAndAnimate();
};
#endif
