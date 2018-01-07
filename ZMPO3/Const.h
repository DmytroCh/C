//
// Created by Admin on 2017-12-26.
//

#ifndef ZMPO3_CONST_H
#define ZMPO3_CONST_H

#include <iostream>
#include <string>

static const std::string ARGUMENTS_ERROR="Niezgodnosc argumentow, drzewo zostalo automatycznie naprawione i ma postac: ";
static const std::string VALUES_ERROR="Niepoprawna liczba argumentow \n";
static const std::string OPERATIONS_ERROR="Nieprawidlowa operacja: ";
static const std::string SYMBOL_ERROR="Niedopuszczalne symbole:\n";
static const std::string OPTIONS="Legenda:\n"
                                 "enter <formula> - wpisz formule w notacji polskiej\n"
                                 "vars - wypisac wszystkie zmienne\n"
                                 "print - wypisac aktualna formule\n"
                                 "comp <var1> <var2>...<varn> nadanie wartosci zmiennym i obliczenie formuly\n"
                                 "join <formula> dodanie do aktualnego drzewa kolejnej formuly\n"
                                 "del - usuwanie drzewa\n";

static const std::string COMMAND="Wpisz polecenie: ";

static const std::string ENTER="enter";
static const std::string VARS="vars";
static const std::string PRINT="print";
static const std::string COMP="comp";
static const std::string JOIN="join";
static const std::string DEL="del";

static const std::string TREE_NOT_CREATED="Drzewo nie zostalo jeszcze utworzone. Utworz drzewo zeby wykonac dane polecenie\n";
static const std::string TREE_DELETED="Drzewo zostalo usuniete.\n";
static const std::string COMMAND_ERROR="Niepoprawne polecenie sprobuj jeszcze raz.\n";


#endif //ZMPO3_CONST_H
