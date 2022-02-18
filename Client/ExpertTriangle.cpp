//
// Created by Samvel on 18/02/2022.
//

#include "ExpertTriangle.h"
#include "Triangle.h"

Forme *ExpertTriangle::retrouverForme(string s) {
    vector<string> c = split(s, '-');
    if(c.size() == 4 && c.at(0) == "Triangle"){
        return new Triangle(c.at(1).c_str(), c.at(2).c_str(), c.at(3).c_str());
    }
    return nullptr;
}
