// p116_8_4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <ctime>
#include <iostream>


using namespace std;


void print_rules();
bool is_rule_matched(int num1, int num2, int num3);


int main()
{
    int input = 0;
    int num1 = 0, num2 = 0, num3 = 0;

    srand(time(NULL));

    do
    {
        cout << "*** ���Ըӽ� ���� ***" << endl
             << "0: ����, 1: ������, 2: ��Ģ" << endl;

        cin >> input;

        switch (input)
        {
        case 0:
            break;
        case 1:
            num1 = rand() % 10;
            num2 = rand() % 10;
            num3 = rand() % 10;

            cout << "���:\t[" << num1 << "]\t[" << num2 << "]\t[" << num3 << "]" << endl;

            if (is_rule_matched(num1, num2, num3))
            {
                cout << "<<<�¸�>>> (^-^)" << endl;
            }
            else
            {
                cout << "<<<�й�>>> (��_��)" << endl;
            }
            break;
        case 2:
            print_rules();
            break;
        default:
            cout << "�ش� �޴��� �����!" << endl;
            break;
        }

    } while (input != 0);

	return 0;
}

void print_rules()
{
    cout << "*** �¸� ����***" << endl;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << "\t[" << i << "]\t[" << (i + j) % 10 << "]\t[" << (i + 2 * j) % 10 << "]" << endl;
        }
    }
}

bool is_rule_matched(int num1, int num2, int num3)
{
    int num1_to_num2 = num2 - num1;
    int num2_to_num3 = num3 - num2;

    if (num1_to_num2 < 0)
    {
        num1_to_num2 += 10;
    }

    if (num2_to_num3 < 0)
    {
        num2_to_num3 += 10;
    }

    if (num1_to_num2 == num2_to_num3)
    {
        return true;
    }
    else
    {
        return false;
    }
}
