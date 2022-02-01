//
// Created by Samvel on 01/02/2022.
//

#include "Cercle.h"

Cercle::Cercle(const string &nom, const Point2D &point, double rayon) : Forme(nom, point), rayon(rayon) {}

double Cercle::getRayon() const {
    return rayon;
}

void Cercle::setRayon(double rayon) {
    Cercle::rayon = rayon;
}

string Cercle::toString() const {
    return getNom() + " " + getPoint().toString() + " : r=" + to_string(getRayon());
}

ostream &operator<<(ostream &os, const Cercle &cercle) {
    return os << cercle.toString();
}