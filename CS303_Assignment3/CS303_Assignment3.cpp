// CS303_Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Queue.h"
#include "Functions.h"
#include <vector>
#include <list>
using namespace std;

int main() {
    //Q1: Queue testing
    cout << "Testing Queue Functionality:\n";

    Queue<int> queue;

    //test empty() when queue is empty
    cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;

    //test push()
    cout << "Adding elements to the queue now." << endl;
    queue.push(15);
    queue.push(8);
    queue.push(22);
    queue.push(3);
    queue.push(60);
    queue.push(13);

    //test displayQueue()
    cout << "Queue contents:\n"; 
    queue.displayQueue(); 

    //test empty() when queue has elements
    cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;

    //test size()
    cout << "Queue size: " << queue.size() << endl;

    //test front()
    cout << "Front of queue: " << queue.front().data << endl;

    //test move_to_rear()
    queue.move_to_rear();
    cout << "Queue after calling move_to_rear:" << endl;
    queue.displayQueue();

    //test pop()
    queue.pop();
    cout << "Queue after calling pop:" << endl;
    queue.displayQueue();
    cout << "New front: " << queue.front().data << endl;
    cout << "Queue size: " << queue.size() << endl;



    //Q2: Linear Search testing
    cout << "\nTesting Linear Search Functionality:\n";

    //add elements to the vector
    vector<Item_Type<string>> vectorTest;
    vectorTest.push_back(Item_Type<string>("Dog"));
    vectorTest.push_back(Item_Type<string>("Cat"));
    vectorTest.push_back(Item_Type<string>("Bird"));
    vectorTest.push_back(Item_Type<string>("Cat"));
    vectorTest.push_back(Item_Type<string>("Fish"));

    //display vector to user
    cout << "Vector contents:\n";
    for (auto& word : vectorTest)
        cout << word.data << " ";
    cout << endl;

    //test linear_search()
    Item_Type<string> target("Cat");
    int index = linear_search(vectorTest, target, static_cast<int>(vectorTest.size()) - 1);
    cout << "Last occurrence of \"" << target.data << "\" is at index: " << index << endl;

  

    //Q3: Insertion Sort Testing
    cout << "\nTesting Insertion Sort Functionality\n";

    //declare and add elements to a list
    list<int> nums = { 9, 4, 2, 7, 1 };

    cout << "Original list: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    //test insertion_sort()
    insertion_sort(nums);
    cout << "Sorted list: ";
    for (int n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}



