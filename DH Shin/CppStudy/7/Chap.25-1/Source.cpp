#include <iostream>
#include "vectorOfInt.h"

int main()
{
	vectorOfInt v1;
	vectorOfInt v2(0);

	v1.printElements();
	v1.set(3, 2);
	std::cout << v1.get(3) << std::endl;
	v1.printElements();
	v2.printElements();
	v2.pushback(1);
	v2.pushfront(2);
	v2.printElements();

	vectorOfInt v3 = v2;
	v3.printElements();
	v3 = v1;
	v3.printElements();

	return 0;
}