#include <iostream>
#include <map>
#include <string>

using namespace std;

void add(map<string, string>& AddressBook);
void del(map<string, string>& AddressBook);
void update(map<string, string>& AddressBook);
void search(map<string, string>& AddressBook);

int main()
{
	map<string, string> AddressBook;
	int input = 0;

	while (input < 5)
	{
		cout << "Select command" << endl;
		cout << "1 : add" << endl;
		cout << "2 : del" << endl;
		cout << "3 : update" << endl;
		cout << "4 : search" << endl;
		cout << "5 : exit" << endl;
		cin >> input;

		switch (input)
		{
			case 1:
				add(AddressBook);
				break;
			case 2:
				del(AddressBook);
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

void add(map<string, string>& AddressBook)
{
	cout << "11" <<endl;
}

void del(map<string, string>& AddressBook)
{
	cout << "11" << endl;
}

void update(map<string, string>& AddressBook)
{
	cout << "11" << endl;
}

void search(map<string, string>& AddressBook)
{
	cout << "11" << endl;
}
