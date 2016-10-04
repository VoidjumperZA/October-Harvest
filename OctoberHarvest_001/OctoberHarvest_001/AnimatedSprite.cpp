#include "AnimatedSprite.hpp"
#include <iostream>

using namespace std;

AnimatedSprite::AnimatedSprite(string pTextureLocation, int pRows, int pColumns) : sf::Sprite()
{
	counter = 0;
	isAnimating = false;
	//rows and columns
	rows = pRows;
	columns = pColumns;

	sf::Texture *texture = new sf::Texture();
	texture->loadFromFile(pTextureLocation);
	cout << (texture->loadFromFile(pTextureLocation)) << endl;
	setTexture(*texture);
	
	imageSize = texture->getSize();

	//the pixel width and height of one frame in our image
	frameHeight = imageSize.x / rows;
	frameWidth = imageSize.y / columns;

	numberOfFrames = pRows * pColumns;
	frames = new sf::Vector2u[numberOfFrames];

	setUpImage();
	//setTextureRect(sf::IntRect(0, 0, 60, 60));
}

//animate the sprite if want to use precise column/row co-ordinates
void AnimatedSprite::Animate(int beginRow, int endRow, int beginCol, int endCol, int timeMili)
{
	//
	//                             NOTICE
	//
	//this is to be fixed later, work out index via the column/row number and subsitute
	//that into our current method. But we have a way that works, this is just to be fancy.
	//Fancy can come when the game is done.
	
	/*
	if (isAnimating == false)
	{
		startAnimation();
	}
	else
	{
		sf::Time &elapsedTime = clock->getElapsedTime();
		if (elapsedTime.asMilliseconds() >= timeMili)
		{
			setTextureRect(sf::IntRect(frames[beginIndex + counter].x, frames[beginIndex + counter].y, frameWidth, frameHeight));
			clock->restart();

			//cout << "x: " << frames[beginIndex + counter].x << endl << "y: " << frames[beginIndex + counter].y << endl << endl;
			//cout << "beginIndex + counter: " << frames[beginIndex].x << endl;
			cout << beginIndex + counter << endl;
			counter++;
			if (counter > endIndex - beginIndex)
			{
				counter = 0;
			}
		}

	}
	*/
}

//animate the sprite if you know the exact indexes of where you want to start and end
void AnimatedSprite::Animate(int beginIndex, int endIndex, int timeMili)
{
	if (isAnimating == false)
	{
		startAnimation();
	}
	else
	{
		sf::Time &elapsedTime = clock->getElapsedTime();
		if (elapsedTime.asMilliseconds() >= timeMili)
		{
			setTextureRect(sf::IntRect(frames[beginIndex + counter].x, frames[beginIndex + counter].y, frameWidth, frameHeight));
			clock->restart();

			//cout << "x: " << frames[beginIndex + counter].x << endl << "y: " << frames[beginIndex + counter].y << endl << endl;
			//cout << "beginIndex + counter: " << frames[beginIndex].x << endl;
			//cout << beginIndex + counter << endl;
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



