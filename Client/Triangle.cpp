//
// Created by Samvel on 02/02/2022.
//

#include <algorithm>

#include "Triangle.h"
#include "Matrice2x2.h"
#include "VisiteurAbstrait.h"

Triangle::Triangle(const char *v1, const char *v2, const char *v3, const char *couleur) : Forme(v1, couleur), vecteur2(v2), vecteur3(v3) {}

const Vecteur2D &Triangle::getVecteur2() const {
    return vecteur2;
}

void Triangle::setVecteur2(const Vecteur2D &vecteur2) {
    Triangle::vecteur2 = vecteur2;
}

const Vecteur2D &Triangle::getVecteur3() const {
    return vecteur3;
}

void Triangle::setVecteur3(const Vecteur2D &vecteur3) {
    Triangle::vecteur3 = vecteur3;
}

string Triangle::toString() const {
    return "Triangle_" + getVecteur().toString() + "_" + getVecteur2().toString() +"_" + getVecteur3().toString() + "_" + getCouleur();
}

ostream &operator<<(ostream &os, const Triangle &triangle) {
    return os << triangle.toString();
}

void Triangle::translation(const Vecteur2D& v) {
    setVecteur(getVecteur() + v);
    setVecteur2(getVecteur2() + v);
    setVecteur3(getVecteur3() + v);
}

void Triangle::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    setVecteur(m * (getVecteur() - v) + v);
    setVecteur2(m * (getVecteur2() - v) + v);
    setVecteur3(m * (getVecteur3() - v) + v);
}

void Triangle::homotetie(const double k, const Vecteur2D &v) {
    setVecteur(k * (getVecteur() - v) + v);
    setVecteur2(k * (getVecteur2() - v) + v);
    setVecteur3(k * (getVecteur3() - v) + v);
}

Vecteur2D Triangle::getCentre() {
    double c_x = (getVecteur().x + getVecteur2().x + getVecteur3().x) / 3;
    double c_y = (getVecteur().y + getVecteur2().y + getVecteur3().y) / 3;
    return Vecteur2D(c_x , c_y);
}

void Triangle::draw(VisiteurAbstrait *vis) const {
    vis->visit(this);
}

Forme *Triangle::transform(const TransformationAffine &tf) const {
    cout << tf.transAffine(vecteur3).toString();
    return new Triangle(tf.transAffine(vecteur),tf.transAffine(vecteur2),tf.transAffine(vecteur3),couleur);
}

double Triangle::getHighestY() const {
    return max(vecteur.y,max(vecteur3.y,vecteur2.y));
}

double Triangle::getLowestX() const {
    return min(vecteur.x,min(vecteur3.x,vecteur2.x));
}

double Triangle::getLowestY() const {
    return min(vecteur.y,min(vecteur3.y,vecteur2.y));
}

double Triangle::getHighestX() const {
    return min(vecteur.y,min(vecteur3.y,vecteur2.y));
}