//
// Created by Samvel on 01/02/2022.
//

#include "Cercle.h"
#include "Matrice2x2.h"

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

ostream &operator<<(ostream &os, const Cercle &cercle) {
    return os << cercle.toString();
}

void Cercle::translation(const Vecteur2D& v) {
    setVecteur(getVecteur() + v);
}

void Cercle::rotation(double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    m = m * ((getVecteur() - v) + v);//TODO
}
