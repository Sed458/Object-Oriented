//
//  main.cpp
//  rec04
//
//  Created by Sophia Danielsen on 9/28/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Complex {
    double real;
    double img;
};

class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int x )  { this->x = x; }
private:
    int x;
};

class Colour {
public:
    Colour( const string& name, unsigned r, unsigned g, unsigned b )
    : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string   name;    // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};

class SpeakerSystem {
public:
    void vibrateSpeakerCones( unsigned signal ) const {
        
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    void attachSpeakers( const SpeakerSystem& spkrs )
    {
        if( attachedSpeakers )
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }
    void detachSpeakers()
    { attachedSpeakers = nullptr; }
    // should there be an "error" message if not attached?
    void playMusic( ) const {
        if( attachedSpeakers )
            attachedSpeakers -> vibrateSpeakerCones( 440 );
        else
            cout << "No speakers attached\n";
    }
private:
    const SpeakerSystem* attachedSpeakers = nullptr;
};

class Person {
public:
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        if (newRoomate.roomie != nullptr){
            cout << newRoomate.getName() << " already has a roommate." << endl;
        }
        else if (this == &newRoomate){
            cout << "Cannot become roommate with him/herself" << endl;
        }
        else if (roomie == nullptr){
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
        }
        else{
            cout << name << " already has a roommate." << endl;
        }
    }
    string getName() const {
        return name;
    }
    // Don't need to use getName() below, just there for you to use in debugging.
    string getRoomiesName() const {
        if (roomie == nullptr) {
            return "no roommate";
        }
        return roomie->getName();
    }
private:
    Person* roomie;
    string name;
};


int main() {
    //  Task 2
    int x;
    x = 10;
    cout << "x = " << x << endl;
    
    cout << endl;
    
    // Task 8
    int* p;
    p = &x;
    // p = 0x7fff5fbff6bc;   error
    cout << "p = " << p << endl;
    
    cout << endl;
    
    // Task 10
    cout << "p points to where " << *p << " is stored\n";    // *p is a dereference operator
    cout << "*p contains " << *p << endl;
    
    cout << endl;
    
    // Task 11
    *p = -2763;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    cout << endl;
    
    // Task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
    cout << endl;
    
    // Task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    cout << endl;
    
    // Task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    // pD  = p;              cannot assign int* to double* or vice versa
    // p   = pD;
    
    
    // Task 15
    int joe( 24 );
    const int sal( 19 );
    int*  pI;
    pI = &joe;
    //*pI = 234;
    // pI = &sal;                       cannot assign from int* to const int*
    // *pI = 7623;
    
    const int* pcI;                         // read only
    pcI = &joe;
    // *pcI = 234;                      cannot change value since const int* pcI is read only
    pcI = &sal;
    // *pcI = 7623;                     cannot change value since const int* pcI is read only
    
    // int* const cpI;                  default initialization
    int* const cpI(&joe);
    // int* const cpI(&sal);            sal is already a const int (redefinition)
    // cpI = &joe;                      cannot change value of cpI
    *cpI = 234;                             // changes value of joe to 234
    // cpI = &sal;                      cannot change value of cpI
    *cpI = 7623;                            // changes value of joe to 7623
    
    // const int* const cpcI;           default initialization
    const int* const cpcI(&joe);
    // const int* const cpcI(&sal);     cannot redefine cpcI
    // cpcI = &joe;                     cannot change value of cpI
    // *cpcI = 234;                     cannot change value of joe since cpcI is const int* const (read only)
    // cpcI = &sal;                     cannot change value of cpI
    // *cpcI = 7623;                    cannot change value of joe since cpcI is const int* const (read only)
    
    
    // Task 16
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    // cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img<< endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;           // -> only works when referencing structs of classes
    
    cout << endl;
    
    // Task 17
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    cout << endl;
    
    // Task 19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    
    cout << endl;
    
    // Task 20 & 21
    cout << pDyn << endl;
    delete pDyn;
    pDyn = nullptr;
    cout << pDyn << endl;
    
//    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
//    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    double* pDouble( nullptr );
    
    // Task 22
    // cout << "Can we dereference nullptr?  " << *pDyn << endl;
    // cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    // Task 24
    double* pTest = new double( 12 );
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    // Task 25
    short* pShrt = new short( 5 );
    delete pShrt;
    // delete pShrt;
    
    // Task 26
    long jumper( 12238743 );
    // delete jumper;                  cannot delete
    long* ptrTolong( &jumper );
    // delete ptrTolong;               cannot delete
    Complex cmplx;
    // delete cmplx;                   cannot delete
    
    // Task 27
    vector<Complex*> complV;                         // can hold pointers to Complex objects
    Complex* tmpPCmplx;                              // space for a Complex pointer
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        tmpPCmplx = new Complex;                     // create a new Complex object on the heap
        tmpPCmplx->real = ndx;                       // set real and img to be the
        tmpPCmplx->img  = ndx;                       // value of the current ndx
        complV.push_back( tmpPCmplx );               // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for ( size_t ndx = 0 ; ndx < 3 ; ++ndx ) {
        delete complV[ ndx ];
    }      
    // clear the vector      
    complV.clear();
    
    cout << endl;
    
    // Task 28
    vector< Colour* > colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    //(so we don't have to create an actual file)
    // do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
     while ( cin >> inputName >> inputR >> inputG >> inputB ) {
         colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
     }
     
     // display all the Colours in the vector:
     for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
         colours[ndx]->display();
         cout << endl;       
     }
    
    // Task 29
    Amplifier amp;
    amp.playMusic();
    SpeakerSystem speaker;
    amp.attachSpeakers(speaker);
    amp.playMusic();
    
    // Task 30
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane"), harveySpec("Harvey Spec"), johnSmith("John Smith");
    cout << "Roomie: " << joeBob.getRoomiesName() << endl;
    // now model these two becoming roommates
    joeBob.movesInWith( billyJane );
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    
    harveySpec.movesInWith(billyJane);
    joeBob.movesInWith(joeBob);
    joeBob.movesInWith(harveySpec);

}
