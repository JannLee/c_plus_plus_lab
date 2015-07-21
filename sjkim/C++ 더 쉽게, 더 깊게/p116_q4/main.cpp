#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	int firstNumber = 0;
	int secondNumber = 0;
	int thirdNumber = 0;

	srand(time(NULL));

	firstNumber = rand() % 10;
	secondNumber = rand() % 10;
	thirdNumber = rand() % 10;

	cout << firstNumber << secondNumber << thirdNumber << endl;

	if (firstNumber == secondNumber && secondNumber == thirdNumber)
	{
		cout << "Win!" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}

	return 0;
}
