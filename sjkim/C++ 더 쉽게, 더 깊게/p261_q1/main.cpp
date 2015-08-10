#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, string> addressBook;
	string command = "";
	string inputName = "";
	string inputEmail = "";

	cout << "COMMAND(add, del, find, quit) : ";
	getline(cin, command);

	while (command != "quit")
	{
		if (command == "add")
		{
			cout << "NAME : ";
			getline(cin, inputName);
			cout << "EMAIL : ";
			getline(cin, inputEmail);
			addressBook.insert(make_pair(inputName, inputEmail));
		}
		else if (command == "del")
		{
			map<string, string>::iterator it;

			cout << "NAME : ";
			getline(cin, inputName);
			it = addressBook.find(inputName);
			if (it != addressBook.end())
			{
				addressBook.erase(it);
			}
		}
		else if (command == "find")
		{
			map<string, string>::iterator it;

			cout << "NAME : ";
			getline(cin, inputName);
			it = addressBook.find(inputName);
			if (it != addressBook.end())
			{
				cout << "RESULT : " << it->second << endl;
			}
			else
			{
				cout << "Not found" << endl;
			}
		}

		cout << "COMMAND(add, del, find, quit) : ";
		getline(cin, command);
	}

	addressBook.clear();
}
