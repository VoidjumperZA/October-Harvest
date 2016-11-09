#ifndef EXPLOSION_HEADER
#define EXPLOSION_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Enemy.hpp"

using namespace std;
class Explosion : public GameObject
{
public:
	Explosion(string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
private:
	int counter;
};
#endif
