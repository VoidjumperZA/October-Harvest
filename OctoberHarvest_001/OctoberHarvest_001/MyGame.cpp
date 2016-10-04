#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include <iostream>
using namespace std;

int main()
{
	//create a new game window
	sf::RenderWindow gameWindow(sf::VideoMode(1600, 900), "Harpoon Tom");

	Level *level = new Level(&gameWindow);

	
	//AnimatedSprite *animSprite = new AnimatedSprite(*texture, 3, 3);
	//animSprite->setPosition(500, 500);

	GameObject *gameObject = new GameObject("Assets/Sprites/testNumbers.png", 3, 3);
	gameObject->setPosition(500, 500);

	level->CreateNewLayer();
	level->AddToLayer(*gameObject, 0);

	/*level->CreateNewLayer();
	level->AddToLayer(*gameObject, 0);3*/	

	//while our game window is open, clear and display every frame
	while (gameWindow.isOpen())
	{
		gameWindow.clear();
		level->UpdateLevel();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			level->ToggleLayer(0, false);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			level->ToggleLayer(0, true);
		}
		//animSprite->Animate(2, 5, 1000);
		//check if a close event is happening, if it is, close the window
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}

		//gameWindow.draw(*gameObject);
		gameWindow.display();
	}

	return 0;
}