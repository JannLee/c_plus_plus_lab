#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;


struct Node
{
    int data;
    Node* next;
};


Node* PushNode(Node* list, const int data);
Node* PopNode(Node* list, int& data);

Node* PushLoop(Node* list, const int count);
Node* PopLoop(Node* list);

Node* PushRecursion(Node* list, const int count);
Node* PopRecursion(Node* list);


int main(void)
{
    srand(time(NULL));

    Node* list = NULL;
    int count = 0;

    cout << "Push count: ";
    cin >> count;

    list = PushLoop(list, count);
    list = PopLoop(list);

    list = PushRecursion(list, count);
    list = PopRecursion(list);

	return 0;
}


Node* PushNode(Node* list, const int data)
{
    Node* node = new Node;

    node->data = data;
    node->next = list;

    return node;
}

Node* PopNode(Node* list, int& data)
{
    Node* node = NULL;

    if (list)
    {
        data = list->data;
        node = list->next;
        delete list;
    }

    return node;
}

Node* PushLoop(Node* list, const int count)
{
    int data = 0;
    for (int i = 0; i < count; ++i)
    {
        data = rand();
        list = PushNode(list, data);
        cout << "Push by loop(" << i + 1 << "): " << data << endl;
    }

    return list;
}

Node* PopLoop(Node* list)
{
    int data = 0;

    while (list)
    {
        list = PopNode(list, data);
        cout << "Pop by loop: " << data << endl;
    }

    return list;
}

Node* PushRecursion(Node* list, const int count)
{
    if (count > 0)
    {
        int data = rand();

        list = PushNode(list, data);
        cout << "Push by recursion(" << count << "): " << data << endl;

        list = PushRecursion(list, count - 1);
    }

    return list;
}

Node* PopRecursion(Node* list)
{
    if (list)
    {
        int data = 0;

        list = PopNode(list, data);
        cout << "Pop by recursion: " << data << endl;

        list = PopRecursion(list);
    }

    return list;
}
