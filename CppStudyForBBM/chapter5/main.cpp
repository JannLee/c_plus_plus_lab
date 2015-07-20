#include <iostream>
#include <string>

using namespace std;

int main() {
	string q = "";
	string one = "";
	string two = "";
	string three = "";

	int ione = 0;
	int itwo = 0;
	int ithree = 0;
	int in = -1;

	cout << "설문을 입력해 주세요." << endl;
	cin >> q;
	cout << "첫 번째, 문항을 입력해 주세요. : ";
	cin >> one;
	cout << "두 번째, 문항을 입력해 주세요. : ";
	cin >> two;
	cout << "세 번째, 문항을 입력해 주세요. : ";
	cin >> three;
	while (in != 0) {
		cout << "투표해주세요." << endl;
		cin >> in;
		if (in == 1) {
			++ione;
		}
		else if (in == 2) {
			++itwo;
		}
		else if (in == 3) {
			++ithree;
		}
	}
	cout << one << "\t: ";
	for (int i = 0; i < ione; i++) {
		cout << "□";
	}
	cout << endl;
	cout << two << "\t: ";
	for (int i = 0; i < itwo; i++) {
		cout << "□";
	}
	cout << endl;
	cout << three << "\t: ";
	for (int i = 0; i < ithree; i++) {
		cout << "□";
	}
	cout << endl;
	cin.get();
	return 0;
}