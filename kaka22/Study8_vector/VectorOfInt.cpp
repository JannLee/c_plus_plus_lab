#include "VectorOfInt.h"


CVectorOfInt::CVectorOfInt()
	:pArray_(nullptr)
	, pArray_size_(0)
{
	pArray_ = new int[DefaultCount];
	pArray_size_ = DefaultCount;
	
	DataInit(pArray_, pArray_size_);
}
CVectorOfInt::CVectorOfInt(int size)
	: pArray_(nullptr)
	, pArray_size_(0)
{
	int Csize = size;
	if (Csize < 0)
	{
		Csize = DefaultCount;
	}
	pArray_ = new int[Csize];
	pArray_size_ = Csize;
	DataInit(pArray_, pArray_size_);
}
CVectorOfInt::CVectorOfInt(const CVectorOfInt& Voi)
	: pArray_(nullptr)
	, pArray_size_(0)
{
	this->pArray_size_ = Voi.pArray_size_;
	this->pArray_ = Voi.pArray_;
	this->memcpy(pArray_, Voi.pArray_, this->pArray_size_);
}
CVectorOfInt::~CVectorOfInt()
{
	delete pArray_;
}
void	CVectorOfInt :: set(int idx,int val)
{
	if (pArray_size_ > idx-1)
	{
		pArray_[idx - 1] = val;
	}
		
}
int		CVectorOfInt :: get(int idx)
{
	if (pArray_size_ > idx - 1)
	{
		return pArray_[idx - 1];
	}
	return 0;
}
void	CVectorOfInt::pushback(int val)
{
	this->SetSize();
	int* pNewArray = new int[pArray_size_];

	pNewArray[pArray_size_-1] = val;
	memcpy(&pNewArray[0], this->pArray_, this->pArray_size_-1);

	delete this->pArray_;
	pArray_ = nullptr;
	pArray_ = pNewArray;
}
void	CVectorOfInt::SetSize()
{
	pArray_size_++;
}
void	CVectorOfInt::pushfront(int val)
{
	this->SetSize();
	int* pNewArray = new int[pArray_size_];
	
	pNewArray[0] = val;
	memcpy(&pNewArray[1], this->pArray_, this->pArray_size_-1);
	
	delete this->pArray_;
	pArray_ = nullptr;
	pArray_ = pNewArray;
}


void	CVectorOfInt::DataInit(int* pArray, int size,int val)
{
	for (int i = 0; i < size; i++)
	{
		pArray[i] = val;
	}
}
void	CVectorOfInt::memcpy(int* desc, int* src, int size)
{
	for (int i = 0; i < size; i++)
	{
		desc[i] = src[i];
	}
}