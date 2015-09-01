#ifndef VECTOR_OF_INT_H
#define VECTOR_OF_INT_H
class vectorOfInt
{
public:
	vectorOfInt();
	vectorOfInt(int size);
	vectorOfInt(const vectorOfInt& other);
	virtual ~vectorOfInt();
	vectorOfInt& operator=(const vectorOfInt& other);

	int get(int index);
	void set(int index, int value);

	void pushback(int value);
	void pushfront(int value);

	void printElements();

private:
	int* data_;
	int size_;
};

#endif // VECTOR_OF_INT_H