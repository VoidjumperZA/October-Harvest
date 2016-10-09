#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "GameObject.hpp"
using namespace std;
class Player : public GameObject
{
public:
	Player(string pTextureLocation, int pRows, int pColumns, int pPlayerIndentifier);
	void Update(float pFrameTime) override;
	void OnCollision(GameObject *pTargetObject) override;
	void Translate(float pXTranslation, float pYTranslation) override;
private:
	int playerIndentifier;
	float horizontalInertia;
	float maxHInertia;
	float horizontalAcceleration;
	float horizontalDeceleration;
	float verticalInertia;
	float maxVInertia;
	float verticalAcceleration;
	float verticalDeceleration;
	sf::Keyboard::Key *forward;
	sf::Keyboard::Key *backward;
	sf::Keyboard::Key *left;
	sf::Keyboard::Key *right;
	sf::Keyboard::Key *interact;
	sf::Keyboard::Key *altinteract;
	void checkForInput();
	void inputToMovement(float &pInertiaAxis, float &pAccelerationAxis, float &pMaxInertia, int pPolarity);
	void applyInertia(float &pInertiaAxis, float &pDecelerationAxis);
	void movement(float pHSpeed, float pVSpeed);
};
#endif