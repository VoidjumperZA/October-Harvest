#ifndef ANIMATEDSPRITE_HEADER
#define ANIMATEDSPRITE_HEADER

#include <SFML/Graphics.hpp>
using namespace std;
class AnimatedSprite : public sf::Sprite
{
public:
	AnimatedSprite(string pTextureLocation, int pRows, int pColumns); 
    void Animate(int beginRow, int beginCol, int endRow, int endCol, int timeMili);
	void Animate(int beginIndex, int endIndex, int timeMili);
	void StopAnimation();
private:
	int rows;
	int columns;
	int frameHeight;
	int frameWidth;
	int counter;
	bool isAnimating;
	string textureLocation;
	sf::Vector2u imageSize;
	sf::Vector2u *frames;
	sf::Clock *clock = new sf::Clock;
	int numberOfFrames;
	void internalAnimation(int beginIndex, int endIndex, int timeMili);
	void setUpImage();
	void startAnimation();
	void endAnimation();
};

#endif