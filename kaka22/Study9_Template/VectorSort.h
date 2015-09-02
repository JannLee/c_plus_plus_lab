#ifndef __VECTORSORT_H_20150901__
#define __VECTORSORT_H_20150901__
#include <vector>

namespace VectorSort
{
	template < typename T>
	void Sort(std::vector<T>& data)
	{

		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data.size() - 1; j++)
			{
				T temp = 0;
				if (data[j] > data[j + 1])
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
};


#endif // __VECTORSORT_H_20150901__