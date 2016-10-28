#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

using namespace std;
class Enemy : public GameObject
{
public:
	Enemy(string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
private:
};
#endif
