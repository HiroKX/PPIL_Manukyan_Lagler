//
// Created by Samvel on 02/02/2022.
//
#include <algorithm>
#include "h/Formes/Polygone.h"
#include "h/Formes/Triangle.h"
#include "h/Autres/Matrice2x2.h"
#include "h/Client/VisiteurAbstrait.h"

void Polygone::addVecteur(const Vecteur2D &vecteur){
    this->vecteurs.push_back(vecteur);
}

string Polygone::toString() const {
    string s = "Polygone";
    for(Vecteur2D v : this->vecteurs){
        s += "_" + v.toString();
    }
    //s += "_" + vecteur.toString();
    s += "_" + string(getCouleur());
    return s;
}

void Polygone::translation(const Vecteur2D& v) {
    vector<Vecteur2D> vec;
    for(Vecteur2D u : this->vecteurs){
        vec.push_back(u+v);
    }
    vecteurs = vec;
}

void Polygone::rotation(const double rot, const Vecteur2D& v) {
    Matrice2x2 m(rot);
    vector<Vecteur2D> vec;
    for(Vecteur2D u : this->vecteurs){
        vec.push_back(m * (u - v) + v);
    }
    vecteurs = vec;
}

void Polygone::homotetie(const double k, const Vecteur2D &v) {
    vector<Vecteur2D> vec;
    for(Vecteur2D u : this->vecteurs){
        vec.push_back(k * (u - v) + v);
    }
    vecteurs = vec;
}

Vecteur2D Polygone::getCentre() {
    double c_x = getVecteur().x;
    double c_y = getVecteur().y;
    for(Vecteur2D u : this->vecteurs){
        c_x += u.x;
        c_y += u.y;
    }
    c_x = c_x / this->vecteurs.size();
    c_y = c_y / this->vecteurs.size();
    return Vecteur2D(c_x, c_y);
}

Polygone *Polygone::clone() {
    return new Polygone(*this);
}

double Polygone::aire() {
    double aire = 0;
    for (int i = 0; i < this->vecteurs.size() - 2; i++) {
        Triangle t(vecteurs.at(0), vecteurs.at(i+1), vecteurs.at(i+2));
        aire += t.aire();
    }
    return aire;
}

void Polygone::draw(VisiteurAbstrait *vis) const{
    vis->visit(this);
}

Forme *Polygone::transform(const TransformationAffine &tf) const {
    /*cout << this->toString();*/
    vector<Vecteur2D> v;
    /*cout<< "\n";*/
    for(Vecteur2D vec : vecteurs){
        v.push_back(tf.transAffine(vec));
        /*cout << tf.transAffine(vec).toString();
        cout<< "\n";*/
    }
    /*cout << tf.transAffine(vecteur).toString();*/
    Polygone* p = new Polygone(v, couleur);
    return p;
}

double Polygone::getHighestX() const {
    double m = vecteur.x;
    for(Vecteur2D v : vecteurs){
        m = max(m,v.x);
    }
    return m;
}

double Polygone::getHighestY() const {
    double m = vecteur.y;
    for(Vecteur2D v : vecteurs){
        m = max(m,v.y);
    }
    return m;
}

double Polygone::getLowestX() const {
    double m = vecteur.x;
    for(Vecteur2D v : vecteurs){
        m = min(m,v.x);
    }
    return m;
}

double Polygone::getLowestY() const {
    double m = vecteur.y;
    for(Vecteur2D v : vecteurs){
        m = min(m,v.y);
    }
    return m;
}

