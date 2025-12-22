  struct Node 
        {
            int data; //Data stored in the node
            Node* left; //Pointer to the left child
            Node* right; // Pointer to the right child

            // Constructor to initialize a new node
            Node(int value):data(value), left(nullptr),right(nullptr) {}
        };

class BinarySearchTree
{
    private:
        
        Node* root; // stores address of the root node. 


    public:
        // default constructor that creates empty BST:
        BinarySearchTree(); 
        // destructor to free all nodes : 
        ~BinarySearchTree(); // destructor to free all nodes
        // copy constructor to make deep copy of another BST:
        BinarySearchTree(const BinarySearchTree& other); 
        // copy tree helper: 
        void copyTree(const Node* from_copy, Node*& to_copy);
        // move constructor that transfers ownership from 'other' :
        BinarySearchTree(BinarySearchTree&& other); 
        // copy assignment operator that deep copies from rhs to the existing object: 
        BinarySearchTree& operator=(const BinarySearchTree& rhs); 
        // move assignment operator that TRANSFERS ownership from rhs to existing object :
        BinarySearchTree& operator=(BinarySearchTree&& rhs); 


        // returns the pointer for root node for traversals : 
        Node* getRoot(); 
        // returns value 'val' starting from node start (the root node) : 
        Node* insert(Node* start, int val); 
        void inOrder(Node* start); // performs inorder traversal starting from root node (start)
        Node* search(int val); // searches for value in the tree
        Node* deleteNode(Node* start, int val); // deletes the value starting from the root and returns the rootof subtree. 
        Node* findMin(Node* start);
        int findKthSmallest(int k);
        bool isValidBST();


    private:
        void destroy(Node* curr_del);//helper function for destructor
        int findKthSmallest(Node* start, int k, int &counter);
        bool isValidBST(Node* node, Node*& prev);

        
};




