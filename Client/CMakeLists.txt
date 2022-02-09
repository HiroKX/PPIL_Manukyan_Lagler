cmake_minimum_required(VERSION 3.19.2)
project(Client)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Client
        Forme.cpp
        Client.cpp
        Erreur.cpp
        main.cpp)
