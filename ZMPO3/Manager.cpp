//
// Created by Admin on 2017-12-28.
//
#include "Manager.h"


void Manager::enter(std::string data){
    std::vector <std::string> result;
    std::string word;
    std::string forPrint="";
    for(char c : data) {
        if(c == ' ') {
            if(word!="") {
                result.push_back(word);
                word = "";
            }
        }//c == ' '
        else{
            if(isCommonOperation(c)||isNumber(c)||isLathin(c))
                word+=c;
            else{
                forPrint+=c;
            }
        }//c != ' '
    }
    if(word!="")
        result.push_back(word);

    std::string forTree[result.size()];
    for(int i=0;i<result.size();i++){
        forTree[i]=result.at(i);
    }

    tree=new CTree(forTree,result.size());

    if(forPrint!="")
        std::cout<<SYMBOL_ERROR<<forPrint<<"\n";
}

void Manager::joint(std::string data){
    CTree *result, *toAdd;
    std::vector <std::string> res;
    std::string word;
    std::string forPrint="";

    result=new CTree();
    for(char c : data) {
        if(c == ' ') {
            if(word!="") {
                res.push_back(word);
                word = "";
            }
        }//c == ' '
        else{
            if(isCommonOperation(c)||isNumber(c)||isLathin(c))
                word+=c;
            else{
                forPrint+=c;
            }
        }//c != ' '
    }
    if(word!="")
        res.push_back(word);

    std::string forTree[res.size()];
    for(int i=0;i<res.size();i++){
        forTree[i]=res.at(i);
    }
    toAdd=new CTree(forTree,res.size());

    *result=*tree + *toAdd;
    delete tree;
    tree=result;
}

void Manager::print() {
    tree->print();
}

void Manager::vars() {
    tree->vars();
}

void Manager::comp (std::string data){
    std::vector <double> result;
    std::string word;
    std::string forPrint="";
    for(char c : data) {
        if(c == ' ') {
            if(isDouble(word))
                result.push_back(std::stod(word));
            word="";
        }//c == ' '
        else{
            if(isNumber(c))
                word+=c;
            else{
                forPrint+=c;
            }
        }//c != ' '
    }
    if(word!="")
        if(isDouble(word))
            result.push_back(std::stod(word));

    if(result.size()==tree->variables.size()) {
        std::cout<<tree->count(result);
        if(forPrint!="")
            std::cout<<SYMBOL_ERROR<<forPrint<<"\n";
    }
    else{
        std::cout<<VALUES_ERROR;
    }
}

void Manager::deleteTree() {
    delete tree;
    tree=NULL;
}

bool Manager::isEmpty() {
    if(tree==NULL)
        return true;
    else
        return false;
}

bool Manager::isLathin(char letter) {
    for (char a = 'A'; a <= 'Z'; a++)
        if (letter == a)
            return true;

    for (char a = 'a'; a <= 'z'; a++)
        if (letter == a)
            return true;
    return false;
}

bool Manager::isNumber(char letter) {
    for (int i = 0; i<=9; i++) {
        if (i == (int)(letter-'0'))
            return true;
    }
    if(letter=='.')
        return true;
    return false;
}

bool Manager::isCommonOperation(char letter) {
    const char basicOperations[] = {'+', '-', '/', '*'};
    for (char c:basicOperations) {
        if (c == letter)
            return true;
    }
    return false;
}

bool Manager::isDouble(const std::string& s){
    char* end = 0;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && val != HUGE_VAL;
}