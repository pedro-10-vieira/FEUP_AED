//
// Created by pchmelo on 10-10-2023.
//

#include "ucClasses.h"

/*
ucClasses::ucClasses() {
    std::string t_1 = " ";
    std::vector<std::string> t_2;

    classesPerUc = NULL;
    ucsPerClass = NULL;
}
*/
ucClasses::ucClasses(pairUcClasses pUcClasses) {
    std::vector <std::string> t;
    std::string uc = pUcClasses.get_uc();
    std::string classe = pUcClasses.get_classe();

    if(classesPerUc.find(uc) != classesPerUc.end()){
        classesPerUc[uc].push_back(classe);
    }
    else{
        t.push_back(classe);
        classesPerUc.insert({uc, t});
        t.clear();
    }

    /*
    if(ucsPerClass.find(classe) != ucsPerClass.end()){
        ucsPerClass[classe].push_back(uc);
    }
    else{
        t.push_back(uc);
        ucsPerClass.insert({classe, t});
        t.clear();
    }
    */
}

std::map<std::string, std::vector<std::string>> ucClasses::get_classesPerUc() {
    return classesPerUc;
}
/*
std::map <std::string, std::vector<std::string>> ucClasses::get_ucsPerClass() {
    return ucsPerClass;
}
*/

std::vector <std::string> ucClasses::get_classes(std::string uc){
    return classesPerUc[uc];
}

/*
std::vector<std::string> ucClasses::get_ucs(std::string classe) {
    return ucsPerClass[classe];
}
 */

