//
//  main.cpp
//  rec12
//
//  Created by Sophia Danielsen on 11/30/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;


class List {
    struct Node;
public:
    class Iterator {
        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.nodePtr == rhs.nodePtr;
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return !(lhs == rhs);
        }
        
    public:
        explicit Iterator(Node* ptr) : nodePtr(ptr) {}
        
        Iterator& operator++() {
            nodePtr = nodePtr -> next;
            return *this;
        }
        
        Iterator& operator--() {
            nodePtr = nodePtr -> prev;
            return *this;
        }
        
        int operator*() const {
            return nodePtr -> data;
        }
        
        Node* getNode() const {
            return nodePtr;
        }
        
    private:
        Node* nodePtr;
    };
    
    Iterator begin() { return Iterator(head -> next); }
    Iterator end() { return Iterator(tail); }
    
    List(int length = 0) : length(length) {
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
    }
    
    //Destructor
    ~List() {
        cout << "~List()" << endl;
        clear();
        delete head;
        delete tail;
    }
    
    //Copy Constructor
    List(List& rhs){
        
        Node* cursor = rhs.head -> next;
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
        while(cursor -> next != nullptr){
            push_back(cursor -> data);
            cursor = cursor -> next;
        }
    }
    
    //Assignment Operator
    List& operator=(const List& rhs){
        if (this == &rhs){
            return *this;
        }
        
        clear();
        
        Node* cursor = rhs.head -> next;

        while(cursor -> next != nullptr){
            push_back(cursor -> data);
            cursor = cursor -> next;
        }
        
        return *this;
    }
    
    size_t size() const {
        return length;
    }
    
    int front() const {
        return head -> next -> data;
    }
    
    int back() const {
        return tail -> prev-> data;
    }
    
    void push_back(int data) {
        Node* prevTemp = tail -> prev;
        
        Node* newNode = new Node(data, prevTemp, tail);
        prevTemp -> next = newNode;
        tail -> prev = newNode;
        length++;
    }
    
    bool pop_back(){
        if (length == 0) { return false; }
        Node* toDelete = tail -> prev;
        toDelete -> prev -> next = tail;
        tail -> prev = toDelete -> prev;
        
        delete toDelete;
        length--;
        
        return true;
    }
    
    void push_front(int data) {
        Node* nextTemp = head -> next;
        
        Node* newNode = new Node(data, head, nextTemp);
        nextTemp -> prev = newNode;
        head -> next = newNode;
        length++;
    }
    
    Iterator insert(const Iterator& iter, int data){
        Node* temp = iter.getNode();
        
        Node* newNode = new Node(data, temp -> prev, temp);
        temp -> prev = newNode;
        newNode -> prev -> next = newNode;
        
        length++;
        
        Iterator newIter = iter;
        --newIter;
        return newIter;
    }
    
    Iterator erase(const Iterator& iter) {
        Node* toDelete = iter.getNode();
        
        toDelete -> prev -> next = toDelete -> next;
        toDelete -> next -> prev = toDelete -> prev;
        
        length--;
        
        delete toDelete;
        
        Iterator newIter = iter;
        ++newIter;
        return newIter;
    }
    
    bool pop_front() {
        if (length == 0) { return false; }
        Node* toDelete = head -> next;
        toDelete -> next -> prev = head;
        head -> next = toDelete -> next;
        
        delete toDelete;
        length--;
        
        return true;
    }
    
    void clear () {
        while (pop_back() == true) {}
    }
    
    int& operator[](const size_t index) {
        Node* cursor = head -> next;
        size_t counter = 0;
        
        while (counter != index) {
            cursor = cursor -> next;
            counter++;
        }
        
        return cursor -> data;
    }
    
    friend ostream& operator<<(ostream& os, List& rhs);
    
private:
    struct Node{
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
        int data;
        Node* prev;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    size_t length;
};

ostream& operator<<(ostream& os, List& rhs) {
    List::Node* cursor = rhs.head -> next;
    while (cursor -> next != nullptr) {
        os << cursor -> data << " ";
        cursor = cursor -> next;
    }
    
    return os;
}

void printListInfo(List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back(): " << myList.back()
    << ", list: " << myList << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
    
    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";
    
    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
