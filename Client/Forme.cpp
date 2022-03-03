//
// Created by Samvel on 01/02/2022.
//

#include "Forme.h"
#include <fstream>

Forme::Forme(const char *couleur) : couleur(couleur) {}

Forme::Forme(const char * s, const char *couleur) : vecteur(s), couleur(couleur) {}

const Vecteur2D Forme::getVecteur() const {
    return vecteur;
}

void Forme::setVecteur(const Vecteur2D &vecteur) {
    Forme::vecteur = vecteur;
}

char * Forme::getCouleur() const {
    return const_cast<char *>(couleur);
}

void Forme::setCouleur(char* couleur) {
    Forme::couleur = couleur;
}

Forme::Forme(const Vecteur2D &v1, const char *couleur) {
    vecteur =v1;
    this->couleur = couleur;
}


