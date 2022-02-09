//
// Created by Samvel on 01/02/2022.
//

#include "Forme.h"

Forme::Forme(const string &nom, const char * s) : nom(nom), vecteur(s) {}

const string &Forme::getNom() const {
    return nom;
}

void Forme::setNom(const string &nom) {
    Forme::nom = nom;
}

const Vecteur2D &Forme::getVecteur() const {
    return vecteur;
}

void Forme::setVecteur(const Vecteur2D &vecteur) {
    Forme::vecteur = vecteur;
}