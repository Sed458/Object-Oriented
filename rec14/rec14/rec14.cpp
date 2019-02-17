//
//  main.cpp
//  rec14
//
//  Created by Sophia Danielsen on 12/14/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// Task 1
bool evenNumOnes(int n) {
    if (n < 3) { return false; }
    return (evenNumOnes(n/2) + (n % 2)) % 2;
}

// Task 2
Node* sumLists(Node* list1, Node* list2){
    if(list1 -> next == nullptr){
        return new Node(list1 -> data + list2 -> data);
    }
    
    Node* newNode = new Node(list1 -> data + list2 -> data);
    newNode -> next = sumLists(list1 -> next, list2 -> next);
    return newNode;
}

// Task 3
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int max(TNode* root) {
    if (root -> left == nullptr && root -> right == nullptr) {
        return root -> data;
    }
    
    int maxVal = root -> data;
    
    if (root -> left != nullptr){
        int left = max(root -> left);
        if (left > maxVal) {
            maxVal = left;
        }
    }
    if (root -> right != nullptr){
        int right = max(root -> right);
        if (right > maxVal) {
            maxVal = right;
        }
    }
    return maxVal;
}


// Task 4
bool palindrome(char* arr, int numOfChars){
    if (numOfChars <= 1) { return true; }
    return (*arr == *(arr + numOfChars - 1)) && palindrome(arr + 1, numOfChars - 2);
}

// Task 5
int towers(int n, char start, char helper, char target){
    if (n <= 0) return 0;
    int count = 0;
    count += towers(n-1, start, target, helper);
    count += towers(n-1, helper, start, target) + 1;
    return count;
}


// Task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main() {
    // Task 1
    if(evenNumOnes(8)) {
        cout << "true" << endl;;
    }
    else {
        cout << "false" << endl;
    }
    
    if(evenNumOnes(10)) {
        cout << "true" << endl;;
    }
    else {
        cout << "false" << endl;
    }
    
    // Task 2
    Node* list1 = new Node(1);
    Node* toAdd = new Node(4);
    list1 -> next = toAdd;
    
    Node* list2 = new Node(3);
    Node* toAdd2 = new Node(7);
    list2 -> next = toAdd2;
    
    Node* sum = sumLists(list1, list2);
    Node* cursor = sum;
    
    while (cursor != nullptr) {
        cout << cursor -> data << " ";
        cursor = cursor -> next;
    }
    
    cout << endl;
    
    // Task 3
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << max(&f) << endl;
    
    // Task 4
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    
    // Task 5
    cout << towers(1, 'a', 'b', 'c') << endl; //: 1
    cout << towers(2, 'a', 'b', 'c') << endl; //: 3
    cout << towers(3, 'a', 'b', 'c') << endl; //: 7
    cout << towers(4, 'a', 'b', 'c') << endl; //: 15
    cout << towers(5, 'a', 'b', 'c') << endl; //: 31
    cout << towers(6, 'a', 'b', 'c') << endl; //: 63
    cout << towers(7, 'a', 'b', 'c') << endl; //: 127
    cout << towers(8, 'a', 'b', 'c') << endl; //: 255
    cout << towers(9, 'a', 'b', 'c') << endl; //: 511
    cout << towers(10, 'a', 'b', 'c') << endl; //: 1023
    cout << towers(12, 'a', 'b', 'c') << endl;
    
    mystery(4);
    
}
