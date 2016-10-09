#ifndef MAINMENUSCENE_HEADER
#define MAINMENUSCENE_HEADER

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
using namespace std;
class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void SceneUpdate(float pFrameTime) override;
	void SceneRender() override;
private:
};
#endif