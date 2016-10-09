#include "GameScene.hpp"
#include <iostream>

using namespace std;

GameScene::GameScene() : Scene()
{
	level = new Level();

	player_001 = new Player("Assets/Sprites/testNumbers.png", 3, 3, 0);
	player_001->setPosition(500, 500);

	player_002 = new Player("Assets/Sprites/testColours.png", 2, 2, 1);
	player_002->setPosition(900, 500);

	level->CreateNewLayer();
	level->AddToLayer(player_001, 0);
	level->CreateNewLayer();
	level->AddToLayer(player_002, 1);

}

void GameScene::SceneUpdate(float pFrameTime)
{
	level->UpdateLevel(pFrameTime);
	player_001->OnCollision(player_002);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		level->ToggleLayer(0, false);
	}
}

void GameScene::SceneRender()
{
	level->RenderLevel();
}

/*	*/