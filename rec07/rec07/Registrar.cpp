//
//  Registrar.cpp
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include "Registrar.h"
#include "Course.h"
#include "Student.h"

#include <string>
#include <vector>
using namespace std;

namespace BrooklynPoly {
    
    bool Registrar::addCourse(const string _name) {
        if (findCourse(_name) == courses.size()) {
            Course* newCourse = new Course(_name);
            courses.push_back(newCourse);
            return true;
        }
        return false;
    }
    
    bool Registrar::addStudent(const string _name) {
        if (findStudent(_name) == students.size()) {
            Student* newStudent = new Student(_name);
            students.push_back(newStudent);
            return true;
        }
        return false;
    }
    
    bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName){
        size_t studentIndex = findStudent(studentName);
        size_t courseIndex = findCourse(courseName);
        
        if (studentIndex != students.size() && courseIndex != courses.size()){
            if (courses[courseIndex]->checkStudent(studentName) == false){
                courses[courseIndex]->addStudent(students[studentIndex]);
                students[studentIndex]->addCourse(courses[courseIndex]);
            }
        }
        
        return false;
    }
    
    bool Registrar::cancelCourse(const string& courseName) {
        size_t courseIndex = findCourse(courseName);
        
        if (courseIndex != courses.size()) {
            courses[courseIndex]->clearStudents();
            if (courseIndex != courses.size() - 1) {
                courses[courseIndex] = courses[courses.size() - 1];
            }
            delete courses[courses.size() - 1];
            courses.pop_back();
        }
        
        return false;
    }
    
    void Registrar::purge() {
        for (Course* course : courses) {
            course->clearStudents();
            delete course;
        }
        
        courses.clear();
        
        for (Student* student : students){
            delete student;
        }
        students.clear();
    }
    
    void Registrar::printReport() const {
        for (Course* course: courses){
            course->printCourseReport();
        }
    }
    
    // Finds course in vector and returns the size of the vector if not found
    size_t Registrar::findCourse(const string& name) const {
        for (size_t index = 0; index < courses.size(); ++index){
            if (courses[index]->getName() == name){
                return index;
            }
        }
        return courses.size();
    }
    
    // Finds student in vector and returns the size of the vector if not found
    size_t Registrar::findStudent(const string& name) const {
        for (size_t index = 0; index < students.size(); ++index){
            if (students[index]->getName() == name){
                return index;
            }
        }
        return students.size();
    }
}
