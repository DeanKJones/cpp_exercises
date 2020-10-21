#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
	srand(time(NULL));
	int randomNumber = rand() % 100;
	//std::cout << randomNumber << std::endl;
	bool success = false;

	while (!success)
	{
		int guess;
		cout << "Take a guess: ";
		cin >> guess;

		if (guess > randomNumber)
		{
			cout << "\nYour guess is too high.\nTry again!\n" << endl;
			success = false;
		}
		else if (guess < randomNumber)
		{
			cout << "\nYour guess is too low.\nTry again!\n" << endl;
			success = false;
		}
		else if (guess == randomNumber)
		{
			cout << "You guessed right!" << endl;
			success = true;
		}
	}
}