#include "bst.h"
#include <iostream>
using namespace std;
int main()
{
	BST<int> t;
	int n = 20;
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 100;
		cout << "\n\nInsert " << x << endl;
		system("pause");
		system("cls");
		t.insert(x);
		t.displayTree();
	}
	cout << "\n\nPreorder traversal : ";
	t.preorderTraversal();
	cout << endl;
	cout << "\n\nInorder traversal : ";
	t.inorderTraversal();
	cout << endl;
	cout << "\n\nPostorder traversal : ";
	t.postorderTraversal();
	cout << endl;
	cout << "\n\nBFS traversal : ";
	t.bfsTraversal();
	cout << endl;
	system("pause");
	return 0;
}