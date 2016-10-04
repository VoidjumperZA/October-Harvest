#include "Level.hpp"
#include <iostream>

using namespace std;

void DrawOnWindow(GameObject *pGameObject);

Level::Level()
{
	
}

//create a new layer and add it to our list of layers in the level
//while (by default) toggling it to true
void Level::CreateNewLayer() //define a map for layer names later
{
	vector<GameObject*> *newLayer = new vector<GameObject*>();
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
void Level::AddToLayer(GameObject *pGameObject, int pLayerNumber)
{
	layers[pLayerNumber].push_back(pGameObject);
}

///
///<summary>brief enable or disable a layer</summary>
///
void Level::ToggleLayer(int pLayerNumber, bool pStatus)
{
	layerStatus[pLayerNumber] = pStatus;
	cout << endl << "LAYER STATUS" << endl;
	for (size_t i = 0; i < layers.size(); i++)
	{
		cout << "Layer: " << i << ":\t" << layerStatus[i] << endl;
	}
}

void Level::UpdateLevel()
{
	//
	//       NOTE: this actually updates our game objects
	//			   the displaying is done in the second part
	//

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
				layers[i][j]->Update();
			}
		}
	}

	//
	//       NOTE: this part DISPLAYS our objects. 
	//			   we want to display them, even if they're not updating
	//

	//go through each of our level's layers
	for (size_t i = 0; i < layers.size(); i++)
	{
		//cout << "Layer " << i << "is " << layerStatus[i] << endl;
		//update every gameobject in that layer
		for (size_t j = 0; j < layers[i].size(); j++)
		{
			DrawOnWindow(layers[i][j]);
		}
	}
}