#include "bst.h"
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
int main()
{
	BST<int> t;
	int n = 20;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 100;
		cout << "\n\nInsert " << x << endl;
		//system("pause");
		system("cls");
		t.insert(x);
		t.displayTree();
	}
	cout << "\n\nPreorder traversal : ";
	t.preorderTraversal();
	cout << "\n\nInorder traversal : ";
	t.inorderTraversal();
	cout << "\n\nPostorder traversal : ";
	t.postorderTraversal();
	cout << "\n\nBFS traversal : ";
	t.bfsTraversal();
	cout << endl;
	/*
	for (int i = 0; i < 3; i++)
	{
	int x;
	cout << "Enter a value to search for : ";
	cin >> x;
	if (t.search2(x))
	cout << x << " is found.\n";
	else
	cout << x << " is not found.\n";
	}
	*/
	cout << "Size of the tree is : " << t.size() << endl;
	cout << "The number of nodes that have exactly one child is : " <<
		t.numOneChildNodes() << endl;
	cout << "Te height of the tree is : " << t.height() << endl;
	system("pause");
	return 0;
}