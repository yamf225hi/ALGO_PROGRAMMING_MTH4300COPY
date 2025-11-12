#include <iostream>
#include "linked_list.h"


LinkedList::LinkedList() : head(nullptr) {}


LinkedList::LinkedList(const LinkedList& other) : head(nullptr) 
{
    Node* current = other.head;
    int i=0;
    while (current != nullptr)
    {
        insert(current->data,i);
        current=current->next;
        i++;
    }
}


LinkedList::LinkedList(LinkedList&& other)
{
    head=other.head;
    other.head=nullptr;
}


LinkedList::~LinkedList() 
{
    eraseList();
}


void LinkedList::eraseList() 
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}


LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(this!=&rhs)
    {
        eraseList();
        Node* current = rhs.head;
        int i=0;
        while (current != nullptr)
        {
            insert(current->data,i);
            current=current->next;
            i++;
        }
    }

    return *this;
}


LinkedList& LinkedList::operator=(LinkedList&& rhs)
{
    if(this!=&rhs)
    {
        head=rhs.head;
        rhs.head=nullptr;
    }
    

    return *this;
}


void LinkedList::insert(int value, int pos) 
{
    Node* newNode = new Node();  // Create a new node
    newNode->data = value;
    newNode->next = nullptr;

    // empty list case
    if(head==nullptr && pos==0)
        head=newNode;   

    //insert at front of list
    else if(pos==0)
    {
        newNode->next=head;
        head=newNode;
    }

    // Search for the position to insert
    else
    {
        Node* temp = head;
        while(temp!=nullptr && (pos-1)>0)
        {
            temp=temp->next;
            pos--;
        }

        if (temp!=nullptr && pos == 1) 
        {
            newNode->next=temp->next;
            temp->next = newNode;
        }

        else
        {
            std::cout<<"unable to add node, pos invalid"<<std::endl;
            delete newNode;
        }
    }
   
}


void LinkedList::display() 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}


void LinkedList::deleteByValue(int value) 
{
    // If list is empty
    if (head == nullptr)
        std::cout << "List is empty, cannot delete" << std::endl;


    // If the head node holds the value to be deleted
    else if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;  // Move head to the next node
        delete temp;        // Free memory of old head
    }

    // Search for the node to delete
    else
    {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        // If the value is found, delete the node
        if (current != nullptr)
        {
            previous->next = current->next;
            delete current;
        }

        else std::cout << "Value not found in the list" << std::endl;
    }
    
}

