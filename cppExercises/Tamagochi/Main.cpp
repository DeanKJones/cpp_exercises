#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "Tamagotchi.h"

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void game()
{
	cout << "\n      What would you like to do?\n\n" << "\t(1)talk \t(2)eat\n\t(3)play \t(4)die\n" << endl;
}

int main(int argc, char* argv)
{
	Tamagotchi Motchi(1, 5, 5);

	bool success = true;

	while (success)
	{
		system("cls");
		char input;

		game();
		Motchi.state();

		cin >> input;

		if (input == '1')
		{
			Motchi.talk();
			sleep_for(nanoseconds(50));
			sleep_until(system_clock::now() + seconds(1));
		}

		else if (input == '2')
		{
			Motchi.eat();
		}

		else if (input == '3')
		{
			Motchi.play();
		}

		else if (input == '4')
		{
			Motchi.die();
			sleep_for(nanoseconds(20));
			sleep_until(system_clock::now() + seconds(1));
		}

		else
		{
			cout << "Invalid input" << endl;
			sleep_for(nanoseconds(10));
			sleep_until(system_clock::now() + seconds(1));
		}

		success = true;

		if (input == 'quit')
			success = false;
	}
}