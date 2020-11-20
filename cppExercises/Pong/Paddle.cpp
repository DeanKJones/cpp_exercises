#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Paddle.h"
#include "InputState.h"

Paddle::Paddle(int pX, int pY, int w, int h, int pSpeedY)
	:x(pX), y(pY), width(w), height(h), speedY(pSpeedY)
{
}

SDL_Rect Paddle::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Paddle::update(InputState* inputState, int screenHeight)
{
	if (inputState->paddleUp)
	{
		moveUp(screenHeight);
 	}

	if (inputState->paddleDown)
	{
		moveDown(screenHeight);
	}
}

void Paddle::moveUp(int screenHeight)
{
	y -= speedY;
	if (y < 0)
	{
		y = 0;
	}
}

void Paddle::moveDown(int screenHeight)
{
	y += speedY;
	if (y > screenHeight - height)
	{
		y = screenHeight - height;
	}
}

void Paddle::updateAI(int screenHeight, int ballY)
{
	if (ballY < y + height / 4)
	{
		moveUp(screenHeight);
	}
	else if (ballY > y + height * 3 / 4)
	{
		moveDown(screenHeight);
	}
}