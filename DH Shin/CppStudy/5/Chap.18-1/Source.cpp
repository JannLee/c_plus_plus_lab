#include <iostream>
#include <string>
#include <map>

void insert(std::map<std::string, std::string>& addressBook);
void search(std::map<std::string, std::string>& addressBook);
void remove(std::map<std::string, std::string>& addressBook);
void update(std::map<std::string, std::string>& addressBook);

int main()
{
	std::map<std::string, std::string> addressBook;
	int command = -1;

	while (command != 0)
	{
		std::cout << "Input command" << std::endl;
		std::cout << "1 : Insert\n2 : Search\n3 : Remove\n4 : Update\n0 : Exit" << std::endl;
		std::cin >> command;

		switch (command)
		{
		case 0:
			break;
		case 1:
			insert(addressBook);
			break;
		case 2:
			search(addressBook);
			break;
		case 3:
			remove(addressBook);
			break;
		case 4:
			update(addressBook);
			break;
		default:
			break;
		}
	}

	addressBook.clear();
	return 0;
}
void insert(std::map<std::string, std::string>& addressBook)
{
	std::string name;
	std::string email;
	std::cout << "Input name: " << std::endl;
	std::cin >> name;
	std::cout << "Input email:" << std::endl;
	std::cin >> email;

	std::map<std::string, std::string>::const_iterator it = addressBook.find(name);
	if (it != addressBook.end())
	{
		std::cout << name << " already exists." << std::endl;
	}
	else
	{
		addressBook.insert(std::make_pair(name, email));
	}
}
void search(std::map<std::string, std::string>& addressBook)
{
	std::string name;

	std::cout << "Input name: " << std::endl;
	std::cin >> name;

	std::map<std::string, std::string>::const_iterator it = addressBook.find(name);

	if (it != addressBook.end())
	{
		std::cout << "Name : " << it->first << std::endl;
		std::cout << "Email : " << it->second << std::endl;
	}
	else
	{
		std::cout << "No data" << std::endl;
	}

}
void remove(std::map<std::string, std::string>& addressBook)
{
	std::string name;

	std::cout << "Input name: " << std::endl;
	std::cin >> name;

	addressBook.erase(name);
}
void update(std::map<std::string, std::string>& addressBook)
{
	std::string name;
	std::string email;

	std::cout << "Input name: " << std::endl;
	std::cin >> name;
	std::cout << "Input email:" << std::endl;
	std::cin >> email;

	std::map<std::string, std::string>::iterator it = addressBook.find(name);
	if (it != addressBook.end())
	{
		it->second = email;
		std::cout << "Name : " << it->first << std::endl;
		std::cout << "Email : " << it->second << std::endl;
	}
	else
	{
		std::cout << "No data" << std::endl;
	}
}