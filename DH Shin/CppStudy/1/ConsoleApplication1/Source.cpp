#include <iostream>
#include <string>

int main()
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	char input = 0;
	bool flag = true;
	std::string item;
	std::string item1;
	std::string item2;
	std::string item3;
	std::cout << "설문?" << std::endl;
	std::getline(std::cin, item, '\n');
	std::cout << "선택항목 1?" << std::endl;
	std::getline(std::cin, item1, '\n');
	std::cout << "선택항목 2?" << std::endl;
	std::getline(std::cin, item2, '\n');
	std::cout << "선택항목 3?" << std::endl;
	std::getline(std::cin, item3, '\n');
	while (flag == true)
	{
		system("cls");
		std::cout << item << std::endl;
		std::cout << "1 : " << item1 << std::endl;
		std::cout << "2 : " << item2<< std::endl;
		std::cout << "3 : " << item3 << std::endl;
		std::cin >> input;
		if (input == '0')
		{
			flag = false;
		}
		else if (input == '1')
		{
			++count1;
		}
		else if (input == '2')
		{
			++count2;
		}
		else if (input == '3')
		{
			++count3;
		}
	}

	system("cls");
	std::cout << item << " 결과" << std::endl;
	std::cout << item1 << " : ";
	for (int i = 0; i < count1; ++i)
	{
		std::cout << "[]";
	}
	std::cout << std::endl;
	std::cout << item2 << " : ";
	for (int i = 0; i < count2; ++i)
	{
		std::cout << "[]";
	}
	std::cout << std::endl;
	std::cout << item3 << " : ";
	for (int i = 0; i < count3; ++i)
	{
		std::cout << "[]";
	}
	std::cout << std::endl;

	return 0;
}