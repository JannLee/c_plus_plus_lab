#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string name;
	string email;
	Node* leftNode;
	Node* rightNode;
};


Node* Insert(Node* rootNode, const string& name, const string& email)
{
	if (rootNode == NULL)
	{
		Node* newNode = new Node;
		newNode->leftNode = NULL;
		newNode->rightNode = NULL;
		newNode->name = name;
		newNode->email = email;
		return newNode;
	}
	if (name < rootNode->name)
	{
		rootNode->leftNode = Insert(rootNode->leftNode, name, email);
	}
	else
	{
		rootNode->rightNode = Insert(rootNode->rightNode, name, email);
	}

	return rootNode;
}

Node* Search(Node* rootNode, string name)
{
	if (rootNode == NULL)
	{
		return NULL;
	}
	else if (name == rootNode->name)
	{
		return rootNode;
	}
	else if (name < rootNode->name)
	{
		return Search(rootNode->leftNode, name);
	}
	else
	{
		return Search(rootNode->rightNode, name);
	}
}

Node* RemoveMaxNode(Node* rootNode, Node* maxNode)
{
	if (rootNode == NULL)
	{
		return NULL;
	}

	if (rootNode == maxNode)
	{
		return maxNode->leftNode;
	}

	rootNode->rightNode = RemoveMaxNode(rootNode->rightNode, maxNode);

	return rootNode;
}

Node* FindMax(Node* rootNode)
{
	if (rootNode == NULL)
	{
		return NULL;
	}
	if (rootNode->rightNode == NULL)
	{
		return rootNode;
	}
	return FindMax(rootNode->rightNode);
}

Node* Remove(Node* rootNode, string name)
{
	if (rootNode == NULL)
	{
		return NULL;
	}
	if (rootNode->name == name)
	{
		if (rootNode->leftNode == NULL)
		{
			Node* rightNode = rootNode->rightNode;
			delete rootNode;
			return rightNode;
		}
		if (rootNode->rightNode == NULL)
		{
			Node* leftNode = rootNode->leftNode;
			delete rootNode;
			return leftNode;
		}
		Node* maxNode = FindMax(rootNode->leftNode);
		maxNode->leftNode = RemoveMaxNode(rootNode->leftNode, maxNode);
		maxNode->rightNode = rootNode->rightNode;
		delete rootNode;
		return maxNode;
	}
	else if (name < rootNode->name)
	{
		rootNode->leftNode = Remove(rootNode->leftNode, name);
	}
	else
	{
		rootNode->rightNode = Remove(rootNode->rightNode, name);
	}

	return rootNode;
}

void DestroyTree(Node* root)
{
	if (root != NULL)
	{
		DestroyTree(root->leftNode);
		DestroyTree(root->rightNode);
		delete root;
	}
}

int main()
{
	Node* root = NULL;
	string command = "";
	string inputName = "";
	string inputEmail = "";

	cout << "COMMAND(add, del, find, quit) : ";
	getline(cin, command);

	while (command != "quit")
	{
		if (command == "add")
		{
			cout << "NAME : ";
			getline(cin, inputName);
			cout << "EMAIL : ";
			getline(cin, inputEmail);
			root = Insert(root, inputName, inputEmail);
		}
		else if (command == "del")
		{
			cout << "NAME : ";
			getline(cin, inputName);
			root = Remove(root, inputName);
		}
		else if (command == "find")
		{
			cout << "NAME : ";
			getline(cin, inputName);
			Node* node = Search(root, inputName);
			if (node)
			{
				cout << "RESULT : " << node->email << endl;
			}
			else
			{
				cout << "Not found" << endl;
			}
		}

		cout << "COMMAND(add, del, find, quit) : ";
		getline(cin, command);
	}

	DestroyTree(root);
}
