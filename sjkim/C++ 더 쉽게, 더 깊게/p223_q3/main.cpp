#include <iostream>
#include <string>
#include <cstdlib>

#define USE_RECURSIVE 1

using namespace std;

struct ListItem
{
	int value;
	ListItem* nextItem;
};

void PrintList(const ListItem* head)
{
	const ListItem* item = head;

	if (item == nullptr)
	{
		cout << "empty" << endl;
		return;
	}

	while (item != nullptr)
	{
		cout << item->value << " ";
		item = item->nextItem;
	}

	cout << endl;
}

void Add(ListItem** ppHead, int number)
{
	ListItem* item = nullptr;

	if (ppHead == nullptr)
	{
		return;
	}
	item = *ppHead;

	while (rand() % 7 != 0)
	{
		if (item == nullptr)
		{
			item = *ppHead;
		}
		else
		{
			item = item->nextItem;
		}
	}

	ListItem* newItem = new ListItem;
	newItem->value = number;
	if (item != nullptr)
	{
		newItem->nextItem = item->nextItem;
		item->nextItem = newItem;
	}
	else
	{
		newItem->nextItem = *ppHead;
		*ppHead = newItem;
	}
}

#if USE_RECURSIVE
ListItem* Del(ListItem* item, int number)
{
	ListItem* nextItem = nullptr;

	if (item == nullptr)
	{
		return nullptr;
	}

	nextItem = Del(item->nextItem, number);
	if (item->value == number)
	{
		delete item;
		item = nextItem;
	}
	else
	{
		item->nextItem = nextItem;
	}

	return item;
}
#else
void Del(ListItem** ppHead, int number)
{
	ListItem* item = nullptr;
	ListItem* prevItem = nullptr;

	if (ppHead == nullptr)
	{
		return;
	}
	item = *ppHead;

	while (item != nullptr)
	{
		if (item->value == number)
		{
			if (item == *ppHead)
			{
				*ppHead = item->nextItem;
				delete item;
				item = *ppHead;
			}
			else
			{
				prevItem->nextItem = item->nextItem;
				delete item;
				item = prevItem->nextItem;
			}
		}
		else
		{
			prevItem = item;
			item = item->nextItem;
		}
	}
}
#endif // USE_RECURSIVE

int main()
{
	string input = "";
	int inputNumber = 0;
	ListItem* head = nullptr;

	while (input != "quit")
	{
		PrintList(head);
		cin >> input;
		if (input == "add")
		{
			cin >> inputNumber;
			Add(&head, inputNumber);
		}
		else if (input == "del")
		{
			cin >> inputNumber;
#if USE_RECURSIVE
			head = Del(head, inputNumber);
#else
			Del(&head, inputNumber);
#endif // USE_RECURSIVE
		}
	}

	return 0;
}
