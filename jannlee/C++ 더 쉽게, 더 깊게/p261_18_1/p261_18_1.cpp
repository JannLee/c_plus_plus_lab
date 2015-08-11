// p261_18_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <iostream>
#include <map>
#include <string>


using namespace std;


int main()
{
    map<string, string> addresses;
    map<string, string>::iterator it;

    int menuNumber = 1;
    string menuString[5] = { "����", "�߰�", "����", "������Ʈ", "�˻�" };
    string name;
    string email;

    while (menuNumber != 0)
    {
        cout << "�ּҷ�(���ϴ� ����� ���ڸ� �Է��ϼ���.)" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << "\t" << i << ". " << menuString[i] << endl;
        }
        cin >> menuNumber;

        if (menuNumber >= 0 && menuNumber < 5)
        {
            cout << "\t" << menuNumber << ". " << menuString[menuNumber] << endl;
            if (menuNumber == 0)
            {
                cout << "\t�ּҷ��� �����մϴ�." << endl;
                addresses.clear();
                break;
            }
            else
            {
                cout << "\t��  ��: ";
                cin >> name;
                it = addresses.find(name);
                if (it != addresses.end())
                {
                    email = it->second;
                }
                switch (menuNumber)
                {
                case 1:
                    if (it != addresses.end())
                    {
                        cout << "\t�̹� �߰���: �̸�(" << name << "), �̸���(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t�̸���: ";
                        cin >> email;
                        addresses[name] = email;
                        cout << "\t�߰� �Ϸ�: �̸�(" << name << "), �̸���(" << email << ")" << endl;
                    }
                    break;
                case 2:
                    if (it != addresses.end())
                    {
                        addresses.erase(name);
                        cout << "\t���� �Ϸ�: �̸�(" << name << "), �̸���(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\tã�� ����: �̸�(" << name << ")" << endl;
                    }
                    break;
                case 3:
                    if (it != addresses.end())
                    {
                        cout << "\t�̸���: ";
                        cin >> email;
                        addresses[name] = email;
                        cout << "\t������Ʈ �Ϸ�: �̸�(" << name << "), �̸���(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\tã�� ����: �̸�(" << name << ")" << endl;
                    }
                    break;
                case 4:
                    if (it != addresses.end())
                    {
                        cout << "\t�˻� �Ϸ�: �̸�(" << name << "), �̸���(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\tã�� ����: �̸�(" << name << ")" << endl;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << menuNumber << ": ���� ����Դϴ�" << endl;
        }

        cout << endl;
    }

    return 0;
}
