#ifndef BULLET_HEADER
#define BULLET_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace std;
class Bullet : public GameObject
{
public:
	Bullet(string pTextureLocation, int pRows, int pColumns, sf::Vector2f pStartingVelocity);
	void Update(float pFrameTime) override;
private:
	int frameSwitcher;
	sf::Vector2f inputVelocity;
};
#endif
