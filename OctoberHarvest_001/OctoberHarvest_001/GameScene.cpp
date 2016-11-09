#include "GameScene.hpp"
#include <iostream>

using namespace std;

GameScene::GameScene() : Scene()
{
	level = new Level();
	bulletManager = new BulletManager(level);

	player_001_animSprite = new GameObject("Assets/Sprites/Anim/Final/PumpkinHead_FullSheet.png", 2, 30);
	player_001 = new Player(player_001_animSprite, "Assets/Sprites/Anim/Final/PumpkinHead_HitBox.png", 1, 1, bulletManager, 0);
	player_001->setPosition(500, 500);

	player_002_animSprite = new GameObject("Assets/Sprites/Anim/Final/PumpkinHead_FullSheet.png", 2, 30);
	player_002 = new Player(player_002_animSprite, "Assets/Sprites/Anim/Final/PumpkinHead_HitBox.png", 1, 1, bulletManager, 1);
	player_002->setPosition(900, 500);

	player_001_gun = new Gun("Assets/Sprites/Anim/Final/Gun_Fullsheet.png", 1, 6, player_001_animSprite, player_001, bulletManager, sf::Vector2i(0, 0));
	player_002_gun = new Gun("Assets/Sprites/Anim/Final/Gun_FullSheet.png", 1, 6, player_002_animSprite, player_002, bulletManager, sf::Vector2i(0, 0));

	testGhost = new Ghost(level, "Assets/Sprites/Anim/Final/Ghost_FullSheet.png", 2, 3);
	testGhost->setPosition(600, 600);

	testWraith = new Wraith(level, "Assets/Sprites/Anim/Final/Wraith_FullSheet.png", 2, 3);
	testWraith->setPosition(1000, 800);

	ammoPack = new AmmoPack("Assets/Sprites/Anim/Final/AmmoPack_FullSheet.png", 1, 1);
	ammoPack->setPosition(200, 200);

	level->CreateNewLayer();
	level->AddToLayer(player_001, 0, true);
	level->AddToLayer(player_002, 0, true);
	level->CreateNewLayer();
	level->AddToLayer(player_001_animSprite, 0, false);
	level->AddToLayer(player_002_animSprite, 0, false);
	level->AddToLayer(player_001_gun, 0, false);
	level->AddToLayer(player_002_gun, 0, false);
	level->AddToLayer(testGhost, 0, true);
	level->AddToLayer(testWraith, 0, true);
	level->AddToLayer(ammoPack, 0, true);
		
}

void GameScene::SceneUpdate(float pFrameTime)
{
	//this feels dirty
	level->UpdateLevel(pFrameTime);
	player_001_animSprite->FollowAt(player_001, -(int)player_001_animSprite->GetCentrePoint().x / 2, 0, false);
	player_002_animSprite->FollowAt(player_002, -(int)player_002_animSprite->GetCentrePoint().x / 2, 0, false);
}

void GameScene::SceneCollisionCheck()
{
	level->CollisionCheckLevel();
}

void GameScene::SceneRender()
{
	level->RenderLevel();
}

void GameScene::DeleteAllObjects()
{
	delete bulletManager;
	level->DeleteLevel();
}

/*	*/