#ifndef AMMOPACK_HEADER
#define AMMOPACK_HEADER

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

using namespace std;
class AmmoPack : public GameObject
{
public:
	AmmoPack(string pTextureLocation, int pRows, int pColumns);
	void Update(float pFrameTime) override;
private:
};
#endif
