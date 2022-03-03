//
// Created by rlagl on 02/03/2022.
//

#include "ExpertGroupe.h"
#include "GroupeForme.h"
#include "ExpertCercle.h"
#include "ExpertPolygone.h"
#include "ExpertTriangle.h"
#include "ExpertSegment.h"

ExpertGroupe::ExpertGroupe(ExpertForme *suivant) : ExpertForme(suivant) {}

Forme *ExpertGroupe::retrouverForme(string s) {
    vector<string> c = split(s, ';');
    if(c.at(0)=="Groupe"){
        auto* g = new GroupeForme(c.at(1).c_str());
        ExpertForme* expCercle, * expPolygon, * expTriangle, * expSegment, * expGroupe;
        expCercle = new ExpertCercle(nullptr);
        expPolygon = new ExpertPolygone(expCercle);
        expTriangle = new ExpertTriangle(expPolygon);
        expSegment = new ExpertSegment(expTriangle);
        expGroupe = new ExpertGroupe(expSegment);
        int j = atoi(c.at(2).c_str());
        for(int i = 2; i < j+2 ;i++){
            Forme* f = expGroupe->resoudre(c.at(i));
            f->setCouleur(g->getCouleur());
            g->addForme(f);
        }
        return g;
    }
    return nullptr;
}
