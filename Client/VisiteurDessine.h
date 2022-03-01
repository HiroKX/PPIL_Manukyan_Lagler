//
// Created by rlagl on 01/03/2022.
//

#ifndef CLIENT_VISITEURDESSINE_H
#define CLIENT_VISITEURDESSINE_H


#include "VisiteurAbstrait.h"
#include "ClientWin.h"

class VisiteurDessine: public VisiteurAbstrait {
    ClientWin c;
public:
    VisiteurDessine(const ClientWin &c);
    void visit(const Cercle *c) override;
    void visit(const Polygone *p) override;
    void visit(const Triangle *t) override;
    void visit(const GroupeForme *g) override;
    void visit(const Segment *s) override;
};


#endif //CLIENT_VISITEURDESSINE_H
