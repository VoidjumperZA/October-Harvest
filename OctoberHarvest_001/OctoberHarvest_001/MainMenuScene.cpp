#include "MainMenuScene.hpp"
#include <iostream>

using namespace std;

MainMenuScene::MainMenuScene() : Scene()
{

}

void MainMenuScene::SceneUpdate(float pFrameTime)
{
	cout << "This is MainMenuScene SceneRefresh" << endl;
}

void MainMenuScene::SceneCollisionCheck()
{
	cout << "This is MainMenuScene SceneCollisionCheck" << endl;
}

void MainMenuScene::SceneRender()
{
	cout << "This is MainMenuScene SceneRender" << endl;
}