cmake_minimum_required(VERSION 3.21)
project(Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Client
        Client.cpp
        Client.h
        Erreur.h
        main.cpp)
