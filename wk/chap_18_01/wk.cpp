#include <iostream>
#include <map>
#include <string>

using namespace std;

void insert(map<string, string> &AddressBook);
void erase(map<string, string> &AddressBook);
void update(map<string, string> &AddressBook);
void search(map<string, string> &AddressBook);


int main()
{
	map<string, string> AddressBook;
	int input = 0;

	while (input < 5)
	{
		cout << "Select command" << endl;
		cout << "1 : Insert" << endl;
		cout << "2 : Erase" << endl;
		cout << "3 : Update" << endl;
		cout << "4 : Search" << endl;
		cout << "5 : Exit" << endl;
		cin >> input;

		switch (input)
		{
			system("cls");
			case 1:
				insert(AddressBook);
				break;
			case 2:
				erase(AddressBook);
				break;
			case 3:
				update(AddressBook);
				break;
			case 4:
				search(AddressBook);
				break;
			case 5:
				return 0;
		}
	}
	
}

void insert(map<string, string> &AddressBook)
{
	string name;
	string email;

	cout << "Name ? : ";
	cin >> name;
	cout << "Email ? : ";
	cin >> email;

	AddressBook.insert(make_pair(name, email));

	system("cls");
}

void erase(map<string, string> &AddressBook)
{
	string name;
	cout << "Name ? : ";
	cin >> name;

	AddressBook.erase(name);

	system("cls");
}

void update(map<string, string> &AddressBook)
{
	string name;
	string email;

	cout << "Name ? : ";
	cin >> name;
	cout << "Email ? : ";
	cin >> email;

	system("cls");

	map<string, string>::iterator itr = AddressBook.find(name);
	if (itr != AddressBook.end())
	{
		itr->second = email;	 		
	}
	else
	{
		cout << "can't find name.." << endl;
	}
}

void search(map<string, string> &AddressBook)
{
	string name;
	cout << "Name ? : ";
	cin >> name;

	map<string, string>::const_iterator itr = AddressBook.find(name);

	if (itr != AddressBook.end())
	{
		cout << "Name : " << itr->first << endl;
		cout << "Email : " << itr->second << endl;
	}
	else
	{
		cout << "cnat find name.." << endl;
	}
}