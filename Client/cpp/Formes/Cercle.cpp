//
// Created by Samvel on 01/02/2022.
//

#include "h/Formes/Cercle.h"
#include "h/Autres/Matrice2x2.h"
#include "h/Client/VisiteurAbstrait.h"
#include "h/Autres/Erreur.h"

#include <corecrt_math_defines.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

double Cercle::getRayon() const {
    return rayon;
}

void Cercle::setRayon(double rayon) {
    if(rayon < 0)
        Erreur("Le rayon est inferieur a 0");

    Cercle::rayon = rayon;
}

Cercle *Cercle::clone() {
    return new Cercle(*this);
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

double Cercle::aire() {
    return M_PI * getRayon() * getRayon();
}

void Cercle::draw(VisiteurAbstrait *vis) const {
    vis->visit(this);
}

Forme *Cercle::transform(const TransformationAffine &tf) const {
    Vecteur2D vec = Vecteur2D(vecteur.x+rayon,vecteur.y);
    Vecteur2D centre = tf.transAffine(vec);
    Cercle* c = new Cercle(tf.transAffine(vecteur), centre.x- tf.transAffine(vecteur).x, couleur);
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


