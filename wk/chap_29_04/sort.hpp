#include <vector>



namespace wk{
	template<typename T>
	void swap(T &a, T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template<typename T>
	void sort(std::vector<T> &v)
	{
		int minidx;
		int size = v.size();
		for (int i = 1; i < size - 1; ++i)
		{
			minidx = 1;

			for (int j = i; j < size; ++j)
			{
				if (v[i] > v[j])
				{
					minidx = j;
				}
			}

			swap(v[i], v[minidx]);
		}
	}
}
