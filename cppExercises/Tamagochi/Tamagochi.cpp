#include <iostream>

using namespace std;

class Tamagochi
{
public:
	int getHunger()const
	{
		return hunger;
	}
private:
	int hunger;
};

int main()
{
	Tamagochi mochi{};
	cout << mochi.getHunger() << endl;

	int* pScore = new int;
	*pScore = 500;
	//pScore = new int(1000);
	//delete pScore;
	//pScore = 0;

	cout << *pScore << endl;

	return 0;
}