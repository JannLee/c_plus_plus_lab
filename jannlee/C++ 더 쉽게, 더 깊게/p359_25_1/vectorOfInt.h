#pragma once
class vectorOfInt
{
public:
    vectorOfInt();
    vectorOfInt(const size_t size);
    vectorOfInt(const vectorOfInt& other);
    virtual ~vectorOfInt();

    vectorOfInt& operator=(const vectorOfInt& other);

    bool get(const size_t index, int& value);
    bool set(const size_t index, const int value);
    void pushback(const int value);
    void pushfront(const int value);


private:
    size_t size_;
    size_t bufferSize_;
    int* buffer_;
};
