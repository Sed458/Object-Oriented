//
//  main.cpp
//  rec09
//
//  Created by Sophia Danielsen on 11/2/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned _numOfPages) : numberOfPages(_numOfPages) {}
    
    virtual void displayNumPages() const = 0;
protected:
    unsigned getNumPages() {
        return numberOfPages;
    }
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << "Number of Pages: " << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
    
    void displayNumPages() const {
        cout << "Magazine ~ " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
    
    void displayNumPages() const {
        cout << "Book ~ " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numberOfPages, unsigned numIndex) : Book(numberOfPages), numberOfIndex(numIndex) {}
    
    void displayNumPages() const {
        cout << "Textbook ~ " << endl;
        PrintedMaterial::displayNumPages();
        cout << " Number of Indexes: " << numberOfIndex << endl;
    }
protected:
private:
    int numberOfIndex;
};

class Novel : public Book {
public:
    Novel(unsigned numberOfPages) : Book(numberOfPages) {}
    
    void displayNumPages() const {
        cout << "Novel ~ " << endl;
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm)
{
    pm.displayNumPages();
}

// tester/modeler code
int main()
{
    TextBook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    // PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
    // pm.displayNumPages();
    
    // PrintedMaterial* pmPtr;
    // pmPtr = &t;
    // pmPtr->displayNumPages();
    
    displayNumberOfPages(m);
    displayNumberOfPages(n);
    displayNumberOfPages(t);
    
    vector<PrintedMaterial*> printedMaterials;
    printedMaterials.push_back(&t);
    printedMaterials.push_back(&n);
    printedMaterials.push_back(&m);
    for( size_t index=0; index < printedMaterials.size(); ++ index )
    {
        printedMaterials[index]->displayNumPages();
    }
}
