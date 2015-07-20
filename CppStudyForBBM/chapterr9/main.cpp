#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void printNum(int in);

int main() {
	int in = 0;
	cin >> in;
	if (in >= -999999 && in <= 999999) {
		if (in < 0) {
			cout << "���̳ʽ� ";
			in = in * -1;
		}
		if (in == 0) {
			cout << "��";
		}
		else {
			int th = in / 1000;
			int hu = in % 1000;
			if (th != 0) {
				printNum(th);
				cout << " �ο����� ";
			}
			if (hu != 0)
			{
				printNum(hu);
			}
		}
	}
	cout << endl;
	cin.get();
	return 0;
}

void printNum(int in) {
	int num = 0;
	if (in / 100 != 0)
	{
		if (in / 100 == 1) cout << "��";
		else if (in / 100 == 2)  cout << "��";
		else if (in / 100 == 3)  cout << "����";
		else if (in / 100 == 4)  cout << "��";
		else if (in / 100 == 5)  cout << "���̺�";
		else if (in / 100 == 6)  cout << "����";
		else if (in / 100 == 7)  cout << "����";
		else if (in / 100 == 8)  cout << "����";
		else if (in / 100 == 9)  cout << "����";
		cout << " ��巹�� ";
		in = in % 100;
	}
	num = in % 100;
	if (num >= 20)
	{
		if (num / 10 == 2)  cout << "����Ƽ ";
		else if (num / 10 == 3)  cout << "��Ƽ ";
		else if (num / 10 == 4)  cout << "��Ƽ ";
		else if (num / 10 == 5)  cout << "����Ƽ ";
		else if (num / 10 == 6)  cout << "�Ľ�Ƽ ";
		else if (num / 10 == 7)  cout << "����Ƽ ";
		else if (num / 10 == 8)  cout << "����Ƽ ";
		else if (num / 10 == 9)  cout << "����Ƽ ";
		num = num % 10;
	}
	if (num == 1) cout << "��";
	else if (num == 2)  cout << "��";
	else if (num == 3)  cout << "����";
	else if (num == 4)  cout << "��";
	else if (num == 5)  cout << "���̺�";
	else if (num == 6)  cout << "����";
	else if (num == 7)  cout << "����";
	else if (num == 8)  cout << "����";
	else if (num == 9)  cout << "����";
	else if (num == 10)  cout << "��";
	else if (num == 11)  cout << "�Ϸ���";
	else if (num == 12)  cout << "������";
	else if (num == 13)  cout << "��ƾ";
	else if (num == 14)  cout << "��ƾ";
	else if (num == 15)  cout << "����ƾ";
	else if (num == 16)  cout << "�Ľ�ƾ";
	else if (num == 17)  cout << "����ƾ";
	else if (num == 18)  cout << "����ƾ";
	else if (num == 19)  cout << "����ƾ";
}