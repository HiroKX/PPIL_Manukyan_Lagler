//
// Created by Samvel on 18/02/2022.
//

#include "ExpertPolygone.h"
#include "Polygone.h"

Forme *ExpertPolygone::retrouverForme(string s) {
    vector<string> c = split(s, '_');
    if(c.at(0) == "Polygone"){
        vector<Vecteur2D> v;
        for (int i = 1; i <= c.size() - 2 ; i++) {
            v.push_back(Vecteur2D(c.at(i).c_str()));
        }
        return new Polygone(v, c.at(3));
    }
    return nullptr;
}

ExpertPolygone::ExpertPolygone(ExpertForme *suivant) : ExpertForme(suivant) {}