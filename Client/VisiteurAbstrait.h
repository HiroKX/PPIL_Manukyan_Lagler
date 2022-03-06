//
// Created by rlagl on 01/03/2022.
//

#ifndef CLIENT_VISITEURABSTRAIT_H
#define CLIENT_VISITEURABSTRAIT_H


#include "Cercle.h"
#include "Polygone.h"
#include "Triangle.h"
#include "GroupeForme.h"
#include "Segment.h"

class VisiteurAbstrait {
    public:
        virtual void visit(const Cercle *c) =0;
        virtual void visit(const Polygone *p) =0;
        virtual void visit(const Triangle *t) =0;
        virtual void visit(const GroupeForme *g) =0;
        virtual void visit(const Segment *s) =0;
};


#endif //CLIENT_VISITEURABSTRAIT_H
