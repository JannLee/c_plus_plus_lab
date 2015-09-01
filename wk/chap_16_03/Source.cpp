#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

int initdata = 6;

Node* Add_node(Node* list, int data);
void Add_Loop(Node* list, int count);
void Add_Recurse(Node* list, int count);


int main(void)
{
	Node* list = NULL;
	int count = 5;

	Add_Loop(list, count);
	Add_Recurse(list, count);

	return 0;
}

Node* Add_node(Node* list, int data)
{
	Node* node = new Node;
	node->data = data;
	node->next = list;

	return node;
}

void Add_Loop(Node* list, int count)
{
	int data = 0;
	for (int i = 0; i < count; ++i)
	{
		++data;
		Add_node(list, data);
		cout << "Add Loop : " << data << endl;
	}
}

void Add_Recurse(Node* list, int count)
{

	if (count > 0)
	{
		int data = initdata;

		Add_node(list, data);
		cout << "Add Recurse : " << data << endl;
		++initdata;

		Add_Recurse(list, count - 1);
	}
}