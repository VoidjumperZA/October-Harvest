#include <SFML/Graphics.hpp>
#include "GameScene.hpp"
#include "Level.hpp"
#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

sf::RenderWindow *gameWindow;

int main()
{
	//create a new game window
	gameWindow = new sf::RenderWindow(sf::VideoMode(1600, 900), "October Harvest");

	Scene *holderScene = new Scene();
	GameScene *gameScene = new GameScene();

	holderScene = gameScene;

	//while our game window is open, clear and display every frame
	while (gameWindow->isOpen())
	{
		gameWindow->clear();
		gameScene->SceneRefresh();

		//check if a close event is happening, if it is, close the window
		sf::Event event;
		while (gameWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow->close();
			}
		}

		gameWindow->display();
	}

	return 0;
}

void DrawOnWindow(GameObject *pGameObject)
{
	gameWindow->draw(*pGameObject);
}