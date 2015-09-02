

#pragma once

#define DEFAULT_DATA_SIZE 32

class vectorOfInt
{
public:
	vectorOfInt();
	vectorOfInt(size_t dataSize);
	vectorOfInt(const vectorOfInt& other);
	virtual ~vectorOfInt();

	size_t getsize() const;
	int get(size_t index) const;
	bool set(size_t index, int value);
	void pushback(int value);
	void pushfront(int value);
	int* getptr() const;

	vectorOfInt& operator=(const vectorOfInt& other);
private:
	int* data_;
	size_t dataSize_;
};

