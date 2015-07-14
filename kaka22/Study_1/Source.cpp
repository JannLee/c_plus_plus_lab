#include <string>
#include <iostream>


int main()
{
	std::string input1;
	std::string input2;
	std::string input3;
	std::string input4;
	std::string grape("бр");
	std::cin >> input1;
	std::cin >> input2;
	std::cin >> input3;
	std::cin >> input4;
	
	int iInput1 = 0;
	int iInput2 = 0;
	int iInput3 = 0;
	char buf[10] = { 0, };
	int exit = 0;
	while (buf[0] != '0')
	{
		std::cin.getline(buf, 2);

		if (buf[0] == '1')
			iInput1++;
		else if (buf[0] == '2')
			iInput2++;
		else if (buf[0] == '3')
			iInput3++;
		else
		{
			exit++;
			if (exit == 5)
				break;
		}

	}
	std::cout << input2 << ':';
	for (int i = 0; i < iInput1; i++)
	{
		std::cout << grape;
	}
	std::cout << std::endl;
	std::cout << input3 << ':';
	for (int i = 0; i < iInput2; i++)
	{
		std::cout << grape;
	}
	std::cout << std::endl;
	std::cout << input4 << ':';
	for (int i = 0; i < iInput3; i++)
	{
		std::cout << grape;
	}
	std::cout << std::endl;

	return 0;

}