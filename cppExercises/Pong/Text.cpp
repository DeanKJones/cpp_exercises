#include "Text.h"
#include <cstdio>


Text::Text(int pX, int pY, int pWidth, int pHeight)
	:x(pX), y(pY), width(pWidth), height(pHeight), font(nullptr),
	color({ 0xFF, 0xFF, 0xFF }), surface(nullptr), texture(nullptr)
{
}

/*
Text::Text()
	:x(10), y(10), width(15), height(20), font("OpenSans-Regular.ttf"),
	color({ 0xFF, 0xFF, 0xFF }), surface(nullptr), texture(nullptr)
{}

Text::~Text()
{}
*/

void Text::load(SDL_Renderer* renderer, const char* newText)
{
	font = TTF_OpenFont("OpenSans-Regular.ttf", 28);
	changeText(renderer, newText);
}

void Text::changeText(SDL_Renderer* renderer, const char* newText)
{
	if (texture)
	{
		SDL_DestroyTexture(texture);
	}
	surface = TTF_RenderText_Solid(font, newText, color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Text::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}