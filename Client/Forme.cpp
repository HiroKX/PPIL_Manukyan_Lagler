//
// Created by Samvel on 01/02/2022.
//

#include "Forme.h"

Forme::Forme(const string &couleur) : couleur(couleur) {}

Forme::Forme(const char * s, const string &couleur) : vecteur(s), couleur(couleur) {}

const Vecteur2D &Forme::getVecteur() const {
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