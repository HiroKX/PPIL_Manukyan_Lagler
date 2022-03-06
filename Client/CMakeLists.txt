cmake_minimum_required(VERSION 3.19.2)
project(Client)

link_libraries(ws2_32 wsock32)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Client
        cpp/main.cpp
        cpp/Autres/Erreur.cpp h/Autres/Erreur.h
        cpp/Client/ClientWin.cpp h/Client/ClientWin.h
        cpp/Autres/Matrice2x2.cpp h/Autres/Matrice2x2.h
        cpp/Formes/Vecteur2D.cpp h/Formes/Vecteur2D.h
        cpp/Formes/Forme.cpp h/Formes/Forme.h
        cpp/Formes/Cercle.cpp h/Formes/Cercle.h
        cpp/Formes/Polygone.cpp h/Formes/Polygone.h
        cpp/Formes/Triangle.cpp h/Formes/Triangle.h
        cpp/Formes/Segment.cpp h/Formes/Segment.h
        cpp/Expert/Expert.cpp h/Expert/Expert.h
        cpp/Expert/ExpertForme.cpp h/Expert/ExpertForme.h
        cpp/Expert/ExpertCercle.cpp h/Expert/ExpertCercle.h
        cpp/Expert/ExpertPolygone.cpp cpp/Expert/ExpertPolygone.cpp
        cpp/Expert/ExpertTriangle.cpp h/Expert/ExpertTriangle.h
        cpp/Expert/ExpertSegment.cpp h/Expert/ExpertSegment.h
        cpp/Formes/GroupeForme.cpp h/Formes/GroupeForme.h
        h/Client/Fenetre.h
        h/Client/VisiteurAbstrait.h
        cpp/Client/VisiteurDessine.cpp h/Client/VisiteurDessine.h
        cpp/Expert/ExpertGroupe.cpp h/Expert/ExpertGroupe.h
        cpp/Client/TransformationAffine.cpp h/Client/TransformationAffine.h

        #[[TestTriangle.cpp TestSegment.cpp TestCercle.cpp TestPolygone.cpp TestGroupeForme.cpp]] )