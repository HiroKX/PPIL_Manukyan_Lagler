//
// Created by Samvel on 17/02/2022.
//
#include "h/Formes/Cercle.h"
#include "h/Expert/ExpertCercle.h"

Forme *ExpertCercle::retrouverForme(string s) {
    vector<string> c = split(s, '_');
    if(c.size() == 4 && c.at(0) == "Cercle"){
        return new Cercle(c.at(1).c_str(), stod(c.at(2)), c.at(3));
    }
    return nullptr;
}

ExpertCercle::ExpertCercle(ExpertForme *ex): ExpertForme(ex) {}
