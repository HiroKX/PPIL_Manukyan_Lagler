//
// Created by Samvel on 20/02/2022.
//

#include "GroupeForme.h"
#include "VisiteurAbstrait.h"

GroupeForme::GroupeForme(const char *couleur) : Forme(couleur) {}

const vector<Forme*> &GroupeForme::getGroupe() const {
    return groupe;
}

void GroupeForme::addForme(Forme* f){
    groupe.push_back(f);
}

void GroupeForme::setGroupe(const vector<Forme*> &groupe) {
    GroupeForme::groupe = groupe;
}

void GroupeForme::draw(VisiteurAbstrait *vis) const {
    vis->visit(this);
}

void GroupeForme::homotetie(const double k, const Vecteur2D &v) {

}

void GroupeForme::translation(const Vecteur2D &v) {

}

void GroupeForme::rotation(double rot, const Vecteur2D &v) {

}

Vecteur2D GroupeForme::getCentre() {
    return Vecteur2D();
}

double GroupeForme::getHighestX() const {
    return 0;
}

double GroupeForme::getHighestY() const {
    return 0;
}

double GroupeForme::getLowestX() const {
    return 0;
}

double GroupeForme::getLowestY() const {
    return 0;
}

Forme* GroupeForme::transform(const TransformationAffine& tf) const {
    return nullptr;
}

string GroupeForme::toString() const {
    string s = "Groupe[";
    for(int i = 0; i <= groupe.size() - 1; i++){
        s += groupe.at(i)->toString() + "/";
    }
    s += string(getCouleur()) + "]";
    return s;
}
