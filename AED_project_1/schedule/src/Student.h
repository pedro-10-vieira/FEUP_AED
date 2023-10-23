//
// Created by pchmelo on 10-10-2023.
//

#include "vector"
#include "string"
#include "pairUcClasses.h"
#include "iostream"

#ifndef PROJETO_1_STUDENT_H
#define PROJETO_1_STUDENT_H


class Student{
    protected:
        std::string name;
        int idNum;
        std::vector<pairUcClasses> std_uc;
        //pairUcClasses std_uc;
    public:
        //student();
        Student(int idNum, std::string name, std::string uc, std::string classe);

        std::string get_name();
        int get_idNum();

        std::vector<pairUcClasses> get_pairUcClasses();
        void print();
        //pairUcClasses get_paiUcClasses();
};


#endif //PROJETO_1_STUDENT_H
