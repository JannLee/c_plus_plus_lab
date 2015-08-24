class vectorOfInt
{
public:
	vectorOfInt(); // 32���� ��� ���͸� �Ҵ��ϴ� ���μ� ������
	vectorOfInt(int size); // �ʱ� ũ�⸦ �μ��� �޴� ������
	virtual ~vectorOfInt(); // �Ҹ���
	vectorOfInt& operator=(const vectorOfInt& other); // ���� ������
	vectorOfInt(const vectorOfInt& other); // ���� ������
				
	int get(int index);
	void set(int index, int value);
	void pushback(int value);
	void pushfront(int value);
	void print_array();

private:
	int* data;
	int size;
};
