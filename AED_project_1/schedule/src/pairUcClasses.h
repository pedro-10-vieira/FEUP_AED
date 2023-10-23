//
// Created by pchmelo on 11-10-2023.
//
#include "string"
#include "utility"
#include "iostream"
#ifndef PROJETO_1_PAIRUCCLASSES_H
#define PROJETO_1_PAIRUCCLASSES_H


class pairUcClasses {
    protected:
        std::pair<std::string, std::string> pUcClasse;

    public:
        //pairUcClasses();
        pairUcClasses(std::string uc, std::string classe);

        std::string get_uc();
        std::string get_classe();

        void print();

};


#endif //PROJETO_1_PAIRUCCLASSES_H
