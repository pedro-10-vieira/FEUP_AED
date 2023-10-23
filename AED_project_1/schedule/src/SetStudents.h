//
// Created by pchmelo on 18-10-2023.
//

#include "Student.h"
#include "set"

#ifndef PROJETO_1_SETSTUDENTS_H
#define PROJETO_1_SETSTUDENTS_H


class SetStudents {
    private:
        std::set<Student> setStudents;

    public:
        void insert_student(Student student);
        
};


#endif //PROJETO_1_SETSTUDENTS_H
