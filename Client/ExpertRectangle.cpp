//
// Created by Samvel on 18/02/2022.
//

#include "ExpertRectangle.h"
#include "Rectangle.h"

Forme *ExpertRectangle::retrouverForme(string s) {
    vector<string> c = split(s, '-');
    if(c.size() == 4 && c.at(0) == "Rectangle"){
        return new Rectangle(c.at(1).c_str(), stod(c.at(2)), stod(c.at(3)));
    }
    return nullptr;
}
