#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
typedef struct _MIRO
{
	int low;
	int High;
}MIRO;
void printMiro(char** pMiro, int size);
char** MiroAlloc(int size);
void MiroFree(char** pMiro, int size);
void printMiro(char** pMiro, int size);
int GetRandValue();



int main()
{
	int size = 10;
	char**  pMiro = MiroAlloc(size+2);
	int in=0;
	int out = 0;
	std::cout << "CreateMiroA"<<std::endl;

	do
	{
		in = (GetRandValue()+1) % size;
		out =(GetRandValue()+1) % size;
	} while (in == out || in+1 == out ||(in != 0 && in - 1 == out) );




	int widthOne = 0;
	int widthTwo = 0;
	int height = 0;
	do
	{
		widthOne = (GetRandValue()%8)+2;
		widthTwo = (GetRandValue() % 6) +3;
	} while (widthOne == widthTwo || widthTwo == 8 || widthOne == 1|| widthOne +1 == widthTwo);

	do
	{
		height = (GetRandValue() % 9);
	} while (in == height || (in + 1) == height);

	for (int i = 0; i <= size; i++)
	{
		pMiro[i][in] = 1;
		if(i < 5)
		{
			pMiro[i][out] = 1;
		}
		pMiro[widthOne][i] = 1;
		pMiro[widthTwo][i] = 1;
		pMiro[0][i] = 1;
		pMiro[size-1][i] = 1;
	}

	pMiro[0][in] = 2;
	pMiro[size - 1][out] = 2;
	printMiro(pMiro,size);
	MiroFree(pMiro, size);
	return 0;
}

char** MiroAlloc(int size)
{
	int cnt = 60;

	char** retMiro = nullptr;
	retMiro = new char*[size];

	for (int i = 0; i < size; ++i)
	{
		retMiro[i] = new char[size];
		memset(retMiro[i], 0x0, sizeof(char)*size);
	}
	return retMiro;
}
void MiroFree(char** pMiro, int size)
{
	for (int i = 0; i < size; ++size)
	{
		if (pMiro[i])
		{
			delete[] pMiro[i];
			pMiro[i] = nullptr;
		}
	}
	if (pMiro)
	{
		delete[] pMiro;
		pMiro = nullptr;
	}
}
void printMiro(char** pMiro, int size)
{
	char** pMiroPrint = pMiro;
	std::string Block;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{


			switch (pMiroPrint[i][j])
			{
			case 0:	Block = "□";/* "□"*/	break;
			case 1:	Block = "■";/* "■"*/	break;
			case 2:	Block = "★";/* "@"*/	break;
			}
			std::cout << Block;
	//		printf("[%d][%d] ", i, j);
		}
		std::cout << std::endl;
	}
}
int GetRandValue()
{
	srand(time(NULL));
	return rand();
}
/*
void GetMiroGate(MIRO* pIn, int size);
void GetMiroGate(MIRO* pIn, int size)
{
	pIn->low = (GetRandValue() % 3); // 4면 중에 한곳의 입구를 구한다.
	pIn->High = (GetRandValue() % (size - 1));
	switch (pIn->low)
	{
	case 1:
		pIn->low = (GetRandValue() % (size - 1));
		pIn->High = 0;
		break;
	case 2:
		pIn->low = (GetRandValue() % (size - 1));
		pIn->High = size - 1;
		break;
	case 3:
		pIn->low = size - 1;
		break;
	}
}
*/