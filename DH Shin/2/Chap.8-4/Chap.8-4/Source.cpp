#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX_NUM 3

bool Check();

int main()
{
	srand(time(NULL));

	int input = 1;
	while (input != 0)
	{
		std::cin >> input;
		if (Check())
		{
			std::cout << "You win." << std::endl;
		}
		else
		{
			std::cout << "You lose." << std::endl;
		}
	}

	return 0;
}

bool Check()
{
	bool result = true;
	int randNum[MAX_NUM] = { 0 };

	for (int i = 0; i < MAX_NUM; ++i)
	{
		randNum[i] = rand() % 10;
		std::cout << randNum[i];
	}
	std::cout << std::endl;

	int num = randNum[0];

	for (int i = 1; i < MAX_NUM; ++i)
	{
		if (num != randNum[i])
		{
			result = false;
			break;
		}
	}

	return result;
}