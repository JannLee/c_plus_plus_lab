#include <iostream>
#include <vector>

namespace shin {
	template<class T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<class T>
	void vector_sort(std::vector<T>& v)
	{
		int size = v.size();
		for (int i = 1; i < size; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
				else
				{
					break;
				}
			}
		}
	}

	template<class T>
	void print_vector(const std::vector<T>& v)
	{
		int size = v.size();
		for (int i = 0; i < size; ++i)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
}