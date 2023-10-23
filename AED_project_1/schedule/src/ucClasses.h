//
// Created by pchmelo on 10-10-2023.
//
#include "pairUcClasses.h"
#include "string"
#include "map"
#include "vector"
#include "utility"
#ifndef PROJETO_1_UC_H
#define PROJETO_1_UC_H

class ucClasses {
    private:
        std::map<std::string, std::vector<std::string>> classesPerUc;
        //std::map<std::string, std::vector<std::string>> ucsPerClass;

    public:
      //ucClasses();
        ucClasses(pairUcClasses pUcClasse);

        std::map<std::string, std::vector<std::string>> get_classesPerUc();
        //std::map<std::string, std::vector<std::string>> get_ucsPerClass();

        std::vector<std::string> get_classes(std::string uc);
        //std::vector<std::string> get_ucs(std::string classe);

};

#endif //PROJETO_1_UC_H
