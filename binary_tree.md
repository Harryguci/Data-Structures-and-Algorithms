# Set up a binary tree class in C++

```C++
#include <iostream>
#include <string>

using namespace std;

template<class T>
class node {
private:
	T value;
	node* left, *right;

public:
	node() {
		right = left = NULL;
	}

	node(T value) {
		this->value = value;
		right = left = NULL;
	}
	node(T value,node* left, node* right) {
		this->value = value;
		this->right = right;
		this->left = left;
	}

	void setRight(node* p) {
		right = p;
	}
	void setLeft(node* p) {
		left = p;
	}
	node* getRight() {
		return right;
	}
	node* getLeft() {
		return left;
	}
	T& getElem() {
		return this->value;
	}

	T operator*() {
		return value;
	}
};

template<class T>
class binaryTree {
private:
	node<T>* head;
	int num = 0;
public:
	typedef node<T> node;

	binaryTree() {
		head = NULL;
	}

	binaryTree(T value) {
		head = new node(value, 0, 0);
	}
	int size() {
		return num;
	}
	bool empty() {
		return size() == 0;
	}
	node* getHead() {
		return head;
	}
	
	node* insert(node* curr, T value) {
		if (head == NULL) {
			head = new node(value, 0, 0);
			num++;
			return head;
		}
		if (curr == NULL) {
			curr = new node(value, 0, 0);
			num++;
			return curr;
		}
		else if(curr->getElem() > value) {
			curr->setLeft(insert(curr->getLeft(), value));
		}
		else
			curr->setRight(insert(curr->getRight(), value));
	}
	void inOrder(node* curr) {
		if (curr == NULL)
			return;

		inOrder(curr->getLeft());
		cout << curr->getElem() << " ";
		inOrder(curr->getRight());
	}
	void preOrder(node* curr) {
		if (curr == NULL)
			return;

		cout << curr->getElem() << " ";
		inOrder(curr->getLeft());
		inOrder(curr->getRight());
	}
	void postOrder(node* curr) {
		if (curr == NULL)
			return;

		inOrder(curr->getLeft());
		inOrder(curr->getRight());
		cout << curr->getElem() << " ";
	}
};

int main() {
	
	binaryTree<int> tree;
	tree.insert(tree.getHead(), 5);
	tree.insert(tree.getHead(), 3);
	tree.insert(tree.getHead(), 4);
	tree.insert(tree.getHead(), 7);
	tree.insert(tree.getHead(), 6);
	tree.insert(tree.getHead(), 10);

	tree.inOrder(tree.getHead());

	return 0;
}
```