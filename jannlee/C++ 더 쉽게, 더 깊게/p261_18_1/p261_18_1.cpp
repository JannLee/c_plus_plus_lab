// p261_18_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
    string menuString[5] = { "종료", "추가", "제거", "업데이트", "검색" };
    string name;
    string email;

    while (menuNumber != 0)
    {
        cout << "주소록(원하는 기능의 숫자를 입력하세요.)" << endl;
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
                cout << "\t주소록을 삭제합니다." << endl;
                addresses.clear();
                break;
            }
            else
            {
                cout << "\t이  름: ";
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
                        cout << "\t이미 추가됨: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t이메일: ";
                        cin >> email;
                        addresses[name] = email;
                        cout << "\t추가 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    break;
                case 2:
                    if (it != addresses.end())
                    {
                        addresses.erase(name);
                        cout << "\t제거 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                case 3:
                    if (it != addresses.end())
                    {
                        cout << "\t이메일: ";
                        cin >> email;
                        addresses[name] = email;
                        cout << "\t업데이트 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                case 4:
                    if (it != addresses.end())
                    {
                        cout << "\t검색 완료: 이름(" << name << "), 이메일(" << email << ")" << endl;
                    }
                    else
                    {
                        cout << "\t찾지 못함: 이름(" << name << ")" << endl;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << menuNumber << ": 없는 기능입니다" << endl;
        }

        cout << endl;
    }

    return 0;
}
