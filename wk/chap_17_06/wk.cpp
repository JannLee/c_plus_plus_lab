#include <iostream>
#include <string>

using namespace std;


struct node
{
	string name;
	string email;
	node *p_left;
	node *p_right;
};


node *insert(node *p_tree, string &name, string &email);
node *search(node *p_tree, string key);
node *remove(node *p_tree, string key);
node *update(node *p_tree, string key, string email);
void destroy_tree(node *root);

int main()
{
	node *AddressBook = NULL;

	string name = NULL;
	string email = NULL;
	
	int input = 0;
	while (input < 5)
	{
		cout << "Select command" << endl;
		cout << "1 : Insert" << endl;
		cout << "2 : Remove" << endl;
		cout << "3 : Update" << endl;
		cout << "4 : Search" << endl;
		cout << "5 : Exit" << endl;
		cin >> input;
		system("cls");

		if (input == '1')
		{
			cout << "Name ? : ";
			cin >> name;
			cout << "Email ? : ";
			cin >> email;
			AddressBook = insert(AddressBook, name, email);
		}
		else if (input == '2')
		{
			cout << "Name ? : ";
			cin >> name;
			AddressBook = remove(AddressBook, name);
		}
		else if (input == '3')
		{
			cout << "Name ? : ";
			cin >> name;
			cout << "Email ? : ";
			cin >> email;
			AddressBook = update(AddressBook, name, email);
		}
		else if (input == '4')
		{
			cout << "Name ? : ";
			cin >> name;
			node *node = search(AddressBook, name);
			if (node)
			{
				cout << "Email : " << node->email << endl;
			}
			else
			{
				cout << "can't find name.." << endl;
			}
		}
		else if (input == '5')
		{
			destroy_tree(AddressBook);
		}
		
	}

}

node *insert(node *p_tree, string &name, string &email)
{
	if (p_tree == NULL)
	{
		node *p_new_tree = new node;
		p_new_tree->p_left = NULL;
		p_new_tree->p_right = NULL;
		p_new_tree->name = name;
		p_new_tree->email = email;
		return p_new_tree;
	}

	if (name < p_tree->name)
	{
		p_tree->p_left = insert(p_tree->p_left, name, email);
	}
	else
	{
		p_tree->p_right = insert(p_tree->p_right, name, email);
	}
}

node *search(node *p_tree, string name)
{
	if (p_tree == NULL)
	{
		return NULL;
	}
	else if (name == p_tree->name)
	{
		return p_tree;
	}
	else if (name < p_tree->name)
	{
		return search(p_tree->p_left, name);
	}
	else
	{
		return search(p_tree->p_right, name);
	}
}

node *find_max(node *p_tree)
{
	if (p_tree == NULL)
	{
		return NULL;
	}
	if (p_tree->p_right == NULL)
	{
		return p_tree;
	}
	return find_max(p_tree->p_right);
}

node *remove_max_node(node *p_tree, node *p_max_node)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	if (p_tree == p_max_node)
	{
		return p_tree->p_left;
	}
	p_tree->p_right = remove_max_node(p_tree->p_right, p_max_node);
	return p_tree;
}

node *remove(node *p_tree, string name)
{
	if (p_tree == NULL)
	{
		return NULL;
	}
	if (p_tree->name == name)
	{
		if (p_tree->p_left == NULL)
		{
			node* p_right = p_tree->p_right;
			delete p_tree;
			return p_right;
		}
		if (p_tree->p_right == NULL)
		{
			node* p_left = p_tree->p_left;
			delete p_tree;
			return p_left;
		}
		node* p_max_node = find_max(p_tree->p_left);
		p_max_node->p_left = remove_max_node(p_tree->p_left, p_max_node);
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if (name < p_tree->name)
	{
		p_tree->p_left = remove(p_tree->p_left, name);
	}
	else
	{
		p_tree->p_right = remove(p_tree->p_right, name);
	}

	return p_tree;
}
node *update(node *p_tree, string name, string email)
{
	node* item = search(p_tree, name);
	item->email = email;

	return p_tree;
}

void destroy_tree(node *p_tree)
{
	if (p_tree != NULL)
	{
		destroy_tree(p_tree->p_left);
		destroy_tree(p_tree->p_right);
		delete p_tree;
	}
}
