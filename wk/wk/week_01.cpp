#include <iostream>
#include <string>

using namespace std;

int main()
{
	string item;
	string item1;
	string item2;
	string item3;

	char input = 0;
	bool flag = true;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	cout << "���� ������ �Է��ϼ���" << endl;
	getline(cin, item, '\n');
	cout << "�����׸� 1�� ����?" << endl;
	getline(cin, item1, '\n');
	cout << "�����׸� 2�� ����?" << endl;
	getline(cin, item2, '\n');
	cout << "�����׸� 3�� ����?" << endl;
	getline(cin, item3, '\n');


	while (flag == true)
	{
		system("cls");
		cout << item << endl;
		cout << "1�� : " << item1 << endl;
		cout << "2�� : " << item2 << endl;
		cout << "3�� : " << item3 << endl;

		cin >> input;

		if (input == '0')
		{
			flag = false;
		}
		else if (input == '1')
		{
			++count1;
		}
		else if (input == '2')
		{
			++count2;
		}
		else if (input == '3')
		{
			++count3;
		}
	}

	system("cls");
	cout << " ------- ���� ��� ------- " << endl;
	cout << "1�� : ";
	for (int i = 0; i < count1; ++i)
	{
		cout << "D";
	}
	cout << endl;
	cout << "2�� : ";
	for (int i = 0; i < count2; ++i)
	{
		cout << "D";
	}
	cout << endl;
	cout << "3�� : ";
	for (int i = 0; i < count3; ++i)
	{
		cout << "D";
	}
	cout << endl;

	return 0;
}