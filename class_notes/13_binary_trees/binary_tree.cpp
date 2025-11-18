#include <iostream>
#include <cstdlib>   // For rand(), srand()
#include <ctime>     // For time()
#include<vector>

using namespace std;

// Node class
class TreeNode 
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

// Binary Tree class
class BinaryTree 
{
private:
    TreeNode* root;

    // Helper functions
    void insertRandom(TreeNode*& node, int val)
    {
        if (node == nullptr)
            node = new TreeNode(val);

        // Randomly go left or right
        //(rand() % 2 == 0 && node->left == nullptr) || (node->right != nullptr && rand() % 2 == 0)
        else if (rand() % 2 == 0)
            insertRandom(node->left, val);
            //insertRandom(node->left, val);
        
        else insertRandom(node->right, val);
        //insertRandom(node->right, val);

    }


    void inorder(TreeNode* node) 
    {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(TreeNode* node) 
    {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode* node) 
    {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void destroyTree(TreeNode* node) 
    {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }


    void printTree(TreeNode* node, int depth = 0, string prefix = "") 
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
    
    
    
public:
    BinaryTree() 
    {
        root = nullptr;
        srand(time(0)); 
    }

    ~BinaryTree() 
    {
        destroyTree(root);
    }

    void insert(int val) 
    {
        insertRandom(root, val);
    }

    void printInorder() 
    {
        inorder(root);
        cout << endl;
    }

    void printPreorder() 
    {
        preorder(root);
        cout << endl;
    }

    void printPostorder() 
    {
        postorder(root);
        cout << endl;
    }
    
    void printTree() 
    {
        printTree(root);
    }
};

int main() 
{
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
