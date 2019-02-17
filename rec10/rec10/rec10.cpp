//
//  main.cpp
//  rec10
//
//  Created by Sophia Danielsen on 11/10/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    virtual void makeSound() const = 0;
    
    virtual void normalPlaying() const = 0;
private:
    
};

void Instrument::makeSound() const {
    cout << "To make a sound... ";
}

class Brass : public Instrument {
public:
    Brass(unsigned _size) : size(_size) {}
    
    void makeSound() const {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << size << endl;
    }
private:
    unsigned size;
};

class Trumpet : public Brass {
public:
    Trumpet(unsigned size) : Brass(size) {}
    
    void normalPlaying() const {
        cout << "Toot";
    }
};

class Trombone : public Brass {
public:
    Trombone(unsigned size) : Brass(size) {}
    
    void normalPlaying() const {
        cout << "Blat";
    }
};

class String : public Instrument {
public:
    String(unsigned _pitch) : pitch(_pitch) {}
    
    void makeSound() const {
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }
private:
    unsigned pitch;
};

class Violin : public String {
public:
    Violin(unsigned pitch) : String(pitch) {}
    
    void normalPlaying() const {
        cout << "Screech";
    }
};

class Cello : public String {
public:
    Cello(unsigned pitch) : String(pitch) {}
    
    void normalPlaying() const {
        cout << "Squawk";
    }
};

class Percussion : public Instrument {
    // default constructor
    
    void makeSound() const {
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
};

class Drum : public Percussion {
    // default constructor
    
    void normalPlaying() const {
        cout << "Boom";
    }
};

class Cymbal : public Percussion {
    // default constructor
    
    void normalPlaying() const {
        cout << "Crash";
    }
};

class Musician {
public:
    Musician() : instr(nullptr) {}
    void acceptInstr(Instrument& i) { instr = &i; }
    Instrument* giveBackInstr() {
        Instrument* tmp(instr);
        instr = nullptr;
        return tmp;
    }
    void testPlay() const {
        if(instr)
            instr->makeSound();
        else
            cerr << "have no instr\n";
    }
    
    void normalPlay() const {
        if(instr) {
            instr->normalPlaying();
        }
    }
    
private:
    Instrument* instr;
};

class MILL {
public:
//    void receiveInstr(Instrument& instr) {
//        vectorOfInstr.push_back(&instr);
//    }
    
    void dailyTestPlay() const {
        for (Instrument* instr : vectorOfInstr) {
            if (instr != nullptr) {
                instr -> makeSound();
            }
        }
    }
    
    Instrument* loanOut() {
        for (size_t index = 0; index < vectorOfInstr.size(); ++index) {
            if (vectorOfInstr[index] != nullptr) {
                Instrument* instrPointer = vectorOfInstr[index];
                vectorOfInstr[index] = nullptr;
                return instrPointer;
            }
        }
        return nullptr;
    }
    
    void receiveInstr(Instrument& instr){
        bool placed = false;
        for (size_t index = 0; index < vectorOfInstr.size(); ++index) {
            if (placed == false) {
                if (vectorOfInstr[index] == nullptr) {
                    vectorOfInstr[index] = &instr;
                    placed = true;
                }
            }
        }
        if (placed == false) {
            vectorOfInstr.push_back(&instr);
        }
    }
    
private:
    vector<Instrument*> vectorOfInstr;
};

class Orch {
public:
    bool addPlayer(Musician& musician) {
        if (vectorOfMusicians.size() <= 24) {
            vectorOfMusicians.push_back(&musician);
            return true;
        }
        return false;
    }
    
    void play() const {
        for (Musician* musician : vectorOfMusicians) {
            musician -> normalPlay();
        }
        
        cout << endl;
    }
private:
    vector<Musician*> vectorOfMusicians;
};

int main() {

// Part One
    
//     cout << "Define some instruments ----------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12);
//     Violin violin(567);
//    
//     // use the debugger to look at the mill
//     cout << "Define the MILL ------------------------------------------------\n";
//     MILL mill;
//    
//     cout << "Put the instruments into the MILL ------------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//    
//     cout << "Daily test -----------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//    
//     cout << "Define some Musicians-------------------------------------------\n";
//     Musician j;
//     Musician jj;
//     Musician q;
//    
//     cout << "TESTING: q.acceptInstr(*mill.loanOut());-----------------------\n";
//     q.testPlay();
//     cout << endl;
//     q.acceptInstr(*mill.loanOut());
//     cout << endl;
//     q.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//    
//     cout << endl << endl;
//    
//     q.testPlay();
//     cout << endl;
//     mill.receiveInstr(*q.giveBackInstr());
//     j.acceptInstr(*mill.loanOut());
//     q.acceptInstr(*mill.loanOut());
//     cout << endl;
//     q.testPlay();
//     cout << endl;
//     j.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//    
//     cout << "TESTING: mill.receiveInstr(*q.giveBackInstr()); -------------\n";
//    
//     // fifth
//     mill.receiveInstr(*q.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*j.giveBackInstr()); -------------\n";
//     mill.receiveInstr(*j.giveBackInstr());
//    
//    
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//    
//     cout << endl;

    
// Part Two
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);
    
    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(*mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(*mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(*mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(*mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(*mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(*mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(*mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

}

