#ifndef SCENE_HEADER
#define SCENE_HEADER

#include <SFML/Graphics.hpp>

using namespace std;
class Scene
{
public:
	Scene();
	virtual void SceneUpdate(float pFrameTime);
	virtual void SceneRender();
private:

};
#endif