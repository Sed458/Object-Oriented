//
//  Student.cpp
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//
#include "Student.h"
#include "Course.h"

#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly {
    Student::Student(const string& _name) : name(_name) {}
        
    string Student::getName() const {
        return name;
    }
        
    void Student::addCourse(Course* course){
        courses.push_back(course);
    }
        
    void Student::clearCourse(Course& course) {
        for (size_t index = 0; index < courses.size(); ++index) {
            if (courses[index] == &course) {
                if (index == courses.size() - 1){
                    courses.pop_back();
                }
                else{
                    courses[index] = courses[courses.size() - 1];
                    courses.pop_back();
                }
            }
        }
    }
}
