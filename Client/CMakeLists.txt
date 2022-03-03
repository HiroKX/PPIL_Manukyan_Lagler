cmake_minimum_required(VERSION 3.19.2)
project(Client)

link_libraries(ws2_32 wsock32)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Client
        main.cpp
        Erreur.cpp Erreur.h
        ClientWin.cpp ClientWin.h
        Matrice2x2.cpp Matrice2x2.h
        Vecteur2D.cpp Vecteur2D.h
        Forme.cpp Forme.h
        Cercle.cpp Cercle.h
        Polygone.cpp Polygone.h
        Triangle.cpp Triangle.h
        Segment.cpp Segment.h
        Expert.cpp Expert.h
        ExpertForme.cpp ExpertForme.h
        ExpertCercle.cpp ExpertCercle.h
        ExpertPolygone.cpp ExpertPolygone.cpp
        ExpertTriangle.cpp ExpertTriangle.h
        ExpertSegment.cpp ExpertSegment.h
        GroupeForme.cpp GroupeForme.h Fenetre.h VisiteurAbstrait.h VisiteurDessine.cpp VisiteurDessine.h ExpertGroupe.cpp ExpertGroupe.h)