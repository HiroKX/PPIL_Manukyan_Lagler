//
// Created by Samvel on 05/02/2022.
//

#ifndef PPIL_MANUKYAN_LAGLER_VECTEUR2D_H
#define PPIL_MANUKYAN_LAGLER_VECTEUR2D_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
    return u + -v;
}

class Vecteur2D
{
public:
    double x,y;

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

    this->x = stoi(x);
    this->y = stoi(y);
}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}

inline const Vecteur2D operator +(const Vecteur2D & u, const Vecteur2D & v) {
    return Vecteur2D( u.x + v.x, u.y + v.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}

inline const Vecteur2D operator -(const Vecteur2D & u, const Vecteur2D & v) {
    return Vecteur2D( u.x - v.x, u.y - v.y);
}

Vecteur2D::operator string() const
{
    ostringstream os;
    os << "( " << x <<", " << y << ")";
    return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
    os << (string) u;
    return os;
}

#endif //PPIL_MANUKYAN_LAGLER_VECTEUR2D_H