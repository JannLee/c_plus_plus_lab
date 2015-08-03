#include <iostream>

struct Number
{
	int num;
	Number* p_next;
};

Number* getNewNumber()
{
	Number* item = new Number;
	item->num = 0;
	item->p_next = NULL;
	return item;
}

void InsertNumberIterate( Number*& list, int index, Number* item )
{
	if (list == NULL || index == 0)
	{
		item->p_next = list;
		list = item;
		return;
	}

	Number* head = list;
	for (int i = 0; i < index - 1 && head != NULL; ++i)
	{
		head = head->p_next;
	}
	item->p_next = head->p_next;
	head->p_next = item;
	
}

void InsertNumberRecursive(Number*& list, int index, Number* item)
{
	if (list == NULL || index == 0)
	{
		item->p_next = list;
		list = item;
		return;
	}
	InsertNumberRecursive(list->p_next, --index, item);
}

void RemoveNumberIterate(Number*& list, int index)
{
	if (list == NULL)
	{
		return;
	}
	Number* head = list;
	if (index == 0)
	{
		list = head->p_next;
		delete head;
	}
	else
	{
		for (int i = 0; i < index - 1 && head->p_next->p_next != NULL; ++i)
		{
			head = head->p_next;
		}
		
		Number* item = head->p_next;
		head->p_next = head->p_next->p_next;
		delete item;
	}
}
void RemoveNumberRecursive(Number*& list, int index)
{
	if (list == NULL)
	{
		return;
	}
	Number* head = list;
	if (index == 0 || list->p_next == NULL)
	{
		list = head->p_next;
		delete head;
	}
	else
	{
		RemoveNumberRecursive(list->p_next, --index);
	}

}

void PrintList(Number* list)
{
	while (list != NULL)
	{
		std::cout << list->num << " ";
		list = list->p_next;
	}
	std::cout << std::endl;
}

int main()
{
	Number* list = NULL;
	for (int i = 10; i >= 0; i -= 2)
	{
		Number* item = getNewNumber();
		item->num = i;
		item->p_next = list;
		list = item;
	}
	PrintList(list);

	Number* item = getNewNumber();
	item->num = 1;
	InsertNumberRecursive(list, 3, item);
	PrintList(list);

	item = getNewNumber();
	item->num = 11;
	InsertNumberRecursive(list, 0, item);
	PrintList(list);	

	RemoveNumberIterate(list, 0);
	PrintList(list);

	RemoveNumberRecursive(list, 4);
	PrintList(list);
	
	while (list != NULL)
	{
		Number* item = list;
		list = list->p_next;
		delete item;
	}

	return 0;
}