//
// Created by Samvel on 01/02/2022.
//

#include "Forme.h"

Forme::Forme() = default;

Forme::Forme(const char * s) : vecteur(s) {}

const Vecteur2D &Forme::getVecteur() const {
    return vecteur;
}

void Forme::setVecteur(const Vecteur2D &vecteur) {
    Forme::vecteur = vecteur;
}


