cmake_minimum_required(VERSION 3.9)
project(ZMPO3)

set(CMAKE_CXX_STANDARD 11)

add_executable(ZMPO3 main.cpp CNode.h Tree.h CNode.cpp Tree.cpp Const.h Manager.cpp Manager.h Interface.h Interface.cpp)

