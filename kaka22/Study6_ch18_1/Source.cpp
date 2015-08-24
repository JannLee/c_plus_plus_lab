#include <iostream>
#include <string>
#include <cstdio>
#include <map>
struct node
{
	std::string name;
	std::string Email;
	node* p_left;
	node* p_right;
};



int main()
{
	std::map<std::string, std::string> AddressList;

	

	while (true)
	{
		std::cout << "입력 -> 1" << std::endl;
		std::cout << "출력 -> 2" << std::endl;
		std::cout << "삭제 -> 3" << std::endl;
		std::cout << "변경 -> 4" << std::endl;
		std::cout << "종료 -> 5" << std::endl;
		std::string buf;

		std::cin >> buf;

		if (buf.c_str()[0] == '1')
		{
			std::string name;
			std::string Address;
			std::cout << "이름 : ";
			std::cin >> name;
			std::cout << "주소 : ";
			std::cin >> Address;
			AddressList.insert(std::make_pair(name, Address));
		}
		else if (buf.c_str()[0] == '2')
		{
			for (std::map<std::string, std::string>::iterator Iter = AddressList.begin(); Iter != AddressList.end(); ++Iter)
			{
				std::cout <<"이름 : " <<Iter->first.c_str()<<"\t" <<"주소 :" <<Iter->second.c_str() << std::endl;
			}
		}
		else if (buf.c_str()[0] == '3' || buf.c_str()[0] == '4')
		{
			std::string name;
			std::cout << "이름 : ";
			std::cin >> name;
			std::map<std::string, std::string>::iterator Iter = AddressList.find(name);
			if (Iter != AddressList.end())
			{
				if (buf.c_str()[0] == '3')
				{
					AddressList.erase(Iter);
				}
				else if(buf.c_str()[0] == '4')
				{
					std::string address;
					std::cout << "새주소 : ";
					std::cin >> address;
					Iter->second = address;
				}
			}
			else
			{
				std::cout << "입력된 사람이 아님.." << std::endl;
			}
		}
		else if (buf.c_str()[0] == '5')
		{
			return 0;
		}

	}

	return 0;
}