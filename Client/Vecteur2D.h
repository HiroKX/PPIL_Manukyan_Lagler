//
// Created by Samvel on 05/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_VECTEUR2D_H
#define PPIL_MANUKYAN_LAGLER_VECTEUR2D_H

#include <string>
#include <iostream>
#include <sstream>
#include "Matrice.h"

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
    return u + -v;
}

class Vecteur2D
{
public:
    double x, y;

    inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
    inline Vecteur2D(const char * s);
    inline const Vecteur2D operator + (const Vecteur2D & u) const;
    inline const Vecteur2D operator * (const double & a) const;

/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
    inline const Vecteur2D operator - () const;

    operator string() const;
    inline string toString() const;

    const Vecteur2D rotation(const Vecteur2D& V, const double rad, const Vecteur2D& invariant);
    const Vecteur2D homotetie(const Vecteur2D& V, const double k, const Vecteur2D& invariant);
    const Vecteur2D translation(const Vecteur2D& V, const Vecteur2D& u);

};

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) {
    return u*a;
}

//------------ implémentation des fonctions inline ----------------------

inline  Vecteur2D::Vecteur2D(const double & x, const double & y): x(x),y(y){}

inline Vecteur2D::Vecteur2D(const char * s){
    string str = string(s);
    string x = str.substr(2, str.find(',') - 2);
    string y = str.substr(str.find(',') + 2, str.find(')') - str.find(',') - 2);

    this->x = stod(x);
    this->y = stod(y);
}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}

inline Vecteur2D::operator string() const//
{
    ostringstream os;
    os << "( " << x <<", " << y << ")";
    return os.str();
}

inline string Vecteur2D::toString() const{
    return "( " + to_string(x) + ", " + to_string(y) + ")";
}

const Vecteur2D Vecteur2D::rotation(const Vecteur2D& V, const double rad, const Vecteur2D& invariant)
{
    /*Matrice m(2, 2);
    return Vecteur2D(m * (V - invariant) + invariant);*/
    return nullptr;
}

const Vecteur2D Vecteur2D::homotetie(const Vecteur2D& V, const double k, const Vecteur2D& invariant)
{
    return Vecteur2D(k * V + (1 - k) * invariant);
}

const Vecteur2D Vecteur2D::translation(const Vecteur2D& v, const Vecteur2D& u)
{
    return Vecteur2D(v + u);
}

inline ostream &operator<<(ostream & os, const Vecteur2D & u)//
{
    return os << u.toString();
}

#endif //PPIL_MANUKYAN_LAGLER_VECTEUR2D_H
