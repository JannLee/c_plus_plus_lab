#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));
	int a = rand() % 10;
	int b = rand() % 10;
	int c = rand() % 10;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	if (a == b && b == c) {
		cout << "WIN!!!" << endl;
	}
	else {
		cout << "LOSE!!" << endl;
	}
	return 0;
}