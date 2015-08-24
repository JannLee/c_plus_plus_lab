class vectorOfInt
{
public:
	vectorOfInt(); // 32개의 요소 벡터를 할당하는 무인수 생성자
	vectorOfInt(int size); // 초기 크기를 인수로 받는 생성자
	virtual ~vectorOfInt(); // 소멸자
	vectorOfInt& operator=(const vectorOfInt& other); // 대입 연산자
	vectorOfInt(const vectorOfInt& other); // 복사 생성자
				
	int get(int index);
	void set(int index, int value);
	void pushback(int value);
	void pushfront(int value);
	void print_array();

private:
	int* data;
	int size;
};
