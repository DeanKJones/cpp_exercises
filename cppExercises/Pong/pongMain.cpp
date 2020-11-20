#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdio>
#include "Ball.h"
#include "Paddle.h"
#include "InputState.h"
#include "Text.h"
#include "SoundEffect.h"

// Defs

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
bool quit = false;
int result = 0;

int playerPoints = 0;
int opponentPoints = 0;

Text playerScoreText = Text(120, 100, 25, 50);
Text opponentScoreText = Text(650, 100, 25, 50);
Text resultText = Text(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 3, 150, 150);

Ball ball = Ball(0, 100, 32, 32, 7, 6);
Paddle paddleL = Paddle(0, 200, 32, 128, 4);
Paddle paddleR = Paddle(SCREEN_WIDTH - 32, 200, 32, 128, 4);
InputState inputState;

void load(SDL_Renderer*);
bool handleInput();
void update(SDL_Renderer* renderer);
void draw(SDL_Renderer*);
void close(SDL_Window*, SDL_Renderer*);
bool AABBcollision(SDL_Rect* rectA, SDL_Rect* rectB);

SoundEffect defeatSound = SoundEffect("defeat.wav");
SoundEffect outSound = SoundEffect("out.wav");
SoundEffect pingSound = SoundEffect("ping.wav");
SoundEffect winSound = SoundEffect("win.wav");

		///

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//init window
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	//load

	load(renderer);

	while (!quit)
	{
		//inputs
		quit = handleInput();

		//update
		update(renderer);

		//draw
		draw(renderer);

	}

	//end
	close(window, renderer);

	return 0;
}

void load(SDL_Renderer* renderer)
{
	playerScoreText.load(renderer, "0");
	opponentScoreText.load(renderer, "0");
	resultText.load(renderer, " ");
	defeatSound.load();
	outSound.load();
	pingSound.load();
	winSound.load();
}

bool handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.paddleUp = true;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = true;
			}
		}

		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.paddleUp = false;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = false;
			}
		}

		else if (e.type == SDL_QUIT)
		{
			return true;
		}
	}
	return false;
}

void update(SDL_Renderer* renderer)
{
	if (result == 0)
	{
		ball.update(SCREEN_WIDTH, SCREEN_HEIGHT);
		paddleL.update(&inputState, SCREEN_HEIGHT);
		paddleR.updateAI(SCREEN_HEIGHT, ball.y);

		//Collisions
		SDL_Rect ballRect = ball.toRect();
		SDL_Rect paddleRectL = paddleL.toRect();
		if (AABBcollision(&ballRect, &paddleRectL))
		{
			ball.horizontalBounce(paddleRectL.x + paddleRectL.w);
			pingSound.play();
		}

		SDL_Rect paddleRectR = paddleR.toRect();
		if (AABBcollision(&ballRect, &paddleRectR))
		{
			ball.horizontalBounce(paddleRectR.x - paddleRectR.w);
			pingSound.play();
		}

		//Points
		if (ball.getX() < 0)
		{
			++opponentPoints;
			ball.setX(SCREEN_WIDTH / 2);
			char newText[2];
			sprintf_s(newText, "%d", opponentPoints);
			opponentScoreText.changeText(renderer, newText);
			outSound.play();

			if (opponentPoints >= 7)
			{
				result = 2;
				resultText.changeText(renderer, "Defeat");
				defeatSound.play();
			}
		}

		else if (ball.getX() > SCREEN_WIDTH - ball.getWidth())
		{
			++playerPoints;
			ball.setX(SCREEN_WIDTH / 2);
			char newText[2];
			sprintf_s(newText, "%d", playerPoints);
			playerScoreText.changeText(renderer, newText);
			outSound.play();

			if (playerPoints >= 7)
			{
				result = 1;
				resultText.changeText(renderer, "Victory");
				winSound.play();
			}
		}
	}
			/// End 
	else
	{
	}
}

void draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x50, 0xFF);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	playerScoreText.draw(renderer);
	opponentScoreText.draw(renderer);
	resultText.draw(renderer);
	ball.draw(renderer);
	paddleL.draw(renderer);
	paddleR.draw(renderer);

	SDL_RenderPresent(renderer);
}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}


bool AABBcollision(SDL_Rect* rectA, SDL_Rect* rectB)
{
	int xMinA = rectA->x;
	int xMaxA = rectA->x + rectA->w;
	int yMinA = rectA->y;
	int yMaxA = rectA->y + rectA->h;

	int xMinB = rectB->x;
	int xMaxB = rectB->x + rectB->w;
	int yMinB = rectB->y;
	int yMaxB = rectB->y + rectB->h;

	return !(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
}