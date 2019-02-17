//
//  Registrar.h
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#ifndef Registrar_h
#define Registrar_h

#include <string>
#include <vector>

namespace BrooklynPoly {

    class Student;
    class Course;

    class Registrar{
    public:
        bool addCourse(const std::string _name);
        
        bool addStudent(const std::string _name);
        
        bool enrollStudentInCourse(const std::string& studentName, const std::string& courseName);
        
        bool cancelCourse(const std::string& courseName);
        
        void purge();
        
        void printReport() const;
        
        // Finds course in vector and returns the size of the vector if not found
        size_t findCourse(const std::string& name) const;
        
        // Finds student in vector and returns the size of the vector if not found
        size_t findStudent(const std::string& name) const;
        
    private:
        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}

#endif /* Registrar_h */
