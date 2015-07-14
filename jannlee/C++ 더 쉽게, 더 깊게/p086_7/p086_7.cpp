#include <iostream>

using namespace std;

int main(void)
{
    int input = 0, item1 = 0, item2 = 0, item3 = 0;

    do
    {
        cout << "Select items (0: exit)" << endl;
        for (int i = 0; i < 3; ++i)
        {
            cout << "\tItem " << i + 1 << endl;
        }

        cin >> input;
        if (input == 1)
        {
            ++item1;
        }
        else if (input == 2)
        {
            ++item2;
        }
        else if (input == 3)
        {
            ++item3;
        }
        else if (input == 0)
        {
            cout << "Item 1: ";
            for (int i = 0; i < item1; ++i)
            {
                cout << "|";
            }
            cout << endl;
            cout << "Item 2: ";
            for (int i = 0; i < item2; ++i)
            {
                cout << "|";
            }
            cout << endl;
            cout << "Item 3: ";
            for (int i = 0; i < item3; ++i)
            {
                cout << "|";
            }
            cout << endl;
            break;
        }
        else
        {
            cout << "Item " << input << " is not exist." << endl;
        }
    } while (input != 0);

	return 0;
}
