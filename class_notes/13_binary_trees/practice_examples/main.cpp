#include<iostream>
#include"binary_tree.h"

using namespace std;


int main() 
{
    BinaryTree tree;

    for (int i = 1; i <= 20; ++i)
        tree.insert(i);

    cout << "Inorder traversal: ";
    tree.printInorder();

    cout << "Preorder traversal: ";
    tree.printPreorder();

    cout << "Postorder traversal: ";
    tree.printPostorder();

    cout<<"(height, leftmost, # of nodes): "<<"("<<tree.getHeight()<<", "
    <<tree.findLeftmost()->data<<", "<<tree.getSize()<<")"<<endl;

    tree.printTree();

    return 0;
}