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

	cout << "설문 내용을 입력하세요" << endl;
	getline(cin, item, '\n');
	cout << "선택항목 1의 내용?" << endl;
	getline(cin, item1, '\n');
	cout << "선택항목 2의 내용?" << endl;
	getline(cin, item2, '\n');
	cout << "선택항목 3의 내용?" << endl;
	getline(cin, item3, '\n');


	while (flag == true)
	{
		system("cls");
		cout << item << endl;
		cout << "1번 : " << item1 << endl;
		cout << "2번 : " << item2 << endl;
		cout << "3번 : " << item3 << endl;

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
	cout << " ------- 설문 결과 ------- " << endl;
	cout << "1번 : ";
	for (int i = 0; i < count1; ++i)
	{
		cout << "D";
	}
	cout << endl;
	cout << "2번 : ";
	for (int i = 0; i < count2; ++i)
	{
		cout << "D";
	}
	cout << endl;
	cout << "3번 : ";
	for (int i = 0; i < count3; ++i)
	{
		cout << "D";
	}
	cout << endl;

	return 0;
}