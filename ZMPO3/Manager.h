//
// Created by Admin on 2017-12-28.
//

#ifndef ZMPO3_MANAGER_H
#define ZMPO3_MANAGER_H

#include "Tree.h"

class Manager {

public:
    Manager(){
        tree=NULL;
    }
    void enter(std::string data);
    void joint(std::string data);
    void print();
    void vars();
    void comp(std::string data);
    void deleteTree();
    bool isEmpty();


private:
    CTree *tree;
    bool isLathin(char letter);
    bool isNumber(char letter);
    bool isCommonOperation(char letter);
    bool isDouble(const std::string& s);

};

#endif //ZMPO3_MANAGER_H
