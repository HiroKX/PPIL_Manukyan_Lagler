//
// Created by Samvel on 18/02/2022.
//

#include "h/Expert/ExpertTriangle.h"
#include "h/Formes/Triangle.h"

Forme *ExpertTriangle::retrouverForme(string s) {
    vector<string> c = split(s, '_');
    if (c.size() == 5 && c.at(0) == "Triangle") {
        return new Triangle(c.at(1).c_str(), c.at(2).c_str(), c.at(3).c_str(), c.at(4));
    }
    return nullptr;
}

ExpertTriangle::ExpertTriangle(ExpertForme *suivant) : ExpertForme(suivant) {}