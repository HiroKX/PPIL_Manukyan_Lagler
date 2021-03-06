//
// Created by Samvel on 18/02/2022.
//

#include "h/Expert/ExpertSegment.h"
#include "h/Formes/Segment.h"

Forme *ExpertSegment::retrouverForme(string s) {
    vector<string> c = split(s, '_');
    if(c.size() == 4 && c.at(0) == "Segment"){
        return new Segment(c.at(1).c_str(), c.at(2).c_str(), c.at(3));
    }
    return nullptr;
}
ExpertSegment::ExpertSegment(ExpertForme *suivant) : ExpertForme(suivant) {}