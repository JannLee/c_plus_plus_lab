
#include "vectorOfInt.h"

#include <stdlib.h>
#include <string.h>

vectorOfInt::vectorOfInt()
{
	dataSize_ = DEFAULT_DATA_SIZE;
	data_ = reinterpret_cast<int*>(malloc(dataSize_ * sizeof(int)));
}

vectorOfInt::vectorOfInt(size_t dataSize)
{
	dataSize_ = dataSize;
	data_ = reinterpret_cast<int*>(malloc(dataSize_ * sizeof(int)));
}

vectorOfInt::vectorOfInt(const vectorOfInt& other)
{
	dataSize_ = other.getsize();
	data_ = reinterpret_cast<int*>(malloc(dataSize_ * sizeof(int)));
	memcpy(data_, other.getptr(), dataSize_ * sizeof(int));
}

vectorOfInt::~vectorOfInt()
{
	if (data_ != NULL)
	{
		free(data_);
	}
}

size_t vectorOfInt::getsize() const
{
	return dataSize_;
}

int vectorOfInt::get(size_t index) const
{
	if (data_ == NULL || index >= dataSize_)
	{
		return -1;
	}

	return data_[index];
}

bool vectorOfInt::set(size_t index, int value)
{
	if (data_ == NULL || index >= dataSize_)
	{
		return false;
	}

	data_[index] = value;
	return true;
}

void vectorOfInt::pushback(int value)
{
	++dataSize_;
	data_ = reinterpret_cast<int*>(realloc(data_, dataSize_ * sizeof(int)));
	data_[dataSize_ - 1] = value;
}

void vectorOfInt::pushfront(int value)
{
	++dataSize_;
	data_ = reinterpret_cast<int*>(realloc(data_, dataSize_ * sizeof(int)));
	memcpy(data_ + 1, data_, (dataSize_ - 1) * sizeof(int));
	data_[0] = value;
}

int* vectorOfInt::getptr() const
{
	return data_;
}

vectorOfInt& vectorOfInt::operator=(const vectorOfInt& other)
{
	if (dataSize_ != other.getsize())
	{
		dataSize_ = other.getsize();
		data_ = reinterpret_cast<int*>(realloc(data_, dataSize_ * sizeof(int)));
	}
	memcpy(data_, other.getptr(), dataSize_ * sizeof(int));

	return *this;
}