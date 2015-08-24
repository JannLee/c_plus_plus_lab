#include <iostream>
#include "vectorOfInt.h"

using namespace std;


int main()
{
	int input = 0;
	int index = 0;
	int value = 0;
	vectorOfInt vector_1;
	

	while (input < 7)
	{
		cout << endl << endl;
		cout << "Select command" << endl;
		cout << "1 : 32개의 요소 벡터를 할당하는 무인수 생성자" << endl;
		cout << "2 : 초기 크기를 인수로 받는 생성자" << endl;
		cout << "3 : 인덱스를 받아 인덱스의 값을 리턴하는 get 메소드" << endl;
		cout << "4 : 인덱스와 값을 받아 값을 인덱스에 설정하는 set 메소드" << endl;
		cout << "5 : 배열의 끝에 요소 추가" << endl;
		cout << "6 : 배열의 처음에 요소 추가" << endl;
		cin >> input;

		if (input == 1)
		{
			vector_1.print_array();
		}
		else if (input == 2)
		{
			cout << "초기 크기를 입력 하세요 :" << endl;
			cin >> value;
			vectorOfInt vector_2(value);
			vector_2.print_array();
		}
		else if (input == 3)
		{
			cout << "인덱스를 입력하세요 :" << endl;
			cin >> index;
			value = vector_1.get(index);
			cout << "해당 인덱스 값 :" << value << endl;
		}
		else if (input == 4)
		{
			cout << "인덱스를 입력하세요 :" << endl;
			cin >> index;
			cout << "값을 입력하세요 :" << endl;
			cin >> value;

			vector_1.set(index, value);
			cout << "[" << index << "]" << "인덱스 값 :" << value << endl;
		}
		else if (input == 5)
		{
			cout << "끝에 넣을 값을 입력하세요 :" << endl;
			cin >> value;

			vector_1.pushback(value);
			vector_1.print_array();
		}
		else if (input == 6)
		{
			cout << "처음에 넣을 값을 입력하세요 :" << endl;
			cin >> value;

			vector_1.pushfront(value);
			vector_1.print_array();
		}
	}

	return 0;
}