#include "problem4.h"
#include <iostream>
#include <fstream>
#include <algorithm> // For std::swap

// Default constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Utility for adding nodes (to the end of the list)
void LinkedList::addNode(const std::string& first, const std::string& last) {
    Node* newNode = new Node(first, last);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Utility to print the list
void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->first_name << " " << current->last_name << std::endl;
        current = current->next;
    }
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {
    if (other.head == nullptr) {
        return;
    }
    Node* currentOther = other.head;
    Node* lastNew = nullptr;
    while (currentOther != nullptr) {
        Node* newNode = new Node(currentOther->first_name, currentOther->last_name);
        if (head == nullptr) {
            head = newNode;
        } else {
            lastNew->next = newNode;
        }
        lastNew = newNode;
        currentOther = currentOther->next;
    }
}

// Copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) { // Handle self-assignment
        return *this;
    }

    // Deallocate existing nodes
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    // Deep copy
    if (other.head == nullptr) {
        return *this;
    }
    Node* currentOther = other.head;
    Node* lastNew = nullptr;
    while (currentOther != nullptr) {
        Node* newNode = new Node(currentOther->first_name, currentOther->last_name);
        if (head == nullptr) {
            head = newNode;
        } else {
            lastNew->next = newNode;
        }
        lastNew = newNode;
        currentOther = currentOther->next;
    }
    return *this;
}

// Move constructor
LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}

// Move assignment operator
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this == &other) { // Handle self-assignment
        return *this;
    }

    // Deallocate existing resources
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = other.head; // "Steal" the resources
    other.head = nullptr; // Nullify the other's head

    return *this;
}

// Problem 4, Part 0.1: Merge Two Sorted Linked Lists (assuming sorted means by name)
// This implementation assumes the input lists are already sorted.
// It creates a new merged list.
LinkedList LinkedList::merge(LinkedList list1, LinkedList list2) {
    LinkedList mergedList;
    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr || current2 != nullptr) {
        if (current1 == nullptr) {
            mergedList.addNode(current2->first_name, current2->last_name);
            current2 = current2->next;
        } else if (current2 == nullptr) {
            mergedList.addNode(current1->first_name, current1->last_name);
            current1 = current1->next;
        } else {
            // Compare nodes based on first name, then last name
            if (current1->first_name < current2->first_name ||
                (current1->first_name == current2->first_name && current1->last_name < current2->last_name)) {
                mergedList.addNode(current1->first_name, current1->last_name);
                current1 = current1->next;
            } else {
                mergedList.addNode(current2->first_name, current2->last_name);
                current2 = current2->next;
            }
        }
    }
    return mergedList;
}

// Problem 4, Part 0.2: Remove Nth Node From End
bool LinkedList::deleteNthNodeFromEnd(int n) {
    if (head == nullptr || n <= 0) {
        return false;
    }

    Node* dummyHead = new Node("", "", head); // Dummy head to handle deleting the head
    Node* fast = dummyHead;
    Node* slow = dummyHead;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) { // n is greater than list size
            delete dummyHead;
            return false;
        }
        fast = fast->next;
    }
    if (fast == nullptr) { // If n is equal to list size (deleting head)
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        delete dummyHead;
        return true;
    }

    // Move both pointers until fast reaches the end
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to be deleted
    Node* nodeToDelete = slow->next;
    slow->next = nodeToDelete->next;
    
    if (nodeToDelete == head) { // If the node deleted was the original head
        head = head->next;
    }
    
    delete nodeToDelete;
    delete dummyHead;
    return true;
}


// Problem 4, Part 1: Sort by first name, then last name (using selection sort)
void LinkedList::sort() {
    if (head == nullptr || head->next == nullptr) {
        return; // List is empty or has only one element, already sorted
    }

    Node* current = head;
    while (current != nullptr) {
        Node* minNode = current;
        Node* innerCurrent = current->next;
        while (innerCurrent != nullptr) {
            if (innerCurrent->first_name < minNode->first_name ||
                (innerCurrent->first_name == minNode->first_name && innerCurrent->last_name < minNode->last_name)) {
                minNode = innerCurrent;
            }
            innerCurrent = innerCurrent->next;
        }

        // Swap data between current and minNode
        std::swap(current->first_name, minNode->first_name);
        std::swap(current->last_name, minNode->last_name);

        current = current->next;
    }
}


// Helper for printing to file (Part 3)
void LinkedList::writeToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        outFile << current->first_name << " " << current->last_name << std::endl;
        current = current->next;
    }
    outFile.close();
}

// To allow printing with << operator
std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        os << current->first_name << " " << current->last_name << std::endl;
        current = current->next;
    }
    return os;
}