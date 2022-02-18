//
// Created by Samvel on 01/02/2022.
//

#include "Cercle.h"

Cercle::Cercle(const char* vecteur, double rayon) : Forme(vecteur), rayon(rayon) {}

double Cercle::getRayon() const {
    return rayon;
}

void Cercle::setRayon(double rayon) {
    Cercle::rayon = rayon;
}

string Cercle::toString() const {
    return "Cercle " + getVecteur().toString() + " : r=" + to_string(getRayon());
}

void Cercle::translation(Vecteur2D v) {
    //TODO
}

ostream &operator<<(ostream &os, const Cercle &cercle) {
    return os << cercle.toString();
}