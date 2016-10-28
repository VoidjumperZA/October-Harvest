#ifndef WRAITH_HEADER
#define WRAITH_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Enemy.hpp"

using namespace std;
class Wraith : public Enemy
{
public:
	Wraith(string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
private:
};
#endif
