//#include<string>

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
    void insertRandom(TreeNode*& node, int val);
    void inorder(TreeNode* node);
    void preorder(TreeNode* node);
    void postorder(TreeNode* node);
    void destroyTree(TreeNode* node);
    void printTree(TreeNode* node, int depth = 0, std::string prefix = "");
    int getHeight(TreeNode* node);
    TreeNode* findLeftmost(TreeNode* node);
    int getSize(TreeNode* node);
    
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int val);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printTree();
    int getHeight();
    TreeNode* findLeftmost();
    int getSize();

};