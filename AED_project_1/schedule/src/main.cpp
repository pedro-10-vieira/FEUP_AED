#include "iostream"
#include "fstream"
#include "sstream"
#include "ucClasses.h"
#include "Student.h"
#include "string"
#include "pairUcClasses.h"

pairUcClasses read_file_pairUcClasses(std::string input){
    std::ifstream MyReadFile(input);
    std::string line;
    std::vector<std::string> t;
    bool flag = true;

    while(getline(MyReadFile, line)){
        std::stringstream ss(line);

        if(flag){
            flag = false;
            continue;
        }

        while(ss.good()){
            std::string subtr;
            getline(ss, subtr, ',');
            t.push_back(subtr);
        }
        return pairUcClasses(t[0], t[1]);

    }
    return pairUcClasses("a","b");
}


Student read_file_student(std::string input){
    std::ifstream MyReadFile(input);
    std::string line;
    std::vector<std::string> t;
    std::pair<std::string, std::string> t_1;
    bool flag = true;

    while(getline(MyReadFile, line)){
        std::stringstream ss(line);

        if(flag){
            flag = false;
            continue;
        }

        while(ss.good()){
            std::string subtr;
            getline(ss, subtr, ',');
            t.push_back(subtr);
        }

        return Student(std::stoi(t[0]), t[1], t[2], t[3]);
    }

    return Student(0,"0","0","0");
}

int main(){

    pairUcClasses t_1 = read_file_pairUcClasses("/home/pchmelo/Desktop/AED/projeto_1/schedule/src/dataSet/classes_per_uc.csv");
    Student t_2 = read_file_student("/home/pchmelo/Desktop/AED/projeto_1/schedule/src/dataSet/students_classes.csv");

    t_1.print();
    t_2.print();

    return 0;
}


