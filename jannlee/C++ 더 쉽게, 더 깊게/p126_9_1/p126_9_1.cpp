#include <iostream>
#include <string>


using namespace std;


int print_negative(int number);
void print_space(int number);
void print_units(int number);
void print_tens(int number);
void print_hundreds(int number);

int main(void)
{
    int number = 0;
    int hundred = 0;

    do
    {
        cout << "-999,999 ~ 999,999 사이의 수를 입력하세요.(Ctrl+Z: 종료)" << endl;
        cin >> number;

        if (!cin.eof())
        {
            if (number >= -999999 && number <= 999999)
            {
                number = print_negative(number);

                hundred = number / 1000;
                number %= 1000;
                if (hundred > 0)
                {
                    print_hundreds(hundred);
                    cout << " thousand";
                    print_space(number);;
                }

                print_hundreds(number);
                cout << endl;
            }
            else
            {
                cout << number << "는 -999,999 ~ 999,999에 속하지 않습니다." << endl;
            }
        }
        else
        {
            break;
        }
    } while (!cin.eof());

	return 0;
}

int print_negative(int number)
{
    if (number < 0)
    {
        cout << "minus";
        number = -number;
        print_space(number);
    }

    return number;
}

void print_space(int number)
{
    if (number != 0)
    {
        cout << " ";
    }
}

void print_units(int number)
{
    switch (number)
    {
    case 0:
        cout << "zero";
        break;
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    case 5:
        cout << "five";
        break;
    case 6:
        cout << "six";
        break;
    case 7:
        cout << "seven";
        break;
    case 8:
        cout << "eight";
        break;
    case 9:
        cout << "nine";
        break;
    default:
        break;
    }
}

void print_small_tens(int number)
{
    switch (number)
    {
    case 10:
        cout << "ten";
        break;
    case 11:
        cout << "eleven";
        break;
    case 12:
        cout << "twelve";
        break;
    case 13:
        cout << "thirteen";
        break;
    case 14:
        cout << "fourteen";
        break;
    case 15:
        cout << "fifteen";
        break;
    case 16:
        cout << "sixteen";
        break;
    case 17:
        cout << "seventeen";
        break;
    case 18:
        cout << "eightteen";
        break;
    case 19:
        cout << "nineteen";
        break;
    default:
        break;
    }
}

void print_large_tens(int number)
{
    int unit = number % 10;

    switch (number / 10)
    {
    case 2:
        cout << "twenty";
        print_space(unit);
        break;
    case 3:
        cout << "thirty";
        print_space(unit);
        break;
    case 4:
        cout << "fourty";
        print_space(unit);
        break;
    case 5:
        cout << "fifty";
        print_space(unit);
        break;
    case 6:
        cout << "sixty";
        print_space(unit);
        break;
    case 7:
        cout << "seventy";
        print_space(unit);
        break;
    case 8:
        cout << "eighty";
        print_space(unit);
        break;
    case 9:
        cout << "ninety";
        print_space(unit);
        break;
    default:
        break;
    }

    if (unit > 0)
    {
        print_units(unit);
    }
}

void print_tens(int number)
{

    if (number >= 10)
    {
        if (number <= 19)
        {
            print_small_tens(number);
        }
        else
        {
            print_large_tens(number);
        }
    }
    else
    {
        print_units(number);
    }
}

void print_hundreds(int number)
{
    int unit = number / 100;

    if (unit > 0)
    {
        print_units(unit);
        cout << " hundred";
        number %= 100;
        print_space(number);
    }

    print_tens(number);
}
