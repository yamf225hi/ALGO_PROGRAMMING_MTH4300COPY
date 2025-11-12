# Lecture notes

## table of contents
1. Linked Lists
2. Practice Examples


## Linked Lists
A **linked list** is a linear data structure where elements, called nodes, are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts:

* **Data:** The actual value the node holds.
* **Pointer (next):** A pointer/reference to the next node in the sequence.

The main advantage of linked lists over arrays is that they can grow and shrink dynamically, without needing to know their size in advance. However, they don't allow random access to elements, meaning you must traverse the list from the head to access a specific element.

### Basic Structure of a Node
In a **singly linked list**, each node points to the next node, and the last node points to ```nullptr``` (signifying the end of the list). Here's how a node is typically represented:

```cpp
struct Node {
    int data;        // Data part of the node
    Node* next;      // Pointer to the next node
};
```


### Key Linked List Operations
* **Insertion:**
  * To insert a new node, we can add it to the head (beginning), tail (end), or any position in between.
  * In our example, we added nodes at the end (tail insertion).

* **Traversal:**
  * Since linked lists don't provide random access (like arrays), we have to start from the ```head``` and follow the ```next``` pointers until we reach the desired node or the end of the list.

* **Deletion:**
  * Deleting a node involves adjusting the ```next``` pointer of the previous node to point to the node after the one being deleted, and then freeing the memory of the deleted node.

* **Search:**
  * To search for a node, we traverse the list from the ```head```, checking each node's data.


### Types of Linked Lists
* **Singly Linked List:** Each node points to the next node, and the last node points to ```nullptr```.
* **Doubly Linked List:** Each node has two pointers: one pointing to the next node and another pointing to the previous node. This allows traversal in both directions.
* **Circular Linked List:** The last node points back to the ```head```, forming a circle. This can be either singly or doubly linked.


### Example of a Doubly Linked List Node
```cpp
struct Node {
    int data;
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node
};
```


#### Advantages of Linked Lists
* **Dynamic Size:** Linked lists can grow or shrink as needed, unlike arrays which require a fixed size.
* **Efficient Insertion/Deletion:** Inserting or deleting elements at the beginning or middle of the list is more efficient than arrays, as there’s no need to shift elements.

#### Disadvantages of Linked Lists
* **No Random Access:** Accessing elements requires linear traversal, unlike arrays where you can access any element in constant time.
* **Extra Memory:** Each node requires additional memory for the pointer(s), which can lead to increased memory usage compared to arrays.


### Conclusion
Linked lists are a fundamental data structure in computer science, used when dynamic size and efficient insertion/deletion are needed. The singly linked list is the simplest form, while more complex types like doubly and circular linked lists provide additional flexibility in traversal and manipulation.


## Practice Examples
1. Modify deletion to delete by value instead of position. 
2. Write a function that takes in a class ```LinkedList(singly linked list)```, and returns another linked list in the reverse order. Example: l1= 5->3->7->1 then the output should be l1_r= 1->7->3->5
3. Implement a queue class, using the linked list data structure
4. Use stl list and solve the problem from last time for reversing a linked list. What is the time complexity (big O notation) for reversed linked list with stl and without?
  