//
//  Course.cpp
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include "Course.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly {
    Course::Course(const string& _name) : name(_name) {}
    
    string Course::getName() const {
        return name;
    }
    
    void Course::printCourseReport() const {
        cout << name << ": " << endl;
        for (Student* student : students){
            cout << student->getName() << " ";
        }
        if (students.size() == 0){
            cout << "None";
        }
        
        cout << endl;
    }
    
    void Course::addStudent(Student* student) {
        students.push_back(student);
    }
    
    bool Course::checkStudent(const string& name) const {
        for (Student* student: students) {
            if (student->getName() == name){
                return true;
            }
        }
        return false;
    }
    
    void Course::clearStudents() {
        for (Student* student : students){
            student->clearCourse(*this);
        }
        students.clear();
    }
}
