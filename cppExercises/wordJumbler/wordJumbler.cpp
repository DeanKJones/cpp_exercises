#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
#include <time.h>
#include <algorithm>
#include <random>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{

	const int totalNames = 6;
	array<string, totalNames> names{ "dean", "jason", "keagan", "dian", "josh", "elliot" };

	srand(time(0));
	string randomName = names[rand() % totalNames];
	string name = randomName;
	int nameLength = name.size();

    bool success = false;

	for (int i = 0; i < nameLength; i++)
	{

		int index1 = rand() % nameLength;
		int index2 = rand() % nameLength;
		char tempIndex;

		tempIndex = name[index1];
		name[index1] = name[index2];
		name[index2] = tempIndex;

	}

	cout << name << "\n" << endl;

    string guess;
    string quit = "quit";

    cout << "Who's name is this?" << "\n" << "Write it here: ";
    cin >> guess;

    while (!success)
    {

        cout << "\nWho's name is this?" << "\n" << "Write it here: ";
        cin >> guess;

        if (guess == quit)
        {
            exit(EXIT_FAILURE);
        }

        if (guess == randomName)
        {
            cout << "\nThat's thier name!" << endl;
            success = true;
        }

        if (guess != randomName)
        {
            cout << "\nThat's wrong.\nTry again.\n" << endl;
            success = false;
        }
    }
	return 0;
}