#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace std;
class Player : public GameObject
{
public:
	Player(string pTextureLocation, int pRows, int pColumns);
private:
};
#endif