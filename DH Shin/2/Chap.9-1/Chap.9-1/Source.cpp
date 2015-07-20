#include <iostream>
#include <string>

std::string numberToString1[20] = { "one",
									"two",
									"three",
									"four",
									"five",
									"six",
									"seven",
									"eight",
									"nine",
									"ten",
									"eleven",
									"twelve",
									"thirteen",
									"fourteen",
									"fifteen",
									"sixteen",
									"seventeen",
									"eighteen",
									"nineteen",
									"twenty" };

std::string numberToString2[7] = { "thirty",
									"forty",
									"fifty",
									"sixty",
									"seventy",
									"eighty",
									"ninety" };

void printNum(int num);

int main()
{
	int input = 0;
	std::cin >> input;
	if (input > 999999 || input < -999999)
	{
		std::cout << "Out of range" << std::endl;
		return 0;
	}
	if (input < 0)
	{
		std::cout << "minus ";
		input = input * -1;
	}

	int num = input / 1000;
	int remainder = input % 1000;
	if (num != 0)
	{
		printNum(num);
		std::cout << "thousand ";
	}
	if (remainder != 0)
	{
		printNum(remainder);
	}
	if (num == 0 && remainder == 0)
	{
		std::cout << "zero";
	}
	std::cout << std::endl;
	
	return 0;
}

void printNum(int num)
{
	if (num / 100 != 0)
	{
		std::cout << numberToString1[num / 100 - 1] << " " << "hundred ";
		num = num % 100;
	}
	if (num > 20)
	{
		std::cout << numberToString2[num / 10 - 3] << " ";
		num = num % 10;
	}
	std::cout << numberToString1[num - 1] << " ";
}