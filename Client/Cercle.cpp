//
// Created by Samvel on 01/02/2022.
//

#include "Cercle.h"
#include "Matrice2x2.h"
#include "VisiteurAbstrait.h"

#include <corecrt_math_defines.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

double Cercle::getRayon() const {
    return rayon;
}

void Cercle::setRayon(double rayon) {
    Cercle::rayon = rayon;
}

string Cercle::toString() const {
    return "Cercle_" + getVecteur().toString() + "_" + to_string(getRayon()) + "_" + getCouleur();
}

void Cercle::translation(const Vecteur2D& v) {
    setVecteur(getVecteur() + v);
}

void Cercle::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    setVecteur(m * (getVecteur() - v) + v);
}

void Cercle::homotetie(const double k, const Vecteur2D &v) {
    setRayon(k * getRayon());
}

Vecteur2D Cercle::getCentre() {
    return getVecteur();
}

double Cercle::air() {
    return M_PI * getRayon() * getRayon();
}

void Cercle::draw(VisiteurAbstrait *vis) const {
    vis->visit(this);
}

Forme *Cercle::transform(const TransformationAffine &tf) const {
    Cercle* c = new Cercle(tf.transAffine(vecteur), rayon, couleur);
    return c;
}

double Cercle::getHighestX() const {
    return vecteur.x + rayon;
}

double Cercle::getHighestY() const {
    return vecteur.y + rayon;
}

double Cercle::getLowestX() const {
    return vecteur.x - rayon;
}

double Cercle::getLowestY() const {
    return vecteur.y - rayon;
}