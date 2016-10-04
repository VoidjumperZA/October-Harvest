#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace std;
class Player : public GameObject
{
public:
	Player(string pTextureLocation, int pRows, int pColumns, int pPlayerIndentifier);
	void Update() override;
	void OnCollision(GameObject *pTargetObject) override;
private:
	int playerIndentifier;
	sf::Keyboard::Key *forward;
	sf::Keyboard::Key *backward;
	sf::Keyboard::Key *left;
	sf::Keyboard::Key *right;
	sf::Keyboard::Key *interact;
	sf::Keyboard::Key *altinteract;
	void checkForInput();
	void movement();
};
#endif