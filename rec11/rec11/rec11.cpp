//
//  main.cpp
//  rec11
//
//  Created by Sophia Danielsen on 11/16/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
using namespace std;


struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    Node* next;
    int data;
};

void spliceInto(Node* original, Node* splice) {
    Node* cursor = splice -> next;
    Node* originalNext = original -> next;
    
    original -> next = splice;
    
    while (cursor -> next != nullptr){
        cursor = cursor -> next;
    }
    
    cursor -> next = originalNext;
}

bool boolSubList(Node* result, Node* subList){
    while (result != nullptr && subList != nullptr && result -> data == subList -> data){
        result = result -> next;
        subList = subList -> next;
    }
    return (subList == nullptr);
}

Node* isSubList(Node* original, Node* subList){
    Node* result = original;
    
    while (result -> next != nullptr){
        if (boolSubList(result, subList) == false) {
            result = result -> next;
        }
        else{
            return result;
        }
    }
    
    cout << "Failed to match";
    return nullptr;
}

void display(Node* hp) {
    Node* p = hp;
    while (p != nullptr) {
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main( ) {
// Part One
    
    Node* list1 = new Node(5);
    list1 -> next = new Node(7);
    list1 -> next -> next = new Node(9);
    list1 -> next -> next -> next = new Node(1);
    
    Node* list2 = new Node(6);
    list2 -> next = new Node(3);
    list2 -> next -> next = new Node(2);
    
    cout << "List 1: ";
    display(list1);
    cout << endl;
    
    cout << "List 2: ";
    display(list2);
    cout << endl;
    
    
    cout << "spliceInto(List1 -> next, List2) : ";
    spliceInto(list1 -> next, list2);
    display(list1);
    cout << endl;
    display(list2);
    cout << endl;

// Part Two
    
    cout << "------- Part 2 -------" << endl;
    
    Node* list3 = new Node(1);
    Node* cursor = list3;
    
    cursor -> next = new Node(2);
    cursor = cursor -> next;
    cursor -> next = new Node(3);
    cursor = cursor -> next;
    cursor -> next = new Node(2);
    cursor = cursor -> next;
    cursor -> next = new Node(3);
    cursor = cursor -> next;cursor -> next = new Node(2);
    cursor = cursor -> next;
    cursor -> next = new Node(4);
    cursor = cursor -> next;
    cursor -> next = new Node(5);
    cursor = cursor -> next;
    cursor -> next = new Node(6);
    cursor = cursor -> next;
    
    cout << "List 3: ";
    display(list3);
    cout << endl;
    
    Node* testSub1 = new Node(1);
    
    cout << "Attempt match: ";
    display(testSub1);
    cout << endl;
    display(isSubList(list3, testSub1));
    cout << endl;
    
    Node* testSub2 = new Node(3);
    testSub2 -> next = new Node(9);
    
    cout << "Attempt match: ";
    display(testSub2);
    cout << endl;
    display(isSubList(list3, testSub2));
    cout << endl;
    
    Node* testSub3 = new Node(2);
    testSub3 -> next = new Node(3);
    
    cout << "Attempt match: ";
    display(testSub3);
    cout << endl;
    display(isSubList(list3, testSub3));
    cout << endl;
    
    Node* testSub4 = new Node(2);
    testSub4 -> next = new Node(4);
    testSub4 -> next -> next = new Node(5);
    testSub4 -> next -> next -> next= new Node(6);
    
    cout << "Attempt match: ";
    display(testSub4);
    cout << endl;
    display(isSubList(list3, testSub4));
    cout << endl;
    
    Node* testSub5 = new Node(2);
    testSub5 -> next = new Node(3);
    testSub5 -> next -> next = new Node(2);
    testSub5 -> next -> next -> next= new Node(4);
    
    cout << "Attempt match: ";
    display(testSub5);
    cout << endl;
    display(isSubList(list3, testSub5));
    cout << endl;
    
    Node* testSub6 = new Node(5);
    testSub6 -> next = new Node(6);
    testSub6 -> next -> next = new Node(7);
    
    cout << "Attempt match: ";
    display(testSub6);
    cout << endl;
    display(isSubList(list3, testSub6));
    cout << endl;
}
