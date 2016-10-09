#include "AnimatedSprite.hpp"
#include <iostream>

using namespace std;

AnimatedSprite::AnimatedSprite(string pTextureLocation, int pRows, int pColumns) : sf::Sprite()
{
	//intialisation
	counter = 0;
	isAnimating = false;
	rows = pRows;
	columns = pColumns;
	textureLocation = pTextureLocation;

	//loads the texture, sets up the frame array, the
	//right sizes and any other initialisation work
	setUpImage();
}

//animate the sprite if want to use precise column/row co-ordinates
void AnimatedSprite::Animate(int beginRow, int beginCol, int endRow, int endCol, int timeMili)
{
	//work out our begining and end indexes based on
	//the columns and rows we were give to work with
	int beginIndex = (rows * beginRow) + beginCol;
	int endIndex = (rows * endRow) + endCol;

	//once we've got these initial values, plug them into our internal animation
	internalAnimation(beginIndex, endIndex, timeMili);
}

//animate the sprite if you know the exact indexes of where you want to start and end
void AnimatedSprite::Animate(int beginIndex, int endIndex, int timeMili)
{
	//since our internal animation is based off this method, we can
	//just go ahead and use the values verbatim
	internalAnimation(beginIndex, endIndex, timeMili);
}

//since our actual animation is basically the same, we use our overloaded Animate
//methods to work out some initial values and then just plug them into the same
//internal animation method
void AnimatedSprite::internalAnimation(int beginIndex, int endIndex, int timeMili)
{
	//resets the boolean and the clock
	if (isAnimating == false)
	{
		startAnimation();
	}
	else
	{
		//clock moderates animation speed
		sf::Time &elapsedTime = clock->getElapsedTime();

		//once it's time to animate the next frame
		if (elapsedTime.asMilliseconds() >= timeMili)
		{
			//set the area of the texture the sprite is displaying and restart our clock
			setTextureRect(sf::IntRect(frames[beginIndex + counter].x, frames[beginIndex + counter].y, frameWidth, frameHeight));
			clock->restart();

			//for debugging the right frames are being set
			/*cout << "x: " << frames[beginIndex + counter].x << endl << "y: " << frames[beginIndex + counter].y << endl << endl;
			cout << "beginIndex + counter: " << frames[beginIndex].x << endl;
			cout << beginIndex + counter << endl;*/

			//used to cycle through the right frames needs to
			//be reset once it's reached the end of the block
			//of frames we want to display
			counter++;
			if (counter > endIndex - beginIndex)
			{
				counter = 0;
			}
		}
	}
}

void AnimatedSprite::StopAnimation()
{

}

void AnimatedSprite::setUpImage()
{
	//loads the correct texture
	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile(textureLocation);
	cout << (texture->loadFromFile(textureLocation)) << endl;
	setTexture(*texture);

	//get's the image's size
	imageSize = texture->getSize();

	//the pixel width and height of one frame in our image
	frameHeight = imageSize.x / rows;
	frameWidth = imageSize.y / columns;

	//create an array with the number of frames we have
	numberOfFrames = rows * columns;
	frames = new sf::Vector2u[numberOfFrames];

	//used for spacing out across our number of rows
	int rowIncrementor = 0;
	int columnIncrementor = 0;

	//save each frame as a vector2 of pixel co-ordinates
	//so we can tell where to put our rect
	for (int i = 0; i < numberOfFrames; i++)
	{
		frames[i].x = frameWidth * (columnIncrementor);
		frames[i].y = frameHeight * (rowIncrementor);

		//increment our column every loop while wrapping back
		//around to zero after the number of columns and update
		//our rows once we've finished a line of columns
		columnIncrementor++;
		if (columnIncrementor > columns - 1)
		{
			columnIncrementor = 0;
			rowIncrementor++;
		}		
	}

	//set the first frame, just so the whole texture is not displayed
	setTextureRect(sf::IntRect(frames[0].x, frames[0].y, frameWidth, frameHeight));

	//just to debug the values have been set correctly
	/*
	for (int k = 0; k < numberOfFrames; k++)
	{
		cout << "frame " << k << "'s x is set to: " << frames[k].x << endl;
		cout << "frame " << k << "'s y is set to: " << frames[k].y << endl;
		if (k % 2 == 0)
		{
			cout << endl;
		}
	}*/
}

void AnimatedSprite::startAnimation()
{
	clock->restart();
	isAnimating = true;
}

void AnimatedSprite::endAnimation()
{
	isAnimating = false;
}



