

#include "vectorOfInt.h"

#include <iostream>

void PrintVector(const vectorOfInt& vector);

int main()
{
	vectorOfInt test;
	size_t i = 0;

	for (i = 0; i < test.getsize(); ++i)
	{
		test.set(i, i);
	}
	PrintVector(test);
	test.set(0, 100);
	PrintVector(test);
	test.pushback(1000);
	PrintVector(test);
	test.pushfront(1001);
	PrintVector(test);

	vectorOfInt test2(test);
	PrintVector(test2);
	vectorOfInt test3;
	test3 = test;
	PrintVector(test3);

	return 0;
}

void PrintVector(const vectorOfInt& vector)
{
	size_t i = 0;

	for (i = 0; i < vector.getsize(); ++i)
	{
		std::cout << vector.get(i) << " ";
	}
	std::cout << std::endl;
}