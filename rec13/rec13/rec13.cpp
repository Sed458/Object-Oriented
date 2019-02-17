//
//  main.cpp
//  rec13
//
//  Created by Sophia Danielsen on 12/8/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

void printListIter(const list<int>& listInts){
    for(list<int>::const_iterator iter = listInts.begin(); iter != listInts.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void printListRanged(const list<int>& listInts){
    for (int num : listInts){
        cout << num << " ";
    }
    cout << endl;
}

void autoEveryOther(const list<int>& listInts) {
    for(auto index = listInts.begin(); index != listInts.end(); index++){
        cout << *index << " ";
        index++;
    }
    cout << endl;
}

list<int>::const_iterator findInList(const list<int>& listInts, int num){
    for(list<int>::const_iterator iter = listInts.begin(); iter != listInts.end(); iter++){
        if(*iter == num){
            return iter;
        }
    }
    return listInts.end();
}

auto findInListAuto(const list<int>& listInts, int num){
    for(list<int>::const_iterator iter = listInts.begin(); iter != listInts.end(); iter++){
        if(*iter == num){
            return iter;
        }
    }
    return listInts.end();
}

bool isEven(int n){
    return n % 2 == 0;
}

class Even {
public:
    bool operator() (int n) { return n % 2 == 0; }
};

auto ourFind(const list<int>::iterator& begin, const list<int>::iterator& end, int n){
    cout << "ourFind()" << endl;
    
    for(auto iter = begin; iter != end; iter++){
        if(*iter == n){
            return iter;
        }
    }
    
    return end;
    
}

template <typename T, typename U>
T ourFindTemplate(T begin, T end, U num){
    cout << "ourFindTemplate()" << endl;
    
    for(T iter = begin; iter != end; iter++){
        if(*iter == num){
            return iter;
        }
    }
    
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vecInts= {1, 2, 6, 4, 10, 3, 7, 5};
    cout << "Vector: ";
    for(int x : vecInts){
        cout << x << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> listInts(vecInts.begin(), vecInts.end());
    cout << "List: ";
    for(int x : listInts){
        cout << x << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vecInts.begin(), vecInts.end());
    
    cout << "Vector (sorted): ";
    for(int x : vecInts){
        cout << x << " ";
    }
    cout << endl;
    cout << "List: ";
    for(int x : listInts){
        cout << x << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    cout << "Vector (Every other element): ";
    for (size_t index = 0; index < vecInts.size(); index += 2){
        cout << vecInts[index] << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    cout << "List (Every other element): ";
    for (size_t index = 0; index < listInts.size(); index += 2){
//        cout << listInts[index] << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for(vector<int>::iterator index = vecInts.begin(); index != vecInts.end(); index += 2){
        cout << *index << " ";
    }
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for(list<int>::iterator index = listInts.begin(); index != listInts.end(); index++){
        cout << *index << " ";
        index++;
    }
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    listInts.sort();
    for(int x : listInts){
        cout << x << " ";
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printListIter(listInts);
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListRanged(listInts);
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    autoEveryOther(listInts);
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator iter1 = findInListAuto(listInts, 1);
    if (iter1 != listInts.end()){
        cout << *iter1 << endl;
    }
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto iter2 = findInListAuto(listInts, 1);
    if (iter2 != listInts.end()){
        cout << *iter2 << endl;
    }
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    auto iter3 = find(listInts.begin(), listInts.end(), 5);
    if (iter3 != listInts.end()){
        cout << *iter3 << endl;
    }
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    auto iter4 = find_if(listInts.begin(), listInts.end(), isEven);
    if (iter4 != listInts.end()){
        cout << *iter4 << endl;
    }
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    auto iter5 = find_if(listInts.begin(), listInts.end(), Even());
    if (iter5 != listInts.end()){
        cout << *iter5 << endl;
    }
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    auto iter6 = find_if(listInts.begin(), listInts.end(), [] (int n) { return n % 2 == 0; });
    if (iter6 != listInts.end()){
        cout << *iter6 << endl;
    }
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[8];
    copy(vecInts.begin(), vecInts.end(), arr);
    for(int n : arr){
        cout << n << " ";
    }
    cout << endl;
    
    int length = sizeof(arr);
    
    auto iter7 = find(arr, arr + length, 5);
    if (iter7 != arr + length){
        cout << *iter7 << endl;
    }
    
    auto iter8 = find_if(arr, arr + length, isEven);
    if (iter8 != arr + length){
        cout << *iter8 << endl;
    }
    
    auto iter9 = find_if(arr, arr + length, Even());
    if (iter9 != arr + length){
        cout << *iter9 << endl;
    }
    
    auto iter10 = find_if(arr, arr + length, [] (int n) { return n % 2 == 0; });
    if (iter10 != arr + length){
        cout << *iter10 << endl;
    }
    
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    auto iter11 = ourFind(listInts.begin(), listInts.end(), 5);
    if (iter11 != listInts.end()){
        cout << *iter11 << endl;
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    auto iter12 = ourFindTemplate(vecInts.begin(), vecInts.end(), 5);
    if (iter12 != vecInts.end()){
        cout << *iter12 << endl;
    }
    
    auto iter13 = ourFindTemplate(listInts.begin(), listInts.end(), 5);
    if (iter13 != listInts.end()){
        cout << *iter13 << endl;
    }
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing
    cout << "Task 21:\n";
    vector<string> vecString;
    
    ifstream inFile("pooh-nopunc.txt");
    
    if (!inFile) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    
    string word;
    
    while (inFile >> word) {
        if (find(vecString.begin(), vecString.end(), word) == vecString.end()){
            vecString.push_back(word);
        }
    }
    
    inFile.close();
    
    cout << "Length: " << vecString.size() << endl;
    cout << "Contents: " << endl;
    for(string word: vecString){
        cout << word << " ";
    }
    
    cout << endl;
    
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> setString;
    
    ifstream inFile2("pooh-nopunc.txt");
    
    if (!inFile2) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    
    while(inFile2 >> word) {
        setString.insert(word);
    }
    
    inFile2.close();
    
    cout << "Length: " << setString.size() << endl;
    cout << "Contents: " << endl;
    for(string word: setString){
        cout << word << " ";
    }
    
    cout << endl;
    
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> mapString;
    
    ifstream inFile3("pooh-nopunc.txt");
    
    if (!inFile3) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    
    int position = 0;
    
    while(inFile3 >> word) {
        mapString[word].push_back(position);
        position++;
    }
    
    inFile3.close();
    
    cout << "Length: " << mapString.size() << endl;
    cout << "Contents: " << endl;
    for(const auto& word: mapString){
        cout << word.first << ": ";
        for(const auto& position : mapString[word.first]){
            cout << position << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    cout << "=======\n";
}
