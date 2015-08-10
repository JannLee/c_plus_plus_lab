#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>

struct node
{
	std::string name;
	std::string Email;
	node* p_left;
	node* p_right;
};
node* search(node* p_tree, const std::string& SearchName);
node* insert(node* p_tree, const std::string& newName, const std::string& newEmail);
void destroy_tree(node* p_tree);
node* find_max(node* p_tree);
node* remove(node* p_tree, std::string& deleteName);

node* insert(node* p_tree, const std::string& newName, const std::string& newEmail)
{
	if (p_tree == nullptr)
	{
		node *p_new_tree = new node;
		p_new_tree->p_left = nullptr;
		p_new_tree->p_right = nullptr;
		p_new_tree->name = newName;
		p_new_tree->Email = newEmail;
		return p_new_tree;
	}

	if (newName < p_tree->name)
	{
		p_tree->p_left = insert(p_tree->p_left, newName, newEmail);
	}
	else
	{
		p_tree->p_right = insert(p_tree->p_right, newName, newEmail);
	}
	return p_tree;
}

node* search(node* p_tree, const std::string& SearchName)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	else if (SearchName.compare(p_tree->name) == 0)
	{
		return p_tree;
	}
	else if (SearchName.compare(p_tree->name) < 0)
	{
		return search(p_tree->p_left, SearchName);
	}
	else
	{
		return search(p_tree->p_right, SearchName);
	}
}

void destroy_tree(node* p_tree)
{
	if (p_tree != nullptr)
	{
		destroy_tree(p_tree->p_left);
		destroy_tree(p_tree->p_right);
		delete p_tree;
	}
}
node* find_max(node* p_tree)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	if (p_tree->p_right == nullptr)
	{
		return p_tree;
	}
	return find_max(p_tree->p_left);
}
node* remove(node* p_tree, std::string& deleteName)
{
	if (p_tree == nullptr)
	{
		return nullptr;
	}
	else if (p_tree->name == deleteName)
	{
		if (p_tree->p_left == nullptr)
		{
			node* p_right_subtree = p_tree->p_right;
			delete p_tree;
			return p_right_subtree;
		}
		if (p_tree->p_right == nullptr)
		{
			node* p_left_subtree = p_tree->p_right;
			delete p_tree;
			return p_left_subtree;
		}
		node* p_max_node = find_max(p_tree->p_left);
		p_max_node->p_left == p_tree->p_left;
		p_max_node->p_right == p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if (deleteName < p_tree->name)
	{
		p_tree->p_left = remove(p_tree->p_left, deleteName);
	}
	else
	{
		p_tree->p_right = remove(p_tree->p_right,deleteName);
	}
	return p_tree;
}

int main()
{
	node* pNode_tree_header = nullptr;

	pNode_tree_header = insert(pNode_tree_header, std::string("kds1"), std::string("123x@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds2"), std::string("1235@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds3"), std::string("1236@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds4"), std::string("1237@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds5"), std::string("1238@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds6"), std::string("1239@est.com"));
	pNode_tree_header = insert(pNode_tree_header, std::string("kds7"), std::string("1230@est.com"));

	return 0;
}