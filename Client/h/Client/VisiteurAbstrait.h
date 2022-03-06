//
// Created by rlagl on 01/03/2022.
//

#ifndef CLIENT_VISITEURABSTRAIT_H
#define CLIENT_VISITEURABSTRAIT_H


#include "h/Formes/Cercle.h"
#include "h/Formes/Polygone.h"
#include "h/Formes/Triangle.h"
#include "h/Formes/GroupeForme.h"
#include "h/Formes/Segment.h"

class VisiteurAbstrait {
    public:
        virtual void visit(const Cercle *c) =0;
        virtual void visit(const Polygone *p) =0;
        virtual void visit(const Triangle *t) =0;
        virtual void visit(const GroupeForme *g) =0;
        virtual void visit(const Segment *s) =0;
};


#endif //CLIENT_VISITEURABSTRAIT_H
