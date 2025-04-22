#include <iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
#include<vector>

#include"binary_tree.h"

using namespace std;


void BinaryTree::insertRandom(TreeNode*& node, int val)
{
    if (node == nullptr)
        node = new TreeNode(val);

    else if (rand() % 2 == 0)
        insertRandom(node->left, val);
    
    else insertRandom(node->right, val);
}


void BinaryTree::inorder(TreeNode* node) 
{
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}


void BinaryTree::preorder(TreeNode* node) 
{
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


void BinaryTree::postorder(TreeNode* node) 
{
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}


void BinaryTree::destroyTree(TreeNode* node) 
{
    if (node == nullptr) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}


void BinaryTree::printTree(TreeNode* node, int depth, string prefix) 
{
    if (!node) return;

    if (node->right)
        printTree(node->right, depth + 1, prefix + "        ");

    cout << prefix;

    if (depth > 0) {
        cout << (prefix.back() == '/' ? "/" : "\\") << "──── ";
    }

    cout << node->data << endl;

    if (node->left)
        printTree(node->left, depth + 1, prefix + "        ");
}


int BinaryTree::getHeight(TreeNode* node)
{
    if(node==nullptr) return -1;

    else return max(getHeight(node->left),getHeight(node->right))+1;
}


TreeNode* BinaryTree::findLeftmost(TreeNode* node)
{
    if(node == nullptr || node->left == nullptr) return node;

    return findLeftmost(node->left);   
}


int BinaryTree::getSize(TreeNode* node)
{
    if(node==nullptr) return 0;

    return getSize(node->left)+getSize(node->right)+1;
}


BinaryTree::BinaryTree() 
{
    root = nullptr;
    srand(time(0)); 
}


BinaryTree::~BinaryTree() 
{
    destroyTree(root);
}


// wrappers
void BinaryTree::insert(int val) 
{
    insertRandom(root, val);
}


void BinaryTree::printInorder() 
{
    inorder(root);
    cout << endl;
}


void BinaryTree::printPreorder() 
{
    preorder(root);
    cout << endl;
}


void BinaryTree::printPostorder() 
{
    postorder(root);
    cout << endl;
}


void BinaryTree::printTree() 
{
    printTree(root);
}


int BinaryTree::getHeight()
{
    return getHeight(root);
}


TreeNode* BinaryTree::findLeftmost()
{
    return findLeftmost(root);
}


int BinaryTree::getSize()
{
    return getSize(root);
}
