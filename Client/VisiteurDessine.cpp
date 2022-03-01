//
// Created by rlagl on 01/03/2022.
//

#include "VisiteurDessine.h"
class Forme;
void VisiteurDessine::visit(const Cercle *ce) {
    c.sendServeur(ce->toString());
}

void VisiteurDessine::visit(const Polygone *p) {
    c.sendServeur(p->toString());
}

void VisiteurDessine::visit(const Triangle *t) {
    c.sendServeur(t->toString());
}

void VisiteurDessine::visit(const GroupeForme *g) {
    for(auto &Forme: g->getGroupe()){
        Forme->setCouleur(g->getCouleur());
        cout << Forme->toString();
        Forme->draw(this);
    }
}

void VisiteurDessine::visit(const Segment *s) {
    c.sendServeur(s->toString());
}

VisiteurDessine::VisiteurDessine(const ClientWin &c) : c(c) {}
