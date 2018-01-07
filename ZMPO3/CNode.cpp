//
// Created by Admin on 2017-12-22.
//

#include "CNode.h"


//Class CNode
CNode::CNode() {
    value = "";
    childrenCount = 0;
    parent = NULL;
}

CNode::CNode(CNode &toCopy) {
    value = toCopy.value;
    childrenCount = toCopy.childrenCount;
    int support = toCopy.children.size();
    for (int i = 0; i < support; i++) {
        this->children.push_back(new CNode(*(toCopy.children.at(i))));
    }
}

CNode::CNode(int childrenCount, CNode *parent, std::string value) {
    this->childrenCount = childrenCount;
    this->parent = parent;
    this->value = value;
}

CNode::~CNode() {
    for (std::vector <CNode*>::iterator it = children.begin(); it != children.end(); ++it) {
        delete (*it);
    }
    children.clear();
}

double CNode::count(std::vector <std::string> *variables, std::vector <double> *values) {
    if (childrenCount == 0) {
        if (isVariable(value)) {
            return getVarValue(variables,values);
        } //if (isVariable(value))
        else
            return stod(value);
    }//if (childrenCount == 0)
    else {
        if (value == "+") {
            return children.at(0)->count(variables,values) + children.at(1)->count(variables,values);
        }
        else if (value == "-") {
            return children.at(0)->count(variables,values) - children.at(1)->count(variables,values);
        }
        else if (value == "*") {
            return children.at(0)->count(variables,values) * children.at(1)->count(variables,values);
        }
        else if (value == "/") {
            return children.at(0)->count(variables,values) / children.at(1)->count(variables,values);
        }
        else if (value == "sin") {
            return sin(children.at(0)->count(variables,values));
        }
        else if (value == "cos") {
            return cos(children.at(0)->count(variables,values));
        }
        else
            std::cout << OPERATIONS_ERROR <<value<<"\n";
    }//childrenCount != 0
}

double CNode::getVarValue(std::vector <std::string> *variables, std::vector <double> *values) {
    int size = variables->size();
    for (int i = 0; i < size; i++)
        if (value == variables->at(i))
            return values->at(i);
    return -1;
}

bool CNode::isVariable(std::string value){
    if(!isOnlyDouble(value.c_str()))
        return true;
    return false;
}

bool CNode::isOnlyDouble(const char* str){
    char* endptr = 0;
    strtod(str, &endptr);

    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

