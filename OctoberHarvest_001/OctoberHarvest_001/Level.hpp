#ifndef LEVEL_HEADER
#define LEVEL_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
using namespace std;
class Level 
{
public:
	Level();
	void CreateNewLayer();
	size_t GetNumberOfLayers();
	void AddToLayer(GameObject *pGameObject, int pLayerNumber, bool pCollidable);
	void ToggleLayer(int pLayerNumber, bool pStatus);
	bool GetLayerStatus(int pLayerNumber);
	void UpdateLevel(float pFrameTime);
	void CollisionCheckLevel();
	void RenderLevel();
	void DeleteLevel();
	void TranslateLayer(int pLayerNumber, float pXTranslation, float pYTranslation);
private:
	//vector<vector<GameObject>> *layers = new vector<vector<GameObject>>();
	vector<vector<GameObject*>> layers;
	vector<GameObject*> collisionVec;
	map<int, bool> layerStatus;
	sf::RenderWindow *gameWindow;
};
#endif
