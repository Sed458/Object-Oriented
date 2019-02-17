//
//  Student.h
//  rec07
//
//  Created by Sophia Danielsen on 10/20/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <string>
#include <vector>

namespace BrooklynPoly {

    class Course;

    class Student{
    public:
        Student(const std::string& _name);
        
        std::string getName() const;
        
        void addCourse(Course* course);
        
        void clearCourse(Course& course);
        
    private:
        std::string name;
        std::vector<Course*> courses;
    };
}

#endif /* Student_h */
