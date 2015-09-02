#include "vectorOfInt.h"
#include <cstring>


vectorOfInt::vectorOfInt() :
    size_(0),
    bufferSize_(32),
    buffer_(new int[32])
{
}

vectorOfInt::vectorOfInt(const size_t size) :
    size_(0),
    bufferSize_(size),
    buffer_(new int[size])
{
}

vectorOfInt::vectorOfInt(const vectorOfInt& other) :
    size_(other.size_),
    bufferSize_(other.bufferSize_),
    buffer_(new int[other.bufferSize_])
{
    std::memcpy(buffer_, other.buffer_, size_ * sizeof(int));
}

vectorOfInt::~vectorOfInt()
{
    delete[] buffer_;
}

vectorOfInt& vectorOfInt::operator=(const vectorOfInt& other)
{
    if (bufferSize_ < other.bufferSize_)
    {
        delete[] buffer_;
        buffer_ = new int[other.bufferSize_];
        bufferSize_ = other.bufferSize_;
    }

    std::memcpy(buffer_, other.buffer_, other.size_ * sizeof(int));
    size_ = other.size_;

    return *this;
}

bool vectorOfInt::get(const size_t index, int& value)
{
    if (index < size_)
    {
        value = buffer_[index];
        return true;
    }
    else
    {
        return false;
    }
}

bool vectorOfInt::set(const size_t index, const int value)
{
    if (index < size_)
    {
        buffer_[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}

void vectorOfInt::pushback(const int value)
{
    if (size_ == bufferSize_)
    {
        int* temp = new int[size_ + 32];
        std::memcpy(temp, buffer_, size_ * sizeof(int));
        delete[] buffer_;
        buffer_ = temp;
        bufferSize_ += 32;
    }

    buffer_[size_++] = value;
}

void vectorOfInt::pushfront(const int value)
{
    if (size_ == bufferSize_)
    {
        int* temp = new int[size_ + 32];
        std::memcpy(temp + 1, buffer_, size_ * sizeof(int));
        delete[] buffer_;
        buffer_ = temp;
        bufferSize_ += 32;
    }
    else
    {
        for (size_t i = size_; i > 0; --i)
        {
            buffer_[i] = buffer_[i - 1];
        }
    }

    buffer_[0] = value;
    ++size_;
}
