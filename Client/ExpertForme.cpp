//
// Created by Samvel on 17/02/2022.
//

#include "ExpertForme.h"

ExpertForme::ExpertForme(ExpertForme *suivant) : suivant(suivant) {}

ExpertForme *ExpertForme::getSuivant() const {
    return suivant;
}

Forme * ExpertForme::resoudre(string s) {
    Forme *f = retrouverForme(s);

    if (f != nullptr){
        return f;
    }
    else if (getSuivant() != nullptr){
        return getSuivant()->resoudre(s);
    }
    else{
        return f;
    }
}

vector<string> ExpertForme::split(string s, char delimiteur) {
    vector<string> vs{};
    int pos = 0;
    while(s.find(delimiteur, pos) != string::npos){
        vs.push_back(s.substr(pos, s.find(delimiteur, pos) - pos));
        pos = s.find(delimiteur, pos) + 1;
    }
    vs.push_back(s.substr(pos, s.length() - pos));
    return vs;
}