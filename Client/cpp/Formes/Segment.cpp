//
// Created by Samvel on 02/02/2022.
//

#include <algorithm>
#include "h/Formes/Segment.h"
#include "h/Autres/Matrice2x2.h"
#include "h/Client/VisiteurAbstrait.h"

const Vecteur2D &Segment::getVecteur2() const {
    return vecteur2;
}

void Segment::setVecteur2(const Vecteur2D &point2) {
    Segment::vecteur2 = point2;
}

string Segment::toString() const {
    return "Segment_" + getVecteur().toString() + "_" + getVecteur2().toString() + "_" + getCouleur();
}

Segment *Segment::clone() {
    return new Segment(*this);
}

void Segment::translation(const Vecteur2D& v) {
    setVecteur(getVecteur() + v);
    setVecteur2(getVecteur2() + v);
}

void Segment::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    setVecteur(m * (getVecteur() - v) + v);
    setVecteur2(m * (getVecteur2() - v) + v);
}

void Segment::homotetie(const double k, const Vecteur2D &v) {
    setVecteur(k * (getVecteur() - v) + v);
    setVecteur2(k * (getVecteur2() - v) + v);
}

Vecteur2D Segment::getCentre() {
    double c_x = (getVecteur().x + getVecteur2().x) / 2;
    double c_y = (getVecteur().y + getVecteur2().y) / 2;
    return Vecteur2D(c_x, c_y);
}

void Segment::draw(VisiteurAbstrait *vis) const {
    vis->visit(this);
}

Forme *Segment::transform(const TransformationAffine &tf) const {
    return new Segment(tf.transAffine(vecteur), tf.transAffine(vecteur2), couleur);
}

double Segment::getHighestX() const {
    return max(vecteur.x, vecteur2.x);
}

double Segment::getHighestY() const {
    return max(vecteur.y, vecteur2.y);
}

double Segment::getLowestX() const {
    return min(vecteur.x, vecteur2.x);
}

double Segment::getLowestY() const {
    return min(vecteur.y, vecteur2.y);
}

