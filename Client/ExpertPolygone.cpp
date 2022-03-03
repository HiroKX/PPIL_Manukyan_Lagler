//
// Created by Samvel on 18/02/2022.
//

#include "ExpertPolygone.h"
#include "Polygone.h"

Forme *ExpertPolygone::retrouverForme(string s) {
    vector<string> c = split(s, '-');
    if(c.at(0) == "Polygone"){
        vector<Vecteur2D> v;
        return new Polygone(c.at(1).c_str(), v, c.at(3).c_str());
    }
    return nullptr;
}

ExpertPolygone::ExpertPolygone(ExpertForme *suivant) : ExpertForme(suivant) {}