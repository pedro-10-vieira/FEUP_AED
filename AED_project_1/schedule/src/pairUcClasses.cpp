//
// Created by pchmelo on 11-10-2023.
//

#include "pairUcClasses.h"
#include "string"

pairUcClasses::pairUcClasses(std::string uc, std::string classe){
    pUcClasse.first = uc;
    pUcClasse.second = classe;
}

std::string pairUcClasses::get_classe() {
    return pUcClasse.second;
}

std::string pairUcClasses::get_uc() {
    return pUcClasse.first;
}

void pairUcClasses::print() {
    std::cout << pUcClasse.first << ", " << pUcClasse.second << '\n';
}
