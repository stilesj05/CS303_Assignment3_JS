#pragma once
#include <iostream>
using namespace std;

//Item_Type wrapper
template <typename T>
struct Item_Type {
    T data;
    Item_Type(T d) : data(d) {}

    //overload equality operator so we can do comparisons for the linear search
    bool operator==(const Item_Type<T>& other) const {
        return data == other.data;
    }
};

//node definition
template <typename T>
struct Node {
    Item_Type<T> nodeData;
    Node<T>* next;

    Node(const Item_Type<T>& data, Node<T>* next_ptr = nullptr)
        : nodeData(data), next(next_ptr) {
    }
};

//queue class
template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int num_items;

public:
    Queue() {
        //initialize head, tail, and num_items
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }
    ~Queue() {
        //clear the queue
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    //push(): take an item and insert at end of list
    void push(const Item_Type<T>& item) {
        Node<T>* newNode = new Node<T>(item); //add a new node
        //if empty, set newNode = to head and tail
        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        }
        else { //if not empty, push to tail and update previous nodes in queue
            tail->next = newNode;
            tail = newNode;
        }
        num_items++;
    }

    //pop(): delete first element of queue
    void pop() {
        //check for empty queue
        if (head == nullptr) {
            cout << "List is empty. No items to pop." << endl;
        }
        else {
            //check if there is only one node in the queue
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                //create temp variable to store value after head, delete head, set temp variable to head
                Node<T>* temp = head->next;
                delete head;
                head = temp;
            }
            --num_items;
        }
    }

    //front(): return the data of the first node of the queue
    Item_Type<T> front() const {
        //check for empty queue
        if (head == nullptr) {
            cout << "Empty queue. Cannot return front value. " << endl;
            return Item_Type<T>(T());
        }
        return head->nodeData;
    }

    //size(): returns size of the queue
    int size() const {
        return num_items;
    }

    //empty(): return true if queue is empty, otherwise return false
    bool empty() const {
        return head == nullptr;
    }

    //displayQueue(): shows what is inside of the queue to the user
    void displayQueue() {
        if (empty()) {
            cout << "Queue is empty.Nothing to display." << endl;
            return;
        }

        int currentSize = size(); //preserve the size to prevent looping infinitely
        for (int i = 0; i < currentSize; ++i) {
            Item_Type<T> element = front(); //get the front element
            cout << element.data << " "; //print the value

            pop(); //remove from front
            push(element); //push it back to rear
        }

        cout << endl;
    }



    //move_to_rear(): moves an element from the front of the queue to the rear
    void move_to_rear() {
        //check for empty queue
        if (head == nullptr) {
            cout << "Empty list. Cannot move anything from front to rear." << endl;
        }
        //check for one element in queue
        else if (head == tail) {
            cout << "Only one element in the list. Cannot move it anywhere." << endl;
        }
        else {
            push(Item_Type<T>(front().data)); //push the front element to the end
            pop(); //pop the front element we just moved
        }
    }
};

