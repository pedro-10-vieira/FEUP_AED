//
// Created by pchmelo on 18-10-2023.
//

#include "SetStudents.h"

void SetStudents::read_file() {
    std::string dir_file = "/home/pchmelo/Desktop/AED/projeto_1/schedule/src/dataSet/students_classes.csv";

    std::ifstream MyReadFile(dir_file);
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


    }

    return Student(0,"0","0","0");
}