#include <iostream>
#include <string>

#define MAX_RATE_NUMBER 60

using namespace std;

int main()
{
	string question = "";
	string firstAnswer = "";
	string secondAnswer = "";
	string thirdAnswer = "";
	char answer = 0;
	int firstAnswerCount = 0;
	int secondAnswerCount = 0;
	int thirdAnswerCount = 0;
	int answersCount = 0;
	double rateFirst = 0;
	double rateSecond = 0;
	double rateThird = 0;
	int i = 0;

	cout << "설문을 입력하시오 : ";
	cin >> question;

	cout << "첫 번째 선택 항목 : ";
	cin >> firstAnswer;
	cout << "두 번째 선택 항목 : ";
	cin >> secondAnswer;
	cout << "세 번째 선택 항목 : ";
	cin >> thirdAnswer;

	while (answer != '0')
	{
		cout << question << endl << "1 : " << firstAnswer << endl << "2 : " << secondAnswer << endl << "3 : " << thirdAnswer << endl << ": ";
		cin >> answer;

		if (answer == '1')
		{
			++firstAnswerCount;
		}
		else if (answer == '2')
		{
			++secondAnswerCount;
		}
		else if (answer == '3')
		{
			++thirdAnswerCount;
		}
	}

	answersCount = firstAnswerCount + secondAnswerCount + thirdAnswerCount;
	rateFirst = static_cast<double>(firstAnswerCount) / answersCount;
	rateSecond = static_cast<double>(secondAnswerCount) / answersCount;
	rateThird = static_cast<double>(thirdAnswerCount) / answersCount;

	cout << "결과" << endl;
	cout << "1 : ";
	for (i = 0; i < rateFirst * MAX_RATE_NUMBER; ++i)
	{
		cout << "O";
	}
	for (; i < MAX_RATE_NUMBER; ++i)
	{
		cout << " ";
	}
	cout << " -> " << firstAnswerCount << "(" << rateFirst*100 << "%)" << endl;

	cout << "2 : ";
	for (i = 0; i < rateSecond * MAX_RATE_NUMBER; ++i)
	{
		cout << "O";
	}
	for (; i < MAX_RATE_NUMBER; ++i)
	{
		cout << " ";
	}
	cout << " -> " << secondAnswerCount << "(" << rateSecond*100 << "%)" << endl;

	cout << "3 : ";
	for (i = 0; i < rateThird * MAX_RATE_NUMBER; ++i)
	{
		cout << "O";
	}
	for (; i < MAX_RATE_NUMBER; ++i)
	{
		cout << " ";
	}
	cout << " -> " << thirdAnswerCount << "(" << rateThird*100 << "%)" << endl;

	return 0;
}
