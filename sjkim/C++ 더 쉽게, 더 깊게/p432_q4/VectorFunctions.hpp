
#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>

namespace VectorFunctions
{

template <typename T> void SortVector(std::vector<T>& vec);
template <typename T> void PrintVector(const std::vector<T>& vec);

template <typename T>
void SortVector(std::vector<T>& vec)
{
	size_t i = 0;
	size_t j = 0;
	size_t vecSize = vec.size();

	for (i = 0; i < vecSize - 1; ++i)
	{
		for (j = 0; j < vecSize - 1 - i; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				T temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
	typename std::vector<T>::const_iterator it;

	for (it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

template <typename T>
void FillVector(std::vector<T>& vec)
{
	int i = 0;

	for (i = 0; i < 10; ++i)
	{
		vec.push_back(rand());
	}
}

}
