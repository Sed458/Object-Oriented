//
//  main.cpp
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include "Registrar.h"
#include <iostream>
#include <vector>
using namespace BrooklynPoly;
using namespace std;

//class Course;
//
//class Student{
//public:
//    Student(const string& _name) : name(_name) {}
//    
//    string getName() const {
//        return name;
//    }
//    
//    void addCourse(Course* course){
//        courses.push_back(course);
//    }
//    
//    void clearCourse(Course& course) {
//        for (size_t index = 0; index < courses.size(); ++index) {
//            if (courses[index] == &course) {
//                if (index == courses.size() - 1){
//                    courses.pop_back();
//                }
//                else{
//                    courses[index] = courses[courses.size() - 1];
//                    courses.pop_back();
//                }
//            }
//        }
//    }
//    
//private:
//    string name;
//    vector<Course*> courses;
//};
//
//
//
//class Course{
//public:
//    Course(const string& _name) : name(_name) {}
//    
//    string getName() const {
//        return name;
//    }
//    
//    void printCourseReport() const {
//        cout << name << ": " << endl;
//        for (Student* student : students){
//            cout << student->getName() << " ";
//        }
//        if (students.size() == 0){
//            cout << "None";
//        }
//        
//        cout << endl;
//    }
//    
//    void addStudent(Student* student) {
//        students.push_back(student);
//    }
//    
//    bool checkStudent(const string& name) const {
//        for (Student* student: students) {
//            if (student->getName() == name){
//                return true;
//            }
//        }
//        return false;
//    }
//    
//    void clearStudents() {
//        for (Student* student : students){
//            student->clearCourse(*this);
//        }
//        students.clear();
//    }
//    
//private:
//    string name;
//    vector<Student*> students;
//
//};
//
//class Registrar{
//public:
//    Registrar() {}
//    
//    bool addCourse(const string _name) {
//        if (findCourse(_name) == courses.size()) {
//            Course* newCourse = new Course(_name);
//            courses.push_back(newCourse);
//            return true;
//        }
//        return false;
//    }
//    
//    bool addStudent(const string _name) {
//        if (findStudent(_name) == students.size()) {
//            Student* newStudent = new Student(_name);
//            students.push_back(newStudent);
//            return true;
//        }
//        return false;
//    }
//    
//    bool enrollStudentInCourse(const string& studentName, const string& courseName){
//        size_t studentIndex = findStudent(studentName);
//        size_t courseIndex = findCourse(courseName);
//        
//        if (studentIndex != students.size() && courseIndex != courses.size()){
//            if (courses[courseIndex]->checkStudent(studentName) == false){
//                courses[courseIndex]->addStudent(students[studentIndex]);
//                students[studentIndex]->addCourse(courses[courseIndex]);
//            }
//        }
//        
//        return false;
//    }
//    
//    bool cancelCourse(const string& courseName) {
//        size_t courseIndex = findCourse(courseName);
//        
//        if (courseIndex != courses.size()) {
//            courses[courseIndex]->clearStudents();
//            if (courseIndex != courses.size() - 1) {
//                courses[courseIndex] = courses[courses.size() - 1];
//            }
//            delete courses[courses.size() - 1];
//            courses.pop_back();
//        }
//        
//        return false;
//    }
//    
//    void printReport() const {
//        for (Course* course: courses){
//            course->printCourseReport();
//        }
//    }
//    
//private:
//    vector<Course*> courses;
//    vector<Student*> students;
//    
//    // Finds course in vector and returns the size of the vector if not found
//    size_t findCourse(const string& name) const {
//        for (size_t index = 0; index < courses.size(); ++index){
//            if (courses[index]->getName() == name){
//                return index;
//            }
//        }
//        return courses.size();
//    }
//    
//    size_t findStudent(const string& name) const {
//        for (size_t index = 0; index < students.size(); ++index){
//            if (students[index]->getName() == name){
//                return index;
//            }
//        }
//        return students.size();
//    }
//};

int main() {
    
    Registrar registrar;
    
    cout << "No courses or students added yet\n";
//  cout << registrar.print << endl;
    registrar.printReport();
    
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
//    cout << registrar << endl;
    registrar.printReport();

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
//    cout << registrar << endl;
    registrar.printReport();
    
    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
//    cout << registrar << endl;
    registrar.printReport();
    
    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
//    cout << registrar << endl;
    registrar.printReport();
    
    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout <<  "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
//    cout << registrar << endl;
    registrar.printReport();
    
    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
//    cout << registrar << endl;
    registrar.printReport();
   
//    /*
//     // [OPTIONAL - do later if time]
//     cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//     registrar.changeStudentName("FritzTheCat", "MightyMouse");
//     cout << registrar << endl;  // or registrar.printReport()
//     
//     cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//     registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//     cout << registrar << endl;  // or registrar.printReport()
//     
//     cout << "RemoveStudent FritzTheCat\n";
//     registrar.removeStudent("FritzTheCat");
//     cout << registrar << endl;  // or registrar.printReport()
//     */
    
    cout << "Purge for start of next semester\n";
    registrar.purge();
//    cout << registrar << endl;
    registrar.printReport();
}
