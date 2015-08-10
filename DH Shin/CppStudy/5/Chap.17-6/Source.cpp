#include <iostream>>
#include <string>

struct node
{
	std::string name;
	std::string email;
	node* p_left;
	node* p_right;
};


node* insert(node* p_tree, node* item);
node* search(node* p_tree, const std::string& key);
void destroyTree(node* p_tree);
node* remove(node* p_tree, const std::string& key);
node* update(node* p_tree, const std::string& key, const std::string& value);

void insert(node*& addressBook);
void search(node* addressBook);
void remove(node*& addressBook);
void update(node*& addressBook);

int main()
{
	node* addressBook = nullptr;
	int command = -1;

	while (command != 0)
	{
		std::cout << "Input command" << std::endl;
		std::cout << "1 : Insert\n2 : Search\n3 : Remove\n4 : Update\n0 : Exit" << std::endl;
		std::cin >> command;

		switch (command)
		{
			case 0:
				break;
			case 1:
				insert(addressBook);
				break;
			case 2:
				search(addressBook);
				break;
			case 3:
				remove(addressBook);
				break;
			case 4:
				update(addressBook);
				break;
			default:
				break;
		}
	}

	destroyTree(addressBook);

	return 0;
}

void insert(node*& addressBook)
{
	node* item = new node;
	item->p_left = item->p_right = nullptr;
	std::cout << "Input name: " << std::endl;
	std::cin >> item->name;
	std::cout << "Input email:" << std::endl;
	std::cin >> item->email;

	addressBook = insert(addressBook, item);
}
void search(node* addressBook)
{
	std::string name;

	std::cout << "Input name: " << std::endl;
	std::cin >> name;

	node* item = search(addressBook, name);

	if (item != nullptr)
	{
		std::cout << "Name : " << item->name << std::endl;
		std::cout << "Email : " << item->email << std::endl;
	}
	else
	{
		std::cout << "No data" << std::endl;
	}
}
void remove(node*& addressBook)
{
	std::string name;

	std::cout << "Input name: " << std::endl;
	std::cin >> name;

	addressBook = remove(addressBook, name);
}
void update(node*& addressBook)
{
	std::string name;
	std::string email;
	
	std::cout << "Input name: " << std::endl;
	std::cin >> name;
	std::cout << "Input email:" << std::endl;
	std::cin >> email;

	node* item = update(addressBook, name, email);
	if (item != nullptr)
	{
		std::cout << "Name : " << item->name << std::endl;
		std::cout << "Email : " << item->email << std::endl;
	}
	else
	{
		std::cout << "No data" << std::endl;
	}
}
node* insert(node* p_tree, node* item)
{
	if (p_tree == nullptr)
	{
		p_tree = item;
		return item;
	}

	if (item->name == p_tree->name)
	{
		std::cout << item->name << " already exists." << std::endl;
	}
	else if (item->name < p_tree->name)
	{
		insert(p_tree->p_left, item);
	}
	else
	{
		insert(p_tree->p_right, item);
	}
	
	return p_tree;
}
node* search(node* p_tree, const std::string& key)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	else if (key == p_tree->name)
	{
		return p_tree;
	}
	else if (key < p_tree->name)
	{
		return search(p_tree->p_left, key);
	}
	else
	{
		return search(p_tree->p_right, key);
	}
}
void destroyTree(node* p_tree)
{
	if (p_tree != nullptr)
	{
		destroyTree(p_tree->p_left);
		destroyTree(p_tree->p_right);
		delete p_tree;
	}
}

node* findMaxNode(node* p_tree)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	if (p_tree->p_right == nullptr)
	{
		return p_tree;
	}
	return findMaxNode(p_tree->p_right);
}

node* removeMaxNode(node* p_tree, node* p_max_node)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	if (p_tree == p_max_node)
	{
		return p_tree->p_left;
	}
	p_tree->p_right = removeMaxNode(p_tree->p_right, p_max_node);
	return p_tree;
}

node* remove(node* p_tree, const std::string& key)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}

	if (key == p_tree->name)
	{
		if (p_tree->p_left == nullptr)
		{
			node* p_right = p_tree->p_right;
			delete p_tree;
			return p_right;
		}
		if (p_tree->p_right == nullptr)
		{
			node* p_left = p_tree->p_left;
			delete p_tree;
			return p_left;
		}
		node* p_max_node = findMaxNode(p_tree->p_left);
		p_max_node->p_left = removeMaxNode(p_tree->p_left, p_max_node);
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if (key < p_tree->name)
	{
		p_tree->p_left = remove(p_tree->p_left, key);
	}
	else
	{
		p_tree->p_right = remove(p_tree->p_right, key);
	}
}

node* update(node* p_tree, const std::string& key, const std::string& value)
{
	node* item = search(p_tree, key);
	if (item == nullptr)
	{
		return nullptr;
	}
	item->email = value;
	return item;
}