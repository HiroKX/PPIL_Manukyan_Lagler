//
// Created by Samvel on 01/02/2022.
//

#include "Forme.h"

Forme::Forme(const string &nom, const Point2D &point) : nom(nom), point(point) {}

const string &Forme::getNom() const {
    return nom;
}

void Forme::setNom(const string &nom) {
    Forme::nom = nom;
}

const Point2D &Forme::getPoint() const {
    return point;
}

void Forme::setPoint(const Point2D &point) {
    Forme::point = point;
}