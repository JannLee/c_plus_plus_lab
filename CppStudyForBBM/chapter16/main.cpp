#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
	Node* before;
	int data;
	Node* next;
};

void print(Node* root) {
	while (root != NULL) {
		cout << (*root).data << endl;
		root = root->next; 
	}
}
void recAdd(Node* root, int data) {
	if (root->next == NULL) {
		Node* i = new Node;
		i->data = data;
		root->next = i;
		i->before = root;
		i->next = NULL;
	}
	else {
		recAdd(root->next, data);
	}
}
void recRemove(Node* root, int data) {
	if (root == NULL) {
		return;
	}
	if (root->data == data) {
		if (root->next != NULL)
			root->next->before = root->before;
		if (root->before != NULL)
			root->before->next = root->next;
	}
	else {
		recRemove(root->next, data);
	}
}
void loopAdd(Node* root, int data) {
	Node* temp = root;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	Node* i = new Node;
	i->data = data;
	temp->next = i;
	i->before = temp;
	i->next = NULL;
}
void loopRemove(Node* root, int data) {
	Node* temp = root;
	while (temp->next != NULL) {
		if (temp->data == data) {
			if (temp->next != NULL)
				temp->next->before = temp->before;
			if (temp->before != NULL)
				temp->before->next = temp->next;
			break;
		}
		temp = temp->next;
	}
}
int main() {
	Node root;
	root.before = NULL;
	root.data = 1;
	root.next = NULL;
	loopAdd(&root, 2);
	recAdd(&root, 3);
	loopAdd(&root, 4);
	recAdd(&root, 5);
	print(&root);
	cout << endl;
	recRemove(&root, 2);
	loopRemove(&root, 3);
	print(&root);
	return 0;
}