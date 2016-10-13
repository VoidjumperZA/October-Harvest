#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Level.hpp"
#include "Player.hpp"
using namespace std;
class GameScene : public Scene
{
public:
	GameScene();
	void SceneUpdate(float pFrameTime) override;
	void SceneCollisionCheck() override;
	void SceneRender() override;
private:
	int *worldGrid[16][9];
	Level *level;
	Player *player_001;
	Player *player_002;
};
#endif

