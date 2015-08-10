#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
	string key;
	string value;
	Node *p_left;
	Node *p_right;
};

Node *put(Node *tree, string key, string value);
Node *searchByKey(Node *tree, string key);
Node *searchByValue(Node *tree, string value);
Node *removeByKey(Node *tree, string key);
Node *removeMaxNode(Node *p_tree, Node *p_max_node);
Node *find_max(Node *p_tree);
Node *removeByValue(Node *tree, string value);

int main() {
	Node *searchedNode = NULL;

	Node *root = NULL;
	root = put(root, "¹éº´¹Î1", "qkfl1@estsoft.com");
	root = put(root, "¹éº´¹Î2", "qkfl2@estsoft.com");
	root = put(root, "¹éº´¹Î4", "qkfl4@estsoft.com");
	root = put(root, "¹éº´¹Î3", "qkfl3@estsoft.com");

	searchedNode = searchByValue(root, "qkfl4@estsoft.com");
	if (searchedNode != NULL) {
		cout << searchedNode->key << endl;
		cout << searchedNode->value << endl;
	}

	root = removeByKey(root, "¹éº´¹Î2");
	root = removeByValue(root, "qkfl4@estsoft.com");

	searchedNode = searchByValue(root, "qkfl4@estsoft.com");
	if (searchedNode != NULL) {
		cout << searchedNode->key << endl;
		cout << searchedNode->value << endl;
	}
}


Node *put(Node *tree, string key, string value) {
	if (tree == NULL) {
		Node *newTree = new Node;
		newTree->p_left = NULL;
		newTree->p_right = NULL;
		newTree->key = key;
		newTree->value = value;
		return newTree;
	}
	if (key < tree->key) {
		tree->p_left = put(tree->p_left, key, value);
	}
	else if (key == tree->key) {
		tree->value = value;
	}
	else {
		tree->p_right = put(tree->p_right, key, value);
	}
	return tree;
}
Node *searchByKey(Node *tree, string key) {
	if (tree == NULL) {
		return NULL;
	}
	else if (key == tree->key) {
		return tree;
	}
	else if (key < tree->key){
		return searchByKey(tree->p_left, key);
	}
	else {
		return searchByKey(tree->p_right, key);
	}
}
Node *searchByValue(Node *tree, string value) {
	if (tree == NULL) {
		return NULL;
	}
	if (value == tree->value) {
		return tree;
	}
	if (tree->p_left != NULL){
		return searchByValue(tree->p_left, value);
	}
	if (tree->p_right != NULL){
		return searchByValue(tree->p_right, value);
	}
	return NULL;
}
Node *removeMaxNode(Node *p_tree, Node *p_max_node) {
	if (p_tree == NULL) {
		return NULL;
	}
	if (p_tree == p_max_node) {
		return p_max_node->p_left;
	}
	p_tree->p_right = removeMaxNode(p_tree->p_right, p_max_node);
	return p_tree;
}
Node *removeByKey(Node *p_tree, string key) {
	if (p_tree == NULL) {
		return NULL;
	}
	if (p_tree->key == key) {
		if (p_tree->p_left == NULL) {
			Node *p_right_subtree = p_tree->p_right;
			delete p_tree;
			return p_right_subtree;
		}
		if (p_tree->p_right == NULL) {
			Node *p_left_subtree = p_tree->p_left;
			delete p_tree;
			return p_left_subtree;
		}
		Node *p_max_node = find_max(p_tree->p_left);
		p_max_node->p_left = removeMaxNode(p_tree->p_left, p_max_node);
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if (key < p_tree->key) {
		p_tree->p_left = removeByKey(p_tree->p_left, key);
	}
	else {
		p_tree->p_right = removeByKey(p_tree->p_right, key);
	}
	return p_tree;
}
Node *find_max(Node *p_tree) {
	if (p_tree == NULL) {
		return NULL;
	}
	if (p_tree->p_right == NULL) {
		return p_tree;
	}
	return find_max(p_tree->p_right);
}
Node *removeByValue(Node *p_tree, string value) {
	if (p_tree == NULL) {
		return NULL;
	}
	if (p_tree->value == value) {
		if (p_tree->p_left == NULL) {
			Node *p_right_subtree = p_tree->p_right;
			delete p_tree;
			return p_right_subtree;
		}
		if (p_tree->p_right == NULL) {
			Node *p_left_subtree = p_tree->p_left;
			delete p_tree;
			return p_left_subtree;
		}
		Node *p_max_node = find_max(p_tree->p_left);
		p_max_node->p_left = removeMaxNode(p_tree->p_left, p_max_node);
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if (p_tree->p_left != NULL) {
		p_tree->p_left = removeByValue(p_tree->p_left, value);
	}
	else if (p_tree->p_right != NULL) {
		p_tree->p_right = removeByValue(p_tree->p_right, value);
	}
	return p_tree;
}