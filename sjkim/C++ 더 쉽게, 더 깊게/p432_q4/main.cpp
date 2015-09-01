
#include <iostream>
#include <vector>

#include "VectorFunctions.hpp"

using namespace VectorFunctions;

int main()
{
	std::vector<int> intVector;
	std::vector<double> doubleVector;
	std::vector<short> shortVector;

	FillVector<int>(intVector);
	FillVector<double>(doubleVector);
	FillVector<short>(shortVector);

	PrintVector<int>(intVector);
	PrintVector<double>(doubleVector);
	PrintVector<short>(shortVector);

	SortVector<int>(intVector);
	SortVector<double>(doubleVector);
	SortVector<short>(shortVector);
	std::cout << std::endl;

	PrintVector<int>(intVector);
	PrintVector<double>(doubleVector);
	PrintVector<short>(shortVector);

	return 0;
}
