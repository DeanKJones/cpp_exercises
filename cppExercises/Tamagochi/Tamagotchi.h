#pragma once
#include <string>

using namespace std;

class Tamagotchi
{
public: 
	Tamagotchi(int pLives, int pHunger, int pBoredom);
	Tamagotchi();
	//~Tamagotchi();

	void talk();
	void eat();
	void play();
	void die();
	void state();

	string getMood();


private:
	int hunger;
	int boredom;
	int lives;
	//bool is_alive;
	string mood;
	//int passTime;
};