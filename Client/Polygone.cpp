//
// Created by Samvel on 02/02/2022.
//

#include "Polygone.h"
#include "Matrice2x2.h"
#include "VisiteurAbstrait.h"
Polygone::Polygone(const char *s, const vector<Vecteur2D> &vecteurs, const string &couleur) : Forme(s, couleur), vecteurs(vecteurs) {
    this->vecteurs.push_back(getVecteur());
}

void Polygone::addVecteur(const Vecteur2D &vecteur){
    this->vecteurs.push_back(vecteur);
}

string Polygone::toString() const {
    string s = "polygon";
    for(Vecteur2D v : this->vecteurs){
        s += "-" + v.toString();
    }
    s += "-" + this->getCouleur();
    return s;
}

ostream &operator<<(ostream &os, const Polygone &rectangle) {
    return os << rectangle.toString();
}

void Polygone::translation(const Vecteur2D& v) {
    for(Vecteur2D u : this->vecteurs){
        u = u + v;
    }
}

void Polygone::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);

    for(Vecteur2D u : this->vecteurs){
        u = m * (u - v) + v;
    }
}

void Polygone::homotetie(const double k, const Vecteur2D &v) {
    for(Vecteur2D u : this->vecteurs){
        u = k * (u - v) + v;
    }
}

Vecteur2D Polygone::getCentre() {
    double c_x = getVecteur().x;
    double c_y = getVecteur().y;
    for(Vecteur2D u : this->vecteurs){
        c_x += u.x;
        c_y += u.y;
    }
    c_x = c_x / this->vecteurs.size();
    c_y = c_y / this->vecteurs.size();
    return Vecteur2D(c_x, c_y);
}

void Polygone::draw(VisiteurAbstrait *vis) const{
    vis->visit(this);
}

