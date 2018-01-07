//
// Created by Admin on 2017-12-28.
//

#include "Interface.h"

Manager *man;

void start(){
    man=new Manager();
    printLegend();
    getCommand();
}

void printLegend(){
    std::cout<<OPTIONS;
}

void getCommand(){
    bool exit=false;
    std::string phrase = "";
    std::string command = "";
    std::string arguments = "";
    std::string support="";
    do {
        std::cout << COMMAND;
        getline(std::cin,phrase);
        for (char& c:phrase) {
            if(command=="") {
                if(c==' ')
                    command=support;
                else
                    support += c;
            }
            else
                arguments += c;
        }
        if(command=="")
            command=support;

        if(command == ENTER && arguments != "") {
            if (!man->isEmpty())
                man->deleteTree();
            man->enter(arguments);
        }//command==ENTER
        else if(command==VARS){
            man->vars();
        }//command==VARS
        else if(command==PRINT){
            if (man->isEmpty())
                std::cout << TREE_NOT_CREATED;
            else {
                man->print();
            }
        }//command==PRINT
        else if(command == COMP){
            if (man->isEmpty())
                std::cout << TREE_NOT_CREATED;
            else {
                man->comp(arguments);
            }
        }//command==COMP
        else if(command==JOIN && arguments!=""){
            if (man->isEmpty())
                std::cout << TREE_NOT_CREATED;
            else {
                man->joint(arguments);
            }
        }//command==JOIN
        else if(command==DEL){
            if (man->isEmpty())
                std::cout << TREE_NOT_CREATED;
            else {
                man->deleteTree();
                std::cout << TREE_DELETED;
            }
        }//command==DEL
        else{
            std::cout<<COMMAND_ERROR;
        }

        phrase = "";
        command = "";
        arguments = "";
        support="";
    }while(!exit);
}