//
// Created by Samvel on 02/02/2022.
//

#include "Segment.h"

Segment::Segment(const char * vecteur, const char * vecteur2) : Forme(vecteur), vecteur2(vecteur2) {}

const Vecteur2D &Segment::getVecteur2() const {
    return vecteur2;
}

void Segment::setVecteur2(const Vecteur2D &point2) {
    Segment::vecteur2 = point2;
}

string Segment::toString() const {
    return "Segment : " + getVecteur().toString() + " : " + getVecteur2().toString();
}

ostream &operator<<(ostream &os, const Segment &segment) {
    return os << segment.toString();
}

void Segment::translation(Vecteur2D v) {
    setVecteur(getVecteur() + v);
    setVecteur2(getVecteur2() + v);
}
