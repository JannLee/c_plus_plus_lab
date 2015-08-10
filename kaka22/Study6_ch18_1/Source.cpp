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
		std::cout << "�Է� -> 1" << std::endl;
		std::cout << "��� -> 2" << std::endl;
		std::cout << "���� -> 3" << std::endl;
		std::cout << "���� -> 4" << std::endl;
		std::cout << "���� -> 5" << std::endl;
		std::string buf;

		std::cin >> buf;

		if (buf.c_str()[0] == '1')
		{
			std::string name;
			std::string Address;
			std::cout << "�̸� : ";
			std::cin >> name;
			std::cout << "�ּ� : ";
			std::cin >> Address;
			AddressList.insert(std::make_pair(name, Address));
		}
		else if (buf.c_str()[0] == '2')
		{
			for (std::map<std::string, std::string>::iterator Iter = AddressList.begin(); Iter != AddressList.end(); ++Iter)
			{
				std::cout <<"�̸� : " <<Iter->first.c_str()<<"\t" <<"�ּ� :" <<Iter->second.c_str() << std::endl;
			}
		}
		else if (buf.c_str()[0] == '3' || buf.c_str()[0] == '4')
		{
			std::string name;
			std::cout << "�̸� : ";
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
					std::cout << "���ּ� : ";
					std::cin >> address;
					Iter->second = address;
				}
			}
			else
			{
				std::cout << "�Էµ� ����� �ƴ�.." << std::endl;
			}
		}
		else if (buf.c_str()[0] == '5')
		{
			return 0;
		}

	}

	return 0;
}