#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Level.hpp"
#include "BulletManager.hpp"
#include "Player.hpp"
#include "Gun.hpp"
using namespace std;
class GameScene : public Scene
{
public:
	GameScene();
	void SceneUpdate(float pFrameTime) override;
	void SceneCollisionCheck() override;
	void SceneRender() override;
	void DeleteAllObjects() override;
private:
	int *worldGrid[16][9];
	Level *level;
	BulletManager *bulletManager;
	Player *player_001;
	Player *player_002;
	Gun *player_001_gun;
	Gun *player_002_gun;
	GameObject *player_001_animSprite;
	GameObject *player_002_animSprite;
};
#endif

