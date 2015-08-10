#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int main() {
	map<string, string> name_to_email;
	string input = "";
	string name = "";
	string email = "";
	while (input != "q") {
		cout << "�ּҷ�" << endl;
		cout << "1. �߰�/����" << endl;
		cout << "2. ����(�̸�)" << endl;
		cout << "3. ����(����)" << endl;
		cout << "4. �˻�(�̸�)" << endl;
		cout << "5. �˻�(����)" << endl;
		cout << "6. ��ü����" << endl;
		cout << "q. ����" << endl;
		cout << "���� : ";
		cin >> input;
		if (input == "1") {
			cout << "�̸� : ";
			cin >> name;
			cout << "���� : ";
			cin >> email;
			name_to_email[name] = email;
		}
		else if (input == "2") {
			cout << "�̸� : ";
			cin >> name;
			name_to_email.erase(name);
		}
		else if (input == "3") {
			cout << "���� : ";
			cin >> email;
			map<string, string>::iterator itr = name_to_email.begin();
			for (map<string, string>::iterator end = name_to_email.end(); itr != end; ++itr) {
				if (itr->second == email) {
					break;
				}
			}
			if (itr != name_to_email.end()) {
				name_to_email.erase(itr->first);
			}
		}
		else if (input == "4") {
			cout << "�̸� : ";
			cin >> name;
			map<string, string>::iterator itr = name_to_email.find(name);
			if (itr != name_to_email.end()) {
				cout << name << "�� ���� �ּҴ� " << itr->second << "�Դϴ�." << endl;
			}
			else {
				cout << "�ش��ϴ� ����� �����ϴ�." << endl;
			}
		}
		else if (input == "5") {
			cout << "���� : ";
			cin >> email;
			for (map<string, string>::iterator itr = name_to_email.begin(), end = name_to_email.end(); itr != end; ++itr) {
				if (itr->second == email) {
					cout << itr->second << "�� �̸��� " << name << "�Դϴ�." << endl;
				}
			}
		}
		else if (input == "6") {
			for (map<string, string>::iterator itr = name_to_email.begin(), end = name_to_email.end(); itr != end; ++itr) {
				cout << "�̸� : " << itr->first << ", �̸��� : " << itr->second << endl;
			}
		}
		cout << endl;
	}
}
