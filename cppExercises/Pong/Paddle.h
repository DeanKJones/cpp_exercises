#pragma once
#include "InputState.h"

class Paddle
{
public:

	Paddle(int pX, int pY, int w, int h, int pSpeedY);

	SDL_Rect toRect();

	void draw(SDL_Renderer* renderer);
	void update(InputState* inputState, int screenHeight);

	void moveUp(int screenHeight);
	void moveDown(int screenHeight);
	void updateAI(int screenHeight, int ballY);

private:

	int x;
	int y;
	int height;
	int width;
	int speedY;
};