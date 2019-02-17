//
//  Course.h
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#ifndef Course_h
#define Course_h

#include <string>
#include <vector>

namespace BrooklynPoly {

    class Student;

    class Course{
    public:
        Course(const std::string& _name);
        
        std::string getName() const;
        
        void printCourseReport() const;
        
        void addStudent(Student* student);
        
        bool checkStudent(const std::string& name) const;
        
        void clearStudents();
        
    private:
        std::string name;
        std::vector<Student*> students;
        
    };
}

#endif /* Course_h */
