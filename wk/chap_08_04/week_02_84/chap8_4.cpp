#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{	
	int randNum[3] = { 0 };
	int trash;

	cout << "������ �����Ϸ��� �ƹ�Ű�� �����ּ��� :D" << endl;
	cin >> trash;

	cout << "����� ī���!!" << endl;
	srand(time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		randNum[i] = rand() % 10;
		cout << randNum[i];
	}

	cout << endl;

	
	if (randNum[0] == randNum[1] == randNum[2])
	{
		cout << "Ʈ����~! ���� 2�� �Դϴ�." << endl;
	}
	else if ((randNum[0] == randNum[1]) || (randNum[1] == randNum[2]) || (randNum[2] == randNum[0]))
	{
		cout << "�����~! ���� 1�� �Դϴ�." << endl;
	}




	return 0;
}
