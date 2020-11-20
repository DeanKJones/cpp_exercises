#pragma once
#include "SoundEffect.h"

class Ball
{
public:
	Ball(int pX, int pY, int w, int h, int pSpeedX, int pSpeedY);
	Ball();
	~Ball();

	SDL_Rect toRect();

	void draw(SDL_Renderer* renderer);
	void update(int screenWidth, int screenHeight);

	void horizontalBounce(int xReplace);
	void verticalBounce(int yReplace);

	int getX()const;
	void setX(int pX);
	int getWidth()const;

	int y;

private:
	int x;
	//int y;
	int width;
	int height;
	int speedX;
	int speedY;
};
