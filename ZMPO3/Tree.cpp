//
// Created by Admin on 2017-12-22.
//
#include "Tree.h"

//CTree class
const int CTree::REQUIRED_ARGUMENTS[] = { 2,2,2,2,1,1 };
const std::string CTree::OPERATIONS[] = { "+", "-", "/", "*", "sin", "cos" };

CTree::CTree() {
    root = NULL;
}

CTree::CTree(std::string futureNodes[], int length) {
    for (int i=0; i < length; i++)
        nodesValues.push_back(futureNodes[i]);
    buildTree();
}

CTree::CTree(CTree &toCopy) {
    for (int i = 0; i < toCopy.variables.size(); i++) {
        this->variables.push_back(toCopy.variables.at(i));
    }

    for (int i = 0; i < toCopy.nodesValues.size(); i++) {
        this->nodesValues.push_back(toCopy.nodesValues.at(i));
    }

    buildTree();
}

CTree::~CTree() {
    if(variables.size()>0)
        variables.clear();
    if(values.size()>0)
        values.clear();
    if(nodesValues.size()>0)
        nodesValues.clear();
    if(root!=NULL)
        delete root;
}

int CTree::getChildrenCount(std::string operation) {
    int result = 0;
    int length = 6;
    for (int i = 0; i < length; i++) {
        if (OPERATIONS[i] == operation)
            return REQUIRED_ARGUMENTS[i];
    }
    return result;
}

void CTree::buildTree() {
    root = new CNode(getChildrenCount(nodesValues.at(0)), NULL, nodesValues.at(0));
    buildTreeSupport(1, root);
    int alarm=stabilize(root);
    if(alarm>0) {
        std::cout <<ARGUMENTS_ERROR;
        print();
    }
    nodesValues.clear();
    generateNodesValues(root);
}

void CTree::buildTreeSupport(int position, CNode *node) {
    if(node) {
        if (position < (int) nodesValues.size()) {
            if ((int) node->children.size() < node->childrenCount) {
                int childrenCount = getChildrenCount(nodesValues.at(position));
                CNode *support = new CNode(childrenCount, node, nodesValues.at(position));
                node->children.push_back(support);
                buildTreeSupport(++position, support);
            } else {
                buildTreeSupport(position, node->parent);
            }
        }
    }
}

int CTree::stabilize(CNode *node){
    int indicator=0;
    if(node) {
        for (int i = 0; i < node->children.size(); i++)
            indicator+=stabilize(node->children.at(i));

        while ((int) node->children.size() < node->childrenCount) {
            node->children.push_back(new CNode(0, node, "1"));
            indicator++;
        }

        //sprawdza najawność zmiennych i dodaje je do vectora zmiennych
        if(node->childrenCount==0) {
            if (!node->isOnlyDouble(node->value.c_str())) {
                bool result = false;
                for (std::string s:variables) {
                    if (s == node->value)
                        result = true;
                }
                if (!result)
                    variables.push_back(node->value);
            }
        }
    }
    return indicator;
}

void CTree::treeToString(CNode *node) {
    int size = node->children.size();
    if(node)
        std::cout << node->value<<" ";
        for (int i = 0; i < size; i++)
            treeToString(node->children.at(i));
}

void CTree::print(){
    treeToString(root);
    std::cout<<"\n";
}

std::string CTree::count(std::vector <double> val){
    if(val.size()!=variables.size())
        return VALUES_ERROR;
    values=val;
    return std::to_string(root->count(&variables,&values))+"\n";
}

void CTree::vars(){
    std::cout<<"Zmienne: \n";
    if(variables.size()>0) {
        for (std::string s:variables)
            std::cout << s << "\n";
    }
    else
        std::cout<<"Brak zmiennych. \n";
}

CTree& CTree::operator +(CTree other){
    CTree *result;
    result=new CTree(*this);
    CNode *support;
    support=result->root;
    if(root->children.size()!=0) {
        while (support->children.at(0)->childrenCount != 0)
            support = support->children.at(0);
        other.root->parent=support;
        support->children.at(0)=other.root;
    }
    else{
        result->root=other.root;
    }
    result->nodesValues.clear();
    result->generateNodesValues(result->root);

    //linking lists of variables
    bool find=false;
    for(std::string s: other.variables){

        for(int i=0; find==false && i < result->variables.size();i++){
            if(result->variables.at(i)==s)
                find=true;
        }
        if(find==false)
            result->variables.push_back(s);
        find=false;
    }

    return *result;
}

void CTree::operator= (CTree &other) {
    this->root = new CNode(*(other.root));
    for (int i = 0; i < other.variables.size(); i++) {
        this->variables.push_back(other.variables.at(i));
    }

    for (int i = 0; i < other.nodesValues.size(); i++) {
        this->nodesValues.push_back(other.nodesValues.at(i));
    }
}

void CTree::generateNodesValues(CNode *node) {
    int size = node->children.size();
    if(node)
        nodesValues.push_back(node->value);
    for (int i = 0; i < size; i++)
        generateNodesValues(node->children.at(i));
}
//CTree end




