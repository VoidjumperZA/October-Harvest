#include <SFML/Graphics.hpp>
#include "GameScene.hpp"
#include "MainMenuScene.hpp"
#include "Level.hpp"
#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

sf::RenderWindow *gameWindow;
sf::Clock *gameClock = new sf::Clock;
float frameTime = 1.0f / 240.0f;
float timer = 0.0f;

int main()
{
	//create a new game window
	gameWindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "October Harvest");

	Scene *holderScene = new Scene();
	GameScene *gameScene = new GameScene();
	MainMenuScene *mainMenuScene = new MainMenuScene();

	holderScene = gameScene;

	//while our game window is open, clear and display every frame
	while (gameWindow->isOpen())
	{
		timer += gameClock->getElapsedTime().asSeconds();
		gameClock->restart();
		//sf::Time &elapsedTime = gameClock->getElapsedTime();
		//
		bool updatedOnce = false;
		while (timer > frameTime)
		{
			updatedOnce = true;
			timer -= frameTime;			
			holderScene->SceneUpdate(frameTime);			
		}
		if (updatedOnce)
		{
			gameWindow->clear(sf::Color(237, 237, 237));
			holderScene->SceneRender();
			gameWindow->display();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			holderScene = gameScene;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			holderScene = mainMenuScene;
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
	
	delete mainMenuScene;
	delete gameScene;
	delete gameWindow;

	return 0;
}

void DrawOnWindow(GameObject *pGameObject)
{
	gameWindow->draw(*pGameObject);
}