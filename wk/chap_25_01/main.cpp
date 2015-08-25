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
		cout << "1 : 32���� ��� ���͸� �Ҵ��ϴ� ���μ� ������" << endl;
		cout << "2 : �ʱ� ũ�⸦ �μ��� �޴� ������" << endl;
		cout << "3 : �ε����� �޾� �ε����� ���� �����ϴ� get �޼ҵ�" << endl;
		cout << "4 : �ε����� ���� �޾� ���� �ε����� �����ϴ� set �޼ҵ�" << endl;
		cout << "5 : �迭�� ���� ��� �߰�" << endl;
		cout << "6 : �迭�� ó���� ��� �߰�" << endl;
		cin >> input;

		if (input == 1)
		{
			vector_1.print_array();
		}
		else if (input == 2)
		{
			cout << "�ʱ� ũ�⸦ �Է� �ϼ��� :" << endl;
			cin >> value;
			vectorOfInt vector_2(value);
			vector_2.print_array();
		}
		else if (input == 3)
		{
			cout << "�ε����� �Է��ϼ��� :" << endl;
			cin >> index;
			value = vector_1.get(index);
			cout << "�ش� �ε��� �� :" << value << endl;
		}
		else if (input == 4)
		{
			cout << "�ε����� �Է��ϼ��� :" << endl;
			cin >> index;
			cout << "���� �Է��ϼ��� :" << endl;
			cin >> value;

			vector_1.set(index, value);
			cout << "[" << index << "]" << "�ε��� �� :" << value << endl;
		}
		else if (input == 5)
		{
			cout << "���� ���� ���� �Է��ϼ��� :" << endl;
			cin >> value;

			vector_1.pushback(value);
			vector_1.print_array();
		}
		else if (input == 6)
		{
			cout << "ó���� ���� ���� �Է��ϼ��� :" << endl;
			cin >> value;

			vector_1.pushfront(value);
			vector_1.print_array();
		}
	}

	return 0;
}