// p359_25_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "vectorOfInt.h"


int main()
{
    vectorOfInt v1;
    vectorOfInt v2(3);

    v1.pushback(10);
    v1.pushback(200);
    v1.pushfront(5);
    v1.pushfront(7);

    int value = 0;
    
    if (v1.get(3, value))
    {
        v1.set(4, -1);
    }

    v2.pushback(10);
    v2.pushback(300);
    v2.pushfront(6);
    v2.pushfront(8);

    return 0;
}

