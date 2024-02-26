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
	//implement the search function 
	bool search(T x) const { return search(root, x); };
	//implement search non-recursively
	bool search2(T x) const;
	void preorderTraversal() const { preorderTraversal(root); }
	void inorderTraversal() const { inorderTraversal(root); }
	void postorderTraversal() const { postorderTraversal(root); }
	void bfsTraversal() const { bfsTraversal(root); };
	void displayTree() const { displayTree(root, 0); }
	//hw 1
	//write a function that return the largest element in the  BST tree  (non-recursively)
	//hw 2
	//write a function that returns the # of leaves in the BST tree
	//hw 3
	//write a function that return the sum of all the nodes in the tree
	//assume that data is numeric
	//Problem 2
	//write a function that returns the # of nodes on a tree
		int size() const { return size(root); }
	//Problem 3
	//write a function that returns the # of nodes that have exactly 1 child
	int numOneChildNodes() const { return numOneChildNodes(root); }
	//Problem 4
	//write a function that returns the height of a tree
	int height() const { return height(root); }
	//Problem 5
	//implement the destructor 
	~BST() { destroyTree(root); }
private:
	TreeNode<T>* root;
	void destroyTree(TreeNode<T>* treeroot) //deallocate the memory for the subtree treeroot
	{
		if (treeroot) //not empty
		{
			destroyTree(treeroot->left); //delete the left
			destroyTree(treeroot->right);
			delete treeroot; //after deleting the children, delete the root
		}
	};
	int height(TreeNode<T>* treeroot) const;
	//returns the height of the subtree with root treeroot
	int size(TreeNode<T>* treeroot) const;
	//return the # of nodes in the subtree with root treeroot
	int numOneChildNodes(TreeNode<T>* treeroot) const;
	//return the # of 1-child nodes in the subtree with root treeroot
	bool search(TreeNode<T>* treeroot, T x) const;
	//search for x in the subtree with root treeroot
	void insert(TreeNode<T>*& treeroot, T x);
	//insert x into the subtree with root treeroot 
	void inorderTraversal(TreeNode<T>*) const;
	void preorderTraversal(TreeNode<T>*) const;
	void postorderTraversal(TreeNode<T>*) const;
	void bfsTraversal(TreeNode<T>*) const;
	void displayTree(TreeNode<T>* treeroot, int level) const;
};
template <class T>
int BST<T>::height(TreeNode<T>* treeroot) const
{
	if (treeroot == nullptr) //subtree is empty
		return 0;
	//height= 1+ max{height of left, height of right}
	int l = height(treeroot->left);//height of the left subtree
	int r = height(treeroot->right); //height of the right subtree
	if (l > r)
		return l + 1;
	else
		return r + 1;
}
template <class T>
int BST<T>::numOneChildNodes(TreeNode<T>* treeroot) const
{
	if (treeroot == nullptr) //subtree is empty
		return 0;
	if (treeroot->left && treeroot->right) //case 1 - treeroot has two children
		return numOneChildNodes(treeroot->left) + numOneChildNodes(treeroot -> right);
	else if (treeroot->left) //case 2- treeroot has only a left child
		return 1 + numOneChildNodes(treeroot->left);
	else if (treeroot->right)//case 3 - treeroot has only a right child
		return 1 + numOneChildNodes(treeroot->right);
	else //case 4 - treeroot has no children (treeroot is a leaf)
		return 0;
}
template <class T>
int BST<T>::size(TreeNode<T>* treeroot) const
//return the # of nodes in the subtree with root treeroot
{
	if (treeroot == nullptr)  //empty subtree
		return 0;
	//size = 1+size(left)+size(right)
	return 1 + size(treeroot->left) + size(treeroot->right);
}
//implement search non-recursively
template <class T>
bool BST<T>::search2(T x) const
{
	if (root == nullptr)  //tree is empty
		return false;
	TreeNode<T>* walker = root;
	while (walker)
	{
		if (x == walker->data)  //found it
			return true;
		if (x < walker->data)
			walker = walker->left;//go left
		else
			walker = walker->right;//go right
	}
	return false;
}
template <class T>
bool BST<T>::search(TreeNode<T>* treeroot, T x) const
//search for x in the subtree with root treeroot
{
	if (treeroot == nullptr) //empty subtree
		return false;
	if (x == treeroot->data)  //found it
		return true;
	if (x < treeroot->data)
		return search(treeroot->left, x);// search the left subtree
	else
		return search(treeroot->right, x); // search the right subtree
}
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