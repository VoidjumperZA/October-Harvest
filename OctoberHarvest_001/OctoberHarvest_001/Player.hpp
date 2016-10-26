#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Level.hpp"
#include "GameObject.hpp"
#include "BulletManager.hpp"
using namespace std;
class Player : public GameObject
{
public:
	Player(GameObject *pAnimSprite, string pHitBoxTextureLocation, int pHitBoxRows, int pHitBoxColumns, BulletManager *pBulletManager, int pPlayerIndentifier);
	void Update(float pFrameTime) override;
	void OnCollision(GameObject *pTargetObject) override;
	void Translate(float pXTranslation, float pYTranslation) override;
	int GetPlayerIdentifier() override;
    int GetPlayerState();
	bool IsFacingRight();
private:
    int playerIdentifier;

	int const MAGAZINE_SIZE = 8.0f;
	int currentAmmoInMag;
	int const MAX_TOTAL_AMMO = 64.0f;
	int totalAmmo;

	float horizontalInertia;
    float const MAX_H_INERTIA = 700.0f;
	float const HORIZONTAL_ACCELERATION = 3.0f;
	float const HORIZONTAL_DECELERATION = 2.0f;

	float verticalInertia;
	float const MAX_V_INERTIA = 700.0f;
	float const VERTICAL_ACCELERATION = 3.0f;
	float const VERTICAL_DECELERATION = 2.0f;

	float const TIME_BETWEEN_SHOTS = 500.0f;

	sf::Clock *clock = new sf::Clock();

	sf::Vector2f oldPosition;

	sf::Keyboard::Key *north;
	sf::Keyboard::Key *south;
	sf::Keyboard::Key *left;
	sf::Keyboard::Key *right;
	sf::Keyboard::Key *fire;
	sf::Keyboard::Key *reloadAction;
	sf::Keyboard::Key *interact;
	sf::Keyboard::Key *altinteract;

	sf::SoundBuffer *reloadSoundBuffer = new sf::SoundBuffer();
	sf::Sound *reloadSound = new sf::Sound();

	bool fireAxisLock;
	bool chamberingRoundLock;
	bool reloadLock;
	bool reloadIndividualRoundLock;
	bool facingRight;

	enum State {WalkingLeft, WalkingRight, WalkingSouth, WalkingNorth, IdlingLeft, IdlingRight, IdlingSouth, IdlingNorth, HitLeft, HitRight};
	State playerState;
	State previousPlayerState;

	AnimatedSprite *animatedGraphics;
	BulletManager *bulletManager;

	void checkForInput();
	void controlAnimation();
	void inputToMovement(float &pInertiaAxis, float const &pAccelerationAxis, float const &pMaxInertia, int pPolarity);
	void applyInertia(float &pInertiaAxis, float const &pDecelerationAxis);
	void movement(float pHSpeed, float pVSpeed);
	void reload();

	int invert(int pOther);
	void recordOldPosition();
	void reflectInertia(float pScalar);
	void switchStates(State pState);
	void walkToIdle();
	void setUpSound();
};
#endif