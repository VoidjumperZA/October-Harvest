#include <SFML/Graphics.hpp>
#include "GameScene.hpp"
#include "MainMenuScene.hpp"
#include "Level.hpp"
#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

void SwitchScenes(Scene *pScene);
void DeleteScene(Scene *pScene);
void DeleteAllScenes();

Scene *holderScene = new Scene();
GameScene *gameScene = new GameScene();
MainMenuScene *mainMenuScene = new MainMenuScene();

vector<Scene*> sceneList;
sf::RenderWindow *gameWindow;
sf::Clock *gameClock = new sf::Clock;
float frameTime = 1.0f / 240.0f;
float timer = 0.0f;

int main()
{
	//create a new game window
	gameWindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "October Harvest");

	sceneList.push_back(holderScene); 
	sceneList.push_back(gameScene);
	sceneList.push_back(mainMenuScene);

	SwitchScenes(gameScene);

	//while our game window is open, clear and display every frame
	while (gameWindow->isOpen())
	{
		timer += gameClock->getElapsedTime().asSeconds();
		gameClock->restart();

		bool updatedOnce = false;
		while (timer > frameTime)
		{
			updatedOnce = true;
			timer -= frameTime;			
			holderScene->SceneUpdate(frameTime);	
			holderScene->SceneCollisionCheck();
		}
		if (updatedOnce)
		{			
			gameWindow->clear(sf::Color(9, 21, 22)); //237 237 237  - 13 33 33 - 12 28 30
			holderScene->SceneRender();
			gameWindow->display();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			SwitchScenes(gameScene);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			SwitchScenes(mainMenuScene);
		}

		//check if a close event is happening, if it is, close the window
		sf::Event event;
		while (gameWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow->close();
			}
		}	
	}
	
	DeleteAllScenes();

	return 0;
}

void SwitchScenes(Scene *pScene)
{
	holderScene = pScene;
}

void DeleteScene(Scene *pScene)
{
	pScene->DeleteAllObjects();
	delete pScene;
}

void DeleteAllScenes()
{
	for (size_t i = 0; i < sceneList.size(); i++)
	{
		sceneList[i]->DeleteAllObjects();
		delete sceneList[i];
	}
}
void DrawOnWindow(GameObject *pGameObject)
{
	gameWindow->draw(*pGameObject);
}