//
// Created by Samvel on 02/02/2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(const string &nom, const char *s, double hauteur, double largeur) : Forme(nom, s), hauteur(hauteur), largeur(largeur) {}

double Rectangle::getHauteur() const {
    return hauteur;
}

void Rectangle::setHauteur(double hauteur) {
    this->hauteur = hauteur;
}

double Rectangle::getLargeur() const {
    return largeur;
}

void Rectangle::setLargeur(double largeur) {
    this->largeur = largeur;
}

string Rectangle::toString() const {
    return getNom() + " " + getVecteur().toString() + " : hauteur=" + to_string(getHauteur()) + ", largeur=" + to_string(getLargeur());
}

ostream &operator<<(ostream &os, const Rectangle &rectangle) {
    return os << rectangle.toString();
}
