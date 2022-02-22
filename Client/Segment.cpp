//
// Created by Samvel on 02/02/2022.
//

#include "Segment.h"
#include "Matrice2x2.h"

Segment::Segment(const char *v1, const char *v2, const string &couleur) : Forme(v1, couleur), vecteur2(v2) {}

const Vecteur2D &Segment::getVecteur2() const {
    return vecteur2;
}

void Segment::setVecteur2(const Vecteur2D &point2) {
    Segment::vecteur2 = point2;
}

string Segment::toString() const {
    return "Segment-" + getVecteur().toString() + "-" + getVecteur2().toString() + "-" + getCouleur();
}

ostream &operator<<(ostream &os, const Segment &segment) {
    return os << segment.toString();
}

void Segment::translation(const Vecteur2D& v) {
    setVecteur(getVecteur() + v);
    setVecteur2(getVecteur2() + v);
}

void Segment::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    setVecteur(m * (getVecteur() - v) + v);
    setVecteur2(m * (getVecteur2() - v) + v);
}

void Segment::homotetie(const double k, const Vecteur2D &v) {
    setVecteur(k * (getVecteur() - v) + v);
    setVecteur2(k * (getVecteur2() - v) + v);
}

Vecteur2D Segment::getCentre() {
    double c_x = (getVecteur().x + getVecteur2().x) / 2;
    double c_y = (getVecteur().y + getVecteur2().y) / 2;
    return Vecteur2D(c_x, c_y);
}


