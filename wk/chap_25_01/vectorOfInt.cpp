#include <iostream>
#include "vectorOfInt.h"

using namespace std;

vectorOfInt::vectorOfInt()
: data(nullptr), size(32)
{
	data = new int[size];
	memset(data, 0, sizeof(int) * size);
}

vectorOfInt::vectorOfInt(int size)
: data(nullptr), size(size)
{
	data = new int[size];
	memset(data, 0, sizeof(int) * size);
}


vectorOfInt::~vectorOfInt()
{
	if (data != nullptr)
	{
		delete[] data;
	}
}

vectorOfInt& vectorOfInt::operator=(const vectorOfInt& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] data;
	size = other.size;
	data = new int[size];
	memcpy(data, other.data, sizeof(int) * size);
}

int vectorOfInt::get(int index)
{
	return data[index];
}

void vectorOfInt::set(int index, int value)
{
	data[index] = value;
}

void vectorOfInt::pushback(int value)
{
	int* new_data = new int[size + 1];
	memcpy(new_data, data, sizeof(int) * size);
	new_data[size] = value;
	data = new_data;
	++size;
	
	delete[] data;
}

void vectorOfInt::pushfront(int value)
{
	int* new_data = new int[size + 1];
	memcpy(new_data + 1, data, sizeof(int) * size);
	new_data[0] = value;
	data = new_data;
	++size;
	
	delete[] data;
}

void vectorOfInt::print_array()
{
	cout << endl << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}