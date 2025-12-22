#include<iostream>
#include"binary_search_tree.h"

// default constructor: 
BinarySearchTree::BinarySearchTree():root(nullptr)
{}

// copy constructor:
BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): root(nullptr)
{
    if(!other.root) return; // if source is empty, done. 
    
    root = new Node(other.root->data); // copy root node.
    copyTree(other.root->left,root->left); //recursively copy left subtree
    copyTree(other.root->right,root->right);
}

// copy tree helper
void BinarySearchTree::copyTree(const Node* from_copy, Node*& to_copy)
{
    //preorder
    if(!from_copy) return; // base case, nothing to copy. 
    to_copy=new Node(from_copy->data); // creates new node. 
    copyTree(from_copy->left, to_copy->left); // copies left child. 
    copyTree(from_copy->right, to_copy->right);
}

// move constructor
BinarySearchTree::BinarySearchTree(BinarySearchTree&& other) 
{
    root=other.root; // steals others root. 
    other.root=nullptr; // leaves other empty. 
}

// copy assignment operator
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs)
{
    if(&rhs != this) // self assignment check
    {
        destroy(root); // cleans up current tree
        if(!rhs.root)
        {
            root = nullptr;
            return *this;
        }
        
        // deep copy:
        root = new Node(rhs.root->data);
        copyTree(rhs.root->left,root->left);
        copyTree(rhs.root->right,root->right);
    }

    return *this;
}

// move assignment operator
BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree&& rhs)
{
    if(&rhs != this)
    {
        destroy(root);
        root=rhs.root;
        rhs.root=nullptr;
    }

    return *this;
}

// destructor
BinarySearchTree::~BinarySearchTree() 
{
    destroy(root);
    root=nullptr;
}

// destroy helper function
void BinarySearchTree::destroy(Node* curr_del)
{
    if(!curr_del) return; // base case

    destroy(curr_del->left); // delete left subtree 
    destroy(curr_del->right); 

    delete curr_del; // delete current node
    curr_del=nullptr;
}


Node* BinarySearchTree::getRoot()
{
    return root;
}


Node* BinarySearchTree::insert(Node* start, int val)    
{
     if (!root) 
    {
        root= new Node(val);
        return root;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data) start->left = insert(start->left, val);  

    else if (val > start->data) start->right = insert(start->right, val); 
    
    return start;
}

// in order traversal
void BinarySearchTree::inOrder(Node* start)
{
    // Base case: empty subtree :
    if (!start) return; 
    // 1. Traverse left subtree :
    inOrder(start->left); 
    // 2. Visit current node :
    std::cout<<start->data<<" -> ";
    // 3. Traverse right subtree 
    inOrder(start->right);        
}

// search, iterative. 
Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        // go left if smaller: 
        if(val < curr->data) curr=curr->left;

        // else go right if larger:
        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}


Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;  // Base case: not found
    
    // Search for node
    else if(val < start->data) start->left=deleteNode(start->left,val);
    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else { // Found node to delete
        if(start->left && start->right) { // Two children
            Node* min_node = findMin(start->right);  // Find successor
            start->data = min_node->data;            // Replace data
            start->right = deleteNode(start->right, start->data); // Delete successor
        }
       else { // Zero or one child
            Node* save_spot=start->left?start->left:start->right;
            delete start;
            return save_spot; // Connect parent to child
       } 
    }
    return start;
}


Node* BinarySearchTree::findMin(Node* start)
{
    if(!start) return nullptr;
    
    while(start->left) start=start->left;

    return start;
}




// public interface
int BinarySearchTree::findKthSmallest(int k)
{
    if (k < 1) return -1; // k must be a positive integer.
    int counter = 0;
    return findKthSmallest(root, k, counter); // Call recursive helper
}

// private recursive helper function to find the k-th smallest element
int BinarySearchTree::findKthSmallest(Node* start, int k, int &counter)
{
    if (!start) // Base case: if the node is null, the element is not in this subtree.
    {
        return -1; 
    }

    // 1. Recurse on the left subtree.
    // An in-order traversal visits the left subtree first, which contains all smaller elements.
    int leftside = findKthSmallest(start->left, k, counter);

    // If the k-th element was found in the left subtree, propagate the value up the call stack.
    if (leftside != -1)
    {   
        return leftside;
    }

    // 2. Process the current node (this is the "in-order" step).
    // After visiting all nodes in the left subtree, we visit the current node.
    counter++;
    if (counter == k)
    {
        // If the current node is the k-th node we've visited, we've found our element.
        return start->data;
    }

    // 3. Recurse on the right subtree.
    // If the k-th element hasn't been found yet, continue the in-order traversal into the right subtree.
    return findKthSmallest(start->right, k, counter);
}

// Public interface for isValidBST check.
bool BinarySearchTree::isValidBST() {
    Node* prev = nullptr; // Keeps track of the previously visited node in the in-order traversal.
    return isValidBST(root, prev);
}

// Private recursive helper for isValidBST using in-order traversal.
// This function checks if the tree adheres to BST properties in O(n) time.
bool BinarySearchTree::isValidBST(Node* node, Node*& prev) {
    if (node == nullptr) {
        return true; // Base case: an empty subtree is a valid BST.
    }

    // 1. Check the left subtree.
    if (!isValidBST(node->left, prev)) {
        return false;
    }

    // 2. Check the current node against the previous node from the in-order traversal.
    // For a valid BST, the current node's data must be strictly greater than the previous node's data.
    if (prev != nullptr && node->data <= prev->data) {
        return false; // Violation of BST property.
    }
    
    // Update prev to the current node for the next comparison in the right subtree.
    prev = node;

    // 3. Check the right subtree.
    return isValidBST(node->right, prev);
}
