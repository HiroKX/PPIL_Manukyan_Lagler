//
// Created by Samvel on 01/02/2022.
//

#include "h/Formes/Forme.h"

const Vecteur2D Forme::getVecteur() const {
    return vecteur;
}

void Forme::setVecteur(const Vecteur2D &vecteur) {
    Forme::vecteur = vecteur;
}

const string &Forme::getCouleur() const {
    return couleur;
}

void Forme::setCouleur(const string &couleur) {
    Forme::couleur = couleur;
}
