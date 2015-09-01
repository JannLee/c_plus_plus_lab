#include <iostream>
#include <vector>
#include <ctime>
#include "VectorSort.hpp"

using std::vector;

int main()
{
	srand(time(NULL));

	vector<int> numbers;
	for (int i = 10; i > 0; --i)
	{
		numbers.push_back(rand() % 20);
	}
	shin::print_vector(numbers);
	shin::vector_sort(numbers);
	shin::print_vector(numbers);

	vector<char> chars;
	for (int i = 25; i >= 0; --i)
	{
		chars.push_back('A' + i);
	}
	shin::print_vector(chars);
	shin::vector_sort(chars);
	shin::print_vector(chars);
	
	return 0;
}