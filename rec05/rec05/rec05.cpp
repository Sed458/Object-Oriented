//
//  main.cpp
//  rec05
//
//  Created by Sophia Danielsen on 10/6/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section {
public:
    Section (string _name, string _dayOfWeek, int _hour) : name(_name), timeSlot(_dayOfWeek, _hour) {}
    
    Section (const Section& section) {
        name = section.name;
        timeSlot = section.timeSlot;
        for (Student* student : section.students){
            Student* studentPointer =  new Student(*student);
            students.push_back(studentPointer);
        }
        
        
    }
    
    ~Section() {
        cout << "Deleting Section " << name << endl;
        for (Student* studentPointer : students){
            cout << "Deleting " << studentPointer->getName() << endl;
            delete studentPointer;
        }
    }
    
    void addStudent(string name) {
        Student* studentPointer =  new Student(name);
        students.push_back(studentPointer);
    }
    
    size_t findStudent(const string& studentName) {
        for(size_t index = 0; index < students.size(); index++){
            if (students[index]->getName() == studentName) {
                return index;
            }
        }
        return students.size();
    }
    
    void reset(){
        for (Student* studentPointer: students) {
            delete studentPointer;
        }
        
        students.clear();
    }
    
    void changeGrade(string studentName, int grade, int week) {
        size_t index = this->findStudent(studentName);
        students[index]->changeGrade(week, grade);
    }
    
    string getName() const {
        return name;
    }
    
    void display() const {
        cout << "Section: " << name << ", Time Slot: [Day: " << timeSlot.getDayOfWeek() << ", Start Time: " << timeSlot.getHour() << timeSlot.getTimeOfDay() << "], Students: ";
        if (students.size() == 0) {
            cout << "None" << endl;
        }
        else {
            for (size_t index = 0; index < students.size(); index++) {
                cout << endl;
                students[index]->display();
            }
        }
        cout << endl;
    }
    
private:
    class TimeSlot {
    public:
        TimeSlot(){}
    
        TimeSlot (string& _dayOfWeek, int _hour) : dayOfWeek(_dayOfWeek), hour(_hour) {}
        
        string getDayOfWeek() const {
            return dayOfWeek;
        }
        
        unsigned getHour() const {
            if (hour > 12) {
                return hour - 12;
            }
            return hour;
        }
        
        string getTimeOfDay() const {
            if (hour > 11)
                return "pm";
            else{
                return "am";
            }
        }
        
    private:
        string dayOfWeek;
        int hour;
    };
    
    class Student {
    public:
        Student(string& _name) : name(_name), grades(14, -1) {}
        
        string getName() const {
            return name;
        }
        
        void changeGrade(int week, int grade) {
            grades[week-1] = grade;
        }
        
        void display() const {
            cout << "Name: " << name << ", Grades: ";
            for (size_t index = 0; index < grades.size(); index++) {
                cout << grades[index] << " ";
            }
        }
        
    private:
        string name;
        vector<int> grades;
    };
    
    string name;
    TimeSlot timeSlot;
    vector<Student*> students;
};


class LabWorker {
public:
    LabWorker(string _name) : name(_name) {}
    
    void addSection(Section& _labSection) {
        labSection = &_labSection;
    }
    
    void addGrade(string studentName, int grade, int week){
        labSection->changeGrade(studentName, grade, week);
    }
    
    void display() const {
        if (labSection == nullptr) {
            cout << name << " does not have a section." << endl;
        }
        else{
            cout << name << " has ";
            labSection->display();
        }
    }
    
private:
    string name;
    Section* labSection;
};


// Test code
void doNothing(Section sec) { sec.display(); }

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    secA2.display();
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    secA2.display();

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    moe.display();

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    moe.display();

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    jane.display();

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    moe.display();

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    moe.display();

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main
