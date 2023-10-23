//
// Created by pchmelo on 10-10-2023.
//

#include "Student.h"

Student::Student(int idNum, std::string name, std::string uc, std::string classe){
    this->name = name;
    this->idNum = idNum;
    //this->std_uc = pairUcClasses(uc, classe);
    std_uc.push_back(pairUcClasses(uc, classe));
}

std::string Student::get_name() {
    return name;
}

int Student::get_idNum() {
    return idNum;
}


std::vector<pairUcClasses> Student::get_pairUcClasses() {
    return std_uc;
}

void Student::print() {
    for(pairUcClasses uc : std_uc){
        std::cout << idNum <<", " << name << ", " << uc.get_uc() << ", " << uc.get_classe() << '\n';
    }
}

/*
pairUcClasses Student::get_paiUcClasses() {
    return std_uc;
}
*/