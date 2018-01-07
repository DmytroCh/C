//
// Created by Admin on 2017-12-22.
//

#ifndef ZMPO3_TREE_H
#define ZMPO3_TREE_H


#include <iostream>
#include <vector>
#include "CNode.h"
#include "Const.h"


class CTree{
public:

    friend class Manager;
    CTree();
    CTree(std::string futureNodes[], int length);
    CTree(CTree &toCopy);
    ~CTree();
    void print();
    std::string count(std::vector <double> val);
    void vars();
    CTree& operator+(CTree other);
    void operator=(CTree &other);

private:

    static const int REQUIRED_ARGUMENTS[];
    static const std::string OPERATIONS[];
    std::vector <std::string> nodesValues;
    CNode * root;
    std::vector <std::string> variables;
    std::vector <double> values;


    int getChildrenCount(std::string operation);//this function return number of arguments depends on operation
    void buildTree();//this function build expression tree
    void buildTreeSupport(int position, CNode *node);
    int stabilize(CNode *node);//add 1 to the holes. "position" show index in nodesValues
    void treeToString(CNode *node);
    void generateNodesValues(CNode *node);//used in operator +, to recover nodes vector
};

#endif //ZMPO3_TREE_H
