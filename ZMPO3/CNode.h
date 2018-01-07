//
// Created by Admin on 2017-12-22.
//

#ifndef ZMPO3_CNODE_H
#define ZMPO3_CNODE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Const.h"


class CNode {

public:

    friend class CTree;
    CNode();
    CNode(CNode &toCopy);
    CNode(int childrenCount, CNode *parent, std::string value);
    ~CNode();

private:

    int childrenCount;//children count of node - depends on it content
    std::vector <CNode*> children;//pointers on children
    std::string value;//node value
    CNode *parent;

    double count(std::vector <std::string> *variables, std::vector <double> *values);
    double getVarValue(std::vector <std::string> *variables, std::vector <double> *values);//this function return value of variable
    bool isOnlyDouble(const char* str);
    bool isVariable(std::string value);//this function check if value of Node is variable
};

#endif //ZMPO3_CNODE_H
