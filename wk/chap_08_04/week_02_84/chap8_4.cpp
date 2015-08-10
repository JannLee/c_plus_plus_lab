#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{	
	int randNum[3] = { 0 };
	int trash;

	cout << "게임을 시작하려면 아무키나 눌러주세요 :D" << endl;
	cin >> trash;

	cout << "당신의 카드는!!" << endl;
	srand(time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		randNum[i] = rand() % 10;
		cout << randNum[i];
	}

	cout << endl;

	
	if (randNum[0] == randNum[1] == randNum[2])
	{
		cout << "트리플~! 승점 2점 입니다." << endl;
	}
	else if ((randNum[0] == randNum[1]) || (randNum[1] == randNum[2]) || (randNum[2] == randNum[0]))
	{
		cout << "원페어~! 승점 1점 입니다." << endl;
	}




	return 0;
}
