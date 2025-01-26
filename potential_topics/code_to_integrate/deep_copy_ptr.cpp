#include <stdlib.h> 
#include <iostream>
#include <time.h>

struct Node
{
    int val;
    Node* next;
    Node* random;

    Node(int _val):val(_val),next(nullptr),random(nullptr) {}
};

int getNodeIndex(Node* find_node,Node* head)
{
    int index = 0;
    Node* ptr = head;
    if(find_node == nullptr)
        index = -1;
    while(ptr != find_node)
    {
        index++;
        ptr = ptr->next;
    }
    if(ptr == nullptr)
        index = -1;
    
    return index;
}

Node* copyRandomList(Node* head) 
{
    Node* ptr = head;
    Node* new_head = new Node(head->val);
    Node* ptr_add = new_head;
    while(ptr->next != nullptr)
    {
        Node* temp_ptr = new Node(ptr->next->val);
        ptr_add->next = temp_ptr;
        ptr_add = ptr_add->next;
        ptr = ptr->next;
    }
    
    ptr = head;
    Node* ptr2 = new_head;
    while(ptr != nullptr)
    {
        Node* rand_ptr = new_head;
        int index = getNodeIndex(ptr->random, head);
        for(int i = 0 ; i < index; i++)
            rand_ptr = rand_ptr->next;
        if(index == -1)
            rand_ptr = nullptr;
        ptr2->random = rand_ptr;
        ptr = ptr->next;
        ptr2 = ptr2->next;

    }
    return new_head;
}

void printLinkedList(Node* head)
{
    Node* ptr = head;
    while(ptr != nullptr)
    {
        std::cout<<"("<<ptr->val<<","<<getNodeIndex(ptr->random,head)<<")"<<" ";
        if (ptr->random != nullptr)
            std::cout<<ptr->random->val<<". ";
        else std::cout<<"NULL. ";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
}

// creates random linked list where max_val is the largest possible value at a
// given node, and max_size is the largest possible size of random linked list. 
Node* randomLinkedList(int max_val, int max_size)
{
    srand (time(NULL));
    Node* head = new Node(rand()%max_val);
    Node* ptr = head;
    int size_rand_linked_list = rand()%max_size;
    for (int i = 0; i < size_rand_linked_list; i++)
    {
        Node* add_node = new Node(rand()%max_val);
        ptr->next = add_node;
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != nullptr)
    {
        int add_rand_node_index = rand()%(size_rand_linked_list+2);
        if(add_rand_node_index == size_rand_linked_list+1)
            ptr->random = nullptr;
        Node* rand_ptr = head;
        for(int i = 0; i < add_rand_node_index; i++)    
            rand_ptr = rand_ptr->next;
        
        ptr->random = rand_ptr;
        ptr = ptr->next;
    }

    return head;
}

int main()
{
    Node* rand_head = randomLinkedList(100, 10);
    printLinkedList(rand_head);
    Node* copy_rand_head = copyRandomList(rand_head);
    printLinkedList(copy_rand_head);
    return 0; 
}