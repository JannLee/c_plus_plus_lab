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
		cout << "주소록" << endl;
		cout << "1. 추가/변경" << endl;
		cout << "2. 삭제(이름)" << endl;
		cout << "3. 삭제(메일)" << endl;
		cout << "4. 검색(이름)" << endl;
		cout << "5. 검색(메일)" << endl;
		cout << "6. 전체보기" << endl;
		cout << "q. 종료" << endl;
		cout << "선택 : ";
		cin >> input;
		if (input == "1") {
			cout << "이름 : ";
			cin >> name;
			cout << "메일 : ";
			cin >> email;
			name_to_email[name] = email;
		}
		else if (input == "2") {
			cout << "이름 : ";
			cin >> name;
			name_to_email.erase(name);
		}
		else if (input == "3") {
			cout << "메일 : ";
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
			cout << "이름 : ";
			cin >> name;
			map<string, string>::iterator itr = name_to_email.find(name);
			if (itr != name_to_email.end()) {
				cout << name << "의 메일 주소는 " << itr->second << "입니다." << endl;
			}
			else {
				cout << "해당하는 사람이 없습니다." << endl;
			}
		}
		else if (input == "5") {
			cout << "메일 : ";
			cin >> email;
			for (map<string, string>::iterator itr = name_to_email.begin(), end = name_to_email.end(); itr != end; ++itr) {
				if (itr->second == email) {
					cout << itr->second << "의 이름은 " << name << "입니다." << endl;
				}
			}
		}
		else if (input == "6") {
			for (map<string, string>::iterator itr = name_to_email.begin(), end = name_to_email.end(); itr != end; ++itr) {
				cout << "이름 : " << itr->first << ", 이메일 : " << itr->second << endl;
			}
		}
		cout << endl;
	}
}
