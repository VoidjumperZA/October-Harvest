#include "Level.hpp"
#include <iostream>
//#define DEBUG_VOID

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

//add a gameobject to a spesified layer in the level as well
//as automatically add it to the single collision layer
void Level::AddToLayer(GameObject *pGameObject, int pLayerNumber, bool pCollidable)
{
	layers[pLayerNumber].push_back(pGameObject);
	if (pCollidable == true)
	{
		collisionVec.push_back(pGameObject);
	}
}

///
///<summary>brief enable or disable a layer</summary>
///
void Level::ToggleLayer(int pLayerNumber, bool pStatus)
{
	layerStatus[pLayerNumber] = pStatus;
#ifdef DEBUG_VOID
	cout << endl << "LAYER STATUS" << endl;
	for (size_t i = 0; i < layers.size(); i++)
	{
		cout << "Layer: " << i << ":\t" << layerStatus[i] << endl;
	}
#endif
}

void Level::UpdateLevel(float pFrameTime)
{
	//go through each of our level's layers
	for (size_t i = 0; i < layers.size(); i++)
	{
		//check to see if that layer is enabled
		if (layerStatus[i] == true)
		{
			//update every gameobject in that layer
			for (size_t j = 0; j < layers[i].size(); j++)
			{
				layers[i][j]->Update(pFrameTime);
			}
		}
	}
}

void Level::CollisionCheckLevel()
{
	for (size_t i = 0; i < collisionVec.size(); i++)
	{
		for (size_t j = 0; j < collisionVec.size(); j++)
		{
			sf::Rect<int> rect1 = collisionVec[i]->getTextureRect();
			sf::Rect<int> rect2 = collisionVec[j]->getTextureRect();
			if(collisionVec[i]->getGlobalBounds().intersects(collisionVec[j]->getGlobalBounds()) && collisionVec[i] != collisionVec[j])
			{
#ifdef DEBUG_VOID
				cout << "Player " << collisionVec[i]->GetPlayerIdentifier() << "'s global bounds are: [" << collisionVec[i]->getGlobalBounds().left << ", " << collisionVec[i]->getGlobalBounds().top << ", " << collisionVec[i]->getGlobalBounds().height << ", " << collisionVec[i]->getGlobalBounds().width << "] while Player " << collisionVec[j]->GetPlayerIdentifier() << "'s are: [" << collisionVec[j]->getGlobalBounds().left << ", " << collisionVec[j]->getGlobalBounds().top << ", " << collisionVec[j]->getGlobalBounds().height << ", " << collisionVec[j]->getGlobalBounds().width << "]" << endl;
#endif
				collisionVec[i]->OnCollision(collisionVec[j]);
			}
		}
	}
}

void Level::RenderLevel()
{
	for (size_t i = 0; i < layers.size(); i++)
	{
		//render every gameobject in that layer
		for (size_t j = 0; j < layers[i].size(); j++)
		{
			DrawOnWindow(layers[i][j]);
		}
	}
}

void Level::DeleteLevel()
{
	//switch everything off, so there's no dependencies
	for (size_t i = 0; i < layers.size(); i++)
	{
		ToggleLayer(i, false);
	}
	//go through again and delete it all
	for (size_t i = 0; i < layers.size(); i++)
	{
		//delete every gameobject in that layer
		for (size_t j = 0; j < layers[i].size(); j++)
		{
			layers[i][j]->Delete();
		}
	}

	delete this;
}

//move an entire layer across the screen
void Level::TranslateLayer(int pLayerNumber, float pXTranslation, float pYTranslation)
{
	//go through each of our level's layers
	if (layerStatus[pLayerNumber] == true)
	{
		//move every gameobject in that layer
		for (size_t i = 0; i < layers[pLayerNumber].size(); i++)
		{
			layers[pLayerNumber][i]->Translate(pXTranslation, pYTranslation);
		}
	}
}