//
// Created by Samvel on 02/02/2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(const string &nom, const Point2D &point, double hauteur, double largeur)
        : Forme(nom, point), hauteur(hauteur), largeur(largeur) {}

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
    return getNom() + " " + getPoint().toString() + " : hauteur=" + to_string(getHauteur()) + ", largeur=" + to_string(getLargeur());
}

ostream &operator<<(ostream &os, const Rectangle &rectangle) {
    return os << rectangle.toString();
}