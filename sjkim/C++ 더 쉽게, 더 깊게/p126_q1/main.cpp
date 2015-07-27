#include <iostream>
#include <cstdlib>

using namespace std;

void PrintArea(int number);
void PrintDigit(int digit);
void PrintTwoDigit(int twoDigit);

int main(int argc, char* argv[])
{
	int inputNumber = 0;

	if (argc != 2)
	{
		cout << "Usage : " << argv[0] << " number" << endl;
		return -1;
	}

	inputNumber = atoi(argv[1]);

	if (inputNumber < -999999 || inputNumber > 999999)
	{
		cout << "Wrong number. (-999999 ~ 999999)" << endl;
		return -2;
	}

	if (inputNumber < 0)
	{
		cout << "minus ";
		inputNumber *= -1;
	}

	if (inputNumber > 999)
	{
		PrintArea(inputNumber / 1000);
		cout << "thousand ";
	}

	PrintArea(inputNumber % 1000);
	cout << endl;

	return 0;
}

void PrintArea(int number)
{
	if (number > 99)
	{
		PrintDigit(number / 100);
		cout << "hundred ";
	}

	PrintTwoDigit(number % 100);
}

void PrintDigit(int digit)
{
	switch (digit)
	{
	case 1:
		cout << "one ";
		break;
	case 2:
		cout << "two ";
		break;
	case 3:
		cout << "three ";
		break;
	case 4:
		cout << "four ";
		break;
	case 5:
		cout << "five ";
		break;
	case 6:
		cout << "six ";
		break;
	case 7:
		cout << "seven ";
		break;
	case 8:
		cout << "eight ";
		break;
	case 9:
		cout << "nine ";
		break;
	default:
		break;
	}
}

void PrintTwoDigit(int twoDigit)
{
	if (twoDigit < 10)
	{
		PrintDigit(twoDigit);
	}
	else if (twoDigit < 20)
	{
		switch (twoDigit)
		{
		case 10:
			cout << "ten ";
			break;
		case 11:
			cout << "eleven ";
			break;
		case 12:
			cout << "twelve ";
			break;
		case 13:
			cout << "thirteen ";
			break;
		case 14:
			cout << "fourteen ";
			break;
		case 15:
			cout << "fifteen ";
			break;
		case 16:
			cout << "sixteen ";
			break;
		case 17:
			cout << "seventeen ";
			break;
		case 18:
			cout << "eightteen ";
			break;
		case 19:
			cout << "nineteen ";
			break;
		default:
			break;
		}
	}
	else if (twoDigit < 100)
	{
		if (twoDigit < 30)
			cout << "twenty ";
		else if (twoDigit < 40)
			cout << "thirty ";
		else if (twoDigit < 50)
			cout << "forty ";
		else if (twoDigit < 60)
			cout << "fifty ";
		else if (twoDigit < 70)
			cout << "sixty ";
		else if (twoDigit < 80)
			cout << "seventy ";
		else if (twoDigit < 90)
			cout << "eighty ";
		else if (twoDigit < 100)
			cout << "ninety ";
		PrintDigit(twoDigit % 10);
	}
}

