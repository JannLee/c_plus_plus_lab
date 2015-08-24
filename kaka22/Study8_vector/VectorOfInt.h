#ifndef __VECTOROFINT_20150824_H__
#define __VECTOROFINT_20150824_H__
#pragma once


class CVectorOfInt
{
public:

	CVectorOfInt();
	CVectorOfInt(int size);
	CVectorOfInt(const CVectorOfInt& Voi);
	CVectorOfInt& operator = (const CVectorOfInt& Voi)
	{
		this->pArray_size_ = Voi.pArray_size_;
		this->pArray_ = Voi.pArray_;
		this->memcpy(pArray_, Voi.pArray_, this->pArray_size_);
	}
	~CVectorOfInt();
	void	set(int idx, int val);
	int		get(int idx);
	void	pushback(int val);
	void	pushfront(int val);
private:
	void	SetSize();
	int *	pArray_;
	int		pArray_size_;
	void	DataInit(int* pArray, int size, int val = 0);
	int *	newArray();
	void	memcpy(int* desc, int* src, int size);
	#define DefaultCount 32
};

#endif //__VECTOROFINT_20150824_H__