#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

//the structure of each node in the tree
template <class T>
struct TreeNode {
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

//the class for Binary Search Tree (BST)
template <class T>
class BST {
public:
	//to be implemented

	int height(TreeNode<T>* st);
	//write a function that returns the height of the subtree rooted at the node st
	//Remember: an empty tree has height 0

	int balance(TreeNode<T>* st);
	//returns the balance of the node st
	//the balance of a node is given by
	//the difference between the heights of its left and right subtrees
	//You may assume that the height function above is implemented

//members already implemented
	BST() { root = nullptr; } //constructor, empty tree
	void insert(T x) { insert(root, x); } //insert x into the tree
	void displayTree() const { displayTree(root, 0); }

private:
	TreeNode<T>* root;
	void insert(TreeNode<T>*& treeroot, T x);
	void displayTree(TreeNode<T>* treeroot, int level) const;
};


template <class T>
void BST<T>::displayTree(TreeNode<T >* treeroot, int level) const {
	if (treeroot != nullptr) {
		displayTree(treeroot->right, level + 1);
		cout << setw(level * 6) << ' '
			<< setw(6) << treeroot->data << endl;
		displayTree(treeroot->left, level + 1);
	}
}

template <class T>
void BST<T>::insert(TreeNode<T>*& treeroot, T x) {
	if (treeroot == nullptr) {  //reached the end of the search
		TreeNode<T>* newnode = new TreeNode<T>;
		newnode->data = x;
		newnode->left = nullptr;
		newnode->right = nullptr;
		treeroot = newnode;
	}
	else {
		if (x == treeroot->data)
			return;
		if (x < treeroot->data)
			insert(treeroot->left, x);
		else
			insert(treeroot->right, x);
	}
}

template <class T>
int BST<T>::height(TreeNode<T>* st)
{
	//base case
	if (root = nullptr)
		return 0;
	else//general case
		return 1 + height(root->right);
}

template <class T>
int BST<T>::balance(TreeNode<T>* st)




#endif