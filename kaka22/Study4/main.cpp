#include <iostream>
#include <string>

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
void MiroFree(char** pMiro,int size)
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
void printfMiro(char** pMiro)
{

}
int main()
{
	char** pMiro = MiroAlloc(60);


	printfMiro();
	MiroFree(pMiro, 60);
	return 0;
}