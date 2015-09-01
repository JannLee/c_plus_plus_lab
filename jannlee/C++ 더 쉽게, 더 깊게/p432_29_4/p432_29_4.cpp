// p432_29_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <vector>
#include "VectorSort.hpp"

int main()
{
    std::vector<int> a;

    a.push_back(100);
    a.push_back(10);
    a.push_back(3);
    a.push_back(7);
    a.push_back(56);
    a.push_back(453);
    a.push_back(3);
    a.push_back(88);
    a.push_back(23);
    a.push_back(75);

    std::vector<float> b;

    b.push_back(100);
    b.push_back(10);
    b.push_back(3);
    b.push_back(7);
    b.push_back(56);
    b.push_back(453);
    b.push_back(3);
    b.push_back(88);
    b.push_back(23);
    b.push_back(75);


    jannlee::quickSort(a);
    jannlee::quickSort(b);

    return 0;
}

