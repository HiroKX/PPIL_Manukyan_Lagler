//
// Created by Samvel on 02/02/2022.
//

#include "Triangle.h"

Triangle::Triangle(const string &nom, const char* vecteur, const char* vecteur2, const char* vecteur3) : Forme(nom, vecteur), vecteur2(vecteur2), vecteur3(vecteur3) {}

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
    return getNom() + " v1" + getVecteur().toString() + " v2" + getVecteur2().toString() +" v3" + getVecteur3().toString();
}

ostream &operator<<(ostream &os, const Triangle &triangle) {
    return os << triangle.toString();
}
