#ifndef PROBLEM4_H
#define PROBLEM4_H

#include <string>
#include <iostream> // For std::ostream

// Given struct node
struct Node {
    std::string first_name;
    std::string last_name;
    Node* next;

    // Constructor for convenience
    Node(const std::string& first, const std::string& last, Node* next_node = nullptr)
        : first_name(first), last_name(last), next(next_node) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList(); // Default constructor
    ~LinkedList(); // Destructor

    // Utility for adding nodes (for building lists and testing)
    void addNode(const std::string& first, const std::string& last);
    void printList() const; // Utility to print the list

    // Problem 4, Part 0.1: Merge Two Sorted Linked Lists
    static LinkedList merge(LinkedList list1, LinkedList list2);

    // Problem 4, Part 0.2: Remove Nth Node From End
    bool deleteNthNodeFromEnd(int n);

    // Problem 4, Part 1: Sort by first name, then last name (using selection sort)
    void sort();

    // Helper for printing to file (Part 3)
    void writeToFile(const std::string& filename) const;

    // To allow printing with << operator
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

    // Copy constructor and assignment operator for proper resource management (good practice)
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    // Move constructor and assignment operator
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(LinkedList&& other) noexcept;
};

#endif // PROBLEM4_H