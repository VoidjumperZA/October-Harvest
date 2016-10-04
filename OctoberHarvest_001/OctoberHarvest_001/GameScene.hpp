#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "Player.hpp"
using namespace std;
class GameScene
{
public:
	GameScene();
	void SceneRefresh();
private:
	Level *level;
	Player *player_001;
	Player *player_002;
};
#endif

