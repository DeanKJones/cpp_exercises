#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Ball.h"
#include "SoundEffect.h"

Ball::Ball(int pX, int pY, int w, int h, int pSpeedX, int pSpeedY)
	:x(pX), y(pY), width(w), height(h), speedX(pSpeedX), speedY(pSpeedY)
{
}

Ball::Ball()
	: x(0), y(0), width(32), height(32), speedX(6), speedY(6)
{}

Ball::~Ball()
{}

SDL_Rect Ball::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Ball::update(int screenWidth, int screenHeight)
{
	x += speedX;
	y += speedY;

	// Vertical
	if (y < 0)
	{
		verticalBounce(0);
	}

	if (y > screenHeight - height)
	{
		verticalBounce(screenHeight - height);
	}

	//Horizontal
	if (x < 0)
	{
	}

	if (x > screenWidth - width)
	{
	}
}

void Ball::horizontalBounce(int xReplace)
{
	speedX *= -1;
	x = xReplace;
}

void Ball::verticalBounce(int yReplace)
{
	speedY *= -1;
	y = yReplace;
}

int Ball::getX()const
{
	return x;
}

void Ball::setX(int pX)
{
	x = pX;
}

int Ball::getWidth()const
{
	return width;
}