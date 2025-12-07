#include<iostream>
#include"binary_tree.h"
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()

using namespace std;

int main() 
{
    srand(time(0));
    BinaryTree tree;

    for (int i = 1; i <= 10; ++i)
        tree.insert(i);

    cout << "Inorder traversal: ";
    tree.printInorder();

    cout << "Preorder traversal: ";
    tree.printPreorder();

    cout << "Postorder traversal: ";
    tree.printPostorder();

    tree.printTree();

    return 0;
}
