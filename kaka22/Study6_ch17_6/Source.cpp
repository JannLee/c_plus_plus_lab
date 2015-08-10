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

	if (newName.size() < p_tree->name.size()  )
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
		p_max_node->p_left = p_tree->p_left;
		p_max_node->p_right = p_tree->p_right;
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
	int selec = 0;
	std::string node_value;
	std::string node_mail;
	node *p_root = NULL;

	while (true)
	{
		std::cout << " 1. 추가 \n 2. 삭제 \n 3. 검색 \n 4. 전체 삭제\n 5. 종료\n";
		std::cin >> selec;
		switch (selec)
		{
		case 1:
			std::cout << "이름: ";
			std::cin >> node_value;
			std::cout << "메일: ";
			std::cin >> node_mail;
			p_root = insert(p_root, node_value, node_mail);
			break;
		case 2:
			std::cin >> node_value;
			p_root = remove(p_root, node_value);
			break;
		case 4:
			destroy_tree(p_root);
			p_root = NULL;
			break;
		case 3:
			// add an extra scope in order to declare p_search_node
			// without leaking it beyond  the case statement
		{
			std::cout << "무엇을 찾으시겠소?: ";
			std::cin >> node_value;
			node* p_search_node = search(p_root, node_value);
			if (p_search_node != NULL)
			{
				std::cout << p_search_node->Email.c_str() << std::endl;
			}
			else
			{
				std::cout << "검색 결과 없음" << std::endl;
			}
		}
		break;
		case 5:
			return 0;
		}
	}
}