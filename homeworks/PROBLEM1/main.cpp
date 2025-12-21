#include <iostream>
#include <vector>
#include <limits>
#include "binary_search_tree.h"

// main function to drive the program as per the homework specification
int main() {
    BinarySearchTree bst;
    // The set of values to be inserted, as specified in the homework example.
    std::vector<int> values = {20, 10, 30, 5, 15, 25, 35};

    // 1. Insert the set of values into the BST.
    std::cout << "Values to insert into BST: 20, 10, 30, 5, 15, 25, 35" << std::endl;
    for (int val : values) {
        bst.insert(bst.getRoot(), val);
    }
    
    // Print the in-order traversal to show the sorted order of elements.
    std::cout << "In-order Traversal: ";
    bst.inOrder(bst.getRoot());
    std::cout << std::endl;

    // 2. Prompt the user to input k and display the k-th smallest element.
    int k;
    std::cout << "Enter value of k to find the k-th smallest element: ";
    std::cin >> k;
    
    // Robust input handling: ensures the user enters a valid integer.
    while(std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        std::cin.clear(); // Clear error flags
        // Discard the rest of the line to prevent infinite loops on bad input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Enter the value of k: ";
        std::cin >> k;
    }

    int kth_element = bst.findKthSmallest(k);

    // Handle the case where k is out of bounds (less than 1 or greater than the number of nodes).
    if (kth_element != -1) {
        std::cout << "The " << k << "rd smallest element is: " << kth_element << std::endl;
    } else {
        std::cout << "Invalid value for k. It must be between 1 and the number of nodes in the tree." << std::endl;
    }

    // 3. Check if the tree is a valid BST and display the result.
    if (bst.isValidBST()) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is not a valid BST." << std::endl;
    }

    return 0;
}