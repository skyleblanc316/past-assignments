#ifndef BST_H
#define BST_H
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
//the structer of each node in the tree
template <class T>
struct TreeNode
{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};
//the class for Binary Search Tree (BST)
template <class T>
class BST
{
public:
	BST() { root = nullptr; } //constructor
	void insert(T x) { insert(root, x); } //insert x into the tree
	void preorderTraversal() const { preorderTraversal(root); }
	void inorderTraversal() const { inorderTraversal(root); }
	void postorderTraversal() const { postorderTraversal(root); }
	void bfsTraversal() const { bfsTraversal(root); };
	void displayTree() const { displayTree(root, 0); }
private:
	TreeNode<T>* root;
	void insert(TreeNode<T>*& treeroot, T x);
	//insert x into the subtree with root treeroot 
	void inorderTraversal(TreeNode<T>*) const;
	void preorderTraversal(TreeNode<T>*) const;
	void postorderTraversal(TreeNode<T>*) const;
	void bfsTraversal(TreeNode<T>*) const;
	void displayTree(TreeNode<T>* treeroot, int level) const;
};
template <class T>
void BST<T>::insert(TreeNode<T>*& treeroot, T x)
{
	if (treeroot == nullptr)  //reached the end of the search
	{
		TreeNode<T>* newnode = new TreeNode<T>;
		newnode->data = x;
		newnode->left = nullptr;
		newnode->right = nullptr;
		treeroot = newnode;
	}
	else
	{
		if (x == treeroot->data)
			return;
		if (x < treeroot->data)
			insert(treeroot->left, x);
		else
			insert(treeroot->right, x);
	}
}
template <class T>
void BST<T>::preorderTraversal(TreeNode<T>* treeroot) const
{
	if (treeroot != nullptr)
	{
		cout << setw(4) << treeroot->data;  //visit the node
		preorderTraversal(treeroot->left);  //visit the left subtree
		preorderTraversal(treeroot->right);  //visit the right subtree
	}
}
template <class T>
void BST<T>::inorderTraversal(TreeNode<T>* treeroot) const
{
	if (treeroot != nullptr)
	{
		inorderTraversal(treeroot->left);  //visit the left subtree
		cout << setw(4) << treeroot->data;  //visit the node
		inorderTraversal(treeroot->right);  //visit the right subtree
	}
}
template <class T>
void BST<T>::postorderTraversal(TreeNode<T>* treeroot) const
{
	if (treeroot != nullptr)
	{
		postorderTraversal(treeroot->left);  //visit the left subtree
		postorderTraversal(treeroot->right);  //visit the right subtree
		cout << setw(4) << treeroot->data;  //visit the node
	}
}
template <class T>
void BST<T>::bfsTraversal(TreeNode<T>* treeroot) const
{
	queue<TreeNode<T>*> Q;
	TreeNode<T>* current;
	if (treeroot)
	{
		Q.push(treeroot);
	}
	while (!Q.empty())
	{
		current = Q.front();
		Q.pop();
		cout << setw(4) << current->data;
		if (current->left)
			Q.push(current->left);
		if (current->right)
			Q.push(current->right);
	}
}
template <class T>
void BST<T>::displayTree(TreeNode<T >* treeroot, int level) const
{
	if (treeroot != nullptr)
	{
		displayTree(treeroot->right, level + 1);
		cout << setw(level * 6) << ' '
			<< setw(6) << treeroot->data << endl;
		displayTree(treeroot->left, level + 1);
	}
}
#endif