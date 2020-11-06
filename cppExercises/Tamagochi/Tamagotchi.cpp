#include <iostream>
#include "Tamagotchi.h"

using namespace std;

Tamagotchi::Tamagotchi(int pLives, int pHunger, int pBoredom)
	:lives(pLives), hunger(pHunger), boredom(pBoredom)
{
}

Tamagotchi::Tamagotchi()
{
	lives = 1;
	hunger = 10;
	boredom = 5;
}

/*Tamagotchi::~Tamagotchi()
{
	cout << "Tamagotchi has been destroyed!" << endl;
}*/

void Tamagotchi::talk()
{
	cout << "I am: " << Tamagotchi::getMood() << "\n" << endl;
	boredom++;
	hunger--;
}

void Tamagotchi::eat()
{
	hunger++;
	boredom--;
}

void Tamagotchi::play()
{
	boredom++;
	hunger--;
}

void Tamagotchi::die()
{
	//is_alive = false;
	lives--;
	cout << "I don't know how to do this yet" << endl;

	boredom--;
	hunger--;
}

string Tamagotchi::getMood()
{
	string mood;

	//cout << "\n\t" << hunger << " " << boredom << "\n" << endl;

	if (hunger == boredom)
		mood = "Happy";
	else if (hunger > boredom)
		mood = "Bored";
	else if (hunger < boredom)
		mood = "Hungry";
	else
		mood = "Unhappy";
	return mood;

	boredom--;
	hunger--;
	//cout << mood << endl;
}

void Tamagotchi::state()
{
	cout << "\n" << "Hunger: " << hunger << endl;
	cout << "Boredom: " << boredom << "\n" << endl;
}
