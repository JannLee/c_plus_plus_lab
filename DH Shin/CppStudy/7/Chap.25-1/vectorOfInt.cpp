#include <iostream>
#include "vectorOfInt.h"

vectorOfInt::vectorOfInt()
	: data_(nullptr), size_(32)
{
	data_ = new int[size_];
	memset(data_, 0, sizeof(int) * size_);
}

vectorOfInt::vectorOfInt(int size)
	: data_(nullptr), size_(size)
{
	if (size_ >= 0)
	{
		data_ = new int[size_];
		memset(data_, 0, sizeof(int) * size_);
	}
	else
	{
		std::cout << "Out of range!" << std::endl;
	}
}

vectorOfInt::vectorOfInt(const vectorOfInt& rhs)
	: data_(nullptr), size_(0)
{
	size_ = rhs.size_;
	data_ = new int[size_];
	memcpy(data_, rhs.data_, sizeof(int) * size_);
}
vectorOfInt::~vectorOfInt()
{
	if (data_ != nullptr)
	{
		delete[] data_;
	}
}
vectorOfInt& vectorOfInt::operator=(const vectorOfInt& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	delete[] data_;
	data_ = nullptr;

	size_ = rhs.size_;
	data_ = new int[size_];
	memcpy(data_, rhs.data_, sizeof(int) * size_);
}
int vectorOfInt::get(int index)
{
	if (index > 0 && index < size_)
	{
		return data_[index];
	}
	else
	{
		std::cout << "Out of range!" << std::endl;
	}
}
void vectorOfInt::set(int index, int value)
{
	if (index > 0 && index < size_)
	{
		data_[index] = value;
	}
	else
	{
		std::cout << "Out of range!" << std::endl;
	}
}

void vectorOfInt::pushback(int value)
{
	int* dataNew = new int[size_ + 1];
	memcpy(dataNew, data_, sizeof(int) * size_);
	dataNew[size_] = value;
	delete[] data_;
	data_ = dataNew;
	++size_;
}

void vectorOfInt::pushfront(int value)
{
	int* dataNew = new int[size_ + 1];
	memcpy(dataNew + 1, data_, sizeof(int) * size_);
	dataNew[0] = value;
	delete[] data_;
	data_ = dataNew;
	++size_;
}

void vectorOfInt::printElements()
{
	for (int i = 0; i < size_; ++i)
	{
		std::cout << data_[i] << " ";
	}
	std::cout << std::endl;
}
