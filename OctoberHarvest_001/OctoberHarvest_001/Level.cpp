#include "Level.hpp"
#include <iostream>

using namespace std;

Level::Level(sf::RenderWindow *pWindow)
{
	gameWindow = pWindow;
}

//create a new layer and add it to our list of layers in the level
//while (by default) toggling it to true
void Level::CreateNewLayer() //define a map for layer names later
{
	vector<GameObject> *newLayer = new vector<GameObject>();
	layers.push_back(*newLayer);
	ToggleLayer(layers.size() - 1, true);
}

//get the number of layers present in a level
size_t Level::GetNumberOfLayers()
{
	return layers.size();
}

//get the number of layers present in a level
bool Level::GetLayerStatus(int pLayerNumber)
{
	return layerStatus[pLayerNumber];
}

//add a gameobject to a layer in the level
void Level::AddToLayer(GameObject pGameObject, int pLayerNumber)
{
	layers[pLayerNumber].push_back(pGameObject);
}

//enable or disable a layer
void Level::ToggleLayer(int pLayerNumber, bool pStatus)
{
	layerStatus[pLayerNumber] = pStatus;
}

void Level::UpdateLevel()
{
	//go through each of our level's layers
	for (size_t i = 0; i < layers.size(); i++)
	{
		//check to see if that layer is enabled
		if (layerStatus[i] == true)
		{
			//cout << "Layer " << i << "is " << layerStatus[i] << endl;
			//update every gameobject in that layer
			for (size_t j = 0; j < layers[i].size(); j++)
			{
				layers[i][j].Update();
				gameWindow->draw(layers[i][j]);
			}
		}
		
	}
}