#include <iostream>
#include <string>


typedef struct _LinkedList
{
	int idx;
	_LinkedList* p_next;
}LinkedList, *pLinkedList;

LinkedList* g_pHead = nullptr;

LinkedList* LoopAdd(int idx)
{

	LinkedList* getHead = g_pHead;
	LinkedList* pAdd = nullptr;
	while (true)
	{
		if (getHead->p_next)
		{
			getHead = getHead->p_next;
		}
		else if (getHead->p_next == nullptr)
		{
			pAdd= new LinkedList;

			pAdd->idx = idx;
			pAdd->p_next = nullptr;

			getHead->p_next = pAdd;

			break;
		}
	}
	return pAdd;
}

void LoopDel(int idx)
{
	LinkedList* getHead = g_pHead;
	
	do
	{
		if (getHead->idx == idx)
		{
			LinkedList* getNext = nullptr;
			if (getHead->p_next->p_next != nullptr)
				getNext = getHead->p_next->p_next;

			delete getHead->p_next;
			getHead->p_next = nullptr;

			getHead->p_next = getNext; // 링크르 끊어서 붙임
			break;
		}
		else
		{
			getHead = getHead->p_next;
		}

	} while (getHead->p_next != nullptr);
}


void recurrenceDel			(LinkedList* pList,int idx)
{
	LinkedList* pCurrentList = pList;
	if (pCurrentList->idx == idx)
	{
		LinkedList* getNext = nullptr;
		if (pCurrentList->p_next->p_next != nullptr)
			getNext = pCurrentList->p_next->p_next;

		delete pCurrentList->p_next;
		pCurrentList->p_next = nullptr;

		pCurrentList->p_next = getNext; // 링크르 끊어서 붙임
	}
	else
	{
		recurrenceDel(pList->p_next, idx);
	}
}
LinkedList* recurrenceAdd	(LinkedList* pList, int idx)
{
	LinkedList* pNewList = nullptr;

	if (pList->p_next != nullptr)
	{
		recurrenceAdd(pList->p_next, idx);
	}
	else
	{
		pNewList = new LinkedList;
		pNewList->idx = idx;
		pNewList->p_next = nullptr;

		pList->p_next = pNewList;
	}
	return pNewList;
}

int main()
{
	int A = 1;
	int B = 1;
	int C = 1;
	int D = 0;
	if ((A == 2 && B = 2) || (C && B = 1) || (B = 0))
	{
		D = A + B + C;
	}

	return 0;
}