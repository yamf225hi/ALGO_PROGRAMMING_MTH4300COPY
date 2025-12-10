#include "problem4.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> // For temporary storage when reading from file

int main() {
    // --- Part 2: Write to names_list.txt ---
    std::string my_first_name = "Gemini";
    std::string my_last_name = "AI";
    std::string names_list_filename = "problem 4/names_list.txt";

    std::ofstream outFile(names_list_filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open " << names_list_filename << " for writing." << std::endl;
        return 1;
    }

    outFile << my_first_name << " " << my_last_name << std::endl;
    outFile << "John Doe" << std::endl;
    outFile << "Alice Smith" << std::endl;
    outFile << "Bob Johnson" << std::endl;
    outFile << "Charlie Brown" << std::endl;
    outFile.close();
    std::cout << "Successfully wrote names to " << names_list_filename << std::endl;


    // --- Part 3: Read from names_list.txt, create, sort, and write linked list ---
    LinkedList myList;
    std::ifstream inFile(names_list_filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open " << names_list_filename << " for reading." << std::endl;
        return 1;
    }

    std::string first, last;
    while (inFile >> first >> last) {
        myList.addNode(first, last);
    }
    inFile.close();
    std::cout << "Successfully read names from " << names_list_filename << std::endl;

    std::cout << "\nOriginal List from file:" << std::endl;
    myList.printList();

    myList.sort(); // Sort the list
    std::cout << "\nSorted List:" << std::endl;
    myList.printList();

    std::string sorted_names_filename = "problem 4/sorted_names.txt";
    myList.writeToFile(sorted_names_filename);
    std::cout << "\nSorted list written to " << sorted_names_filename << std::endl;


    // --- Test Problem 4, Part 0.1: Merge Two Sorted Linked Lists ---
    std::cout << "\n--- Testing Merge Function ---" << std::endl;
    LinkedList listA;
    listA.addNode("Apple", "Pie");
    listA.addNode("Banana", "Split");
    listA.addNode("Orange", "Juice");
    listA.sort(); // Ensure sorted

    LinkedList listB;
    listB.addNode("Cherry", "Tart");
    listB.addNode("Grape", "Jelly");
    listB.addNode("Watermelon", "Punch");
    listB.sort(); // Ensure sorted

    std::cout << "List A:" << std::endl << listA << std::endl;
    std::cout << "List B:" << std::endl << listB << std::endl;

    LinkedList merged = LinkedList::merge(listA, listB);
    std::cout << "Merged List (A and B):" << std::endl << merged << std::endl;


    // --- Test Problem 4, Part 0.2: Remove Nth Node From End ---
    std::cout << "\n--- Testing deleteNthNodeFromEnd Function ---" << std::endl;
    LinkedList testDeleteList;
    testDeleteList.addNode("One", "Node");
    testDeleteList.addNode("Two", "Nodes");
    testDeleteList.addNode("Three", "Nodes");
    testDeleteList.addNode("Four", "Nodes");
    testDeleteList.addNode("Five", "Nodes");

    std::cout << "Original List for delete test:" << std::endl << testDeleteList << std::endl;

    // Delete 2nd node from end (which is "Four Nodes")
    if (testDeleteList.deleteNthNodeFromEnd(2)) {
        std::cout << "List after deleting 2nd node from end:" << std::endl << testDeleteList << std::endl;
    } else {
        std::cout << "Failed to delete 2nd node from end." << std::endl;
    }
    
    // Delete head (e.g., 4th node from end if 4 elements remaining)
    if (testDeleteList.deleteNthNodeFromEnd(4)) { 
        std::cout << "List after deleting new 4th node from end (original head):" << std::endl << testDeleteList << std::endl;
    } else {
        std::cout << "Failed to delete 4th node from end." << std::endl;
    }

    return 0;
}
