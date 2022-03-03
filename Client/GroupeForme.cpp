//
// Created by Samvel on 20/02/2022.
//

#include "GroupeForme.h"
#include "VisiteurAbstrait.h"
const vector<Forme*> &GroupeForme::getGroupe() const {
    return groupe;
}

void GroupeForme::setGroupe(const vector<Forme*> &gro) {
    GroupeForme::groupe = gro;
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

GroupeForme::GroupeForme(const char *couleur) : Forme(couleur) {}
