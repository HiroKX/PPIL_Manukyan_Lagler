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
    double x, y;


    inline explicit Vecteur2D::Vecteur2D(const double & x=0, const double & y=0): x(x),y(y){}

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
    inline Vecteur2D(const char * s);
    /**
     * Addition d'un Vecteur2D par un autre Vecteur2D
     * @param u Vecteur2D
     * @return Retourne un Vecteur2D
     */
    inline const Vecteur2D operator + (const Vecteur2D & u) const;

    /**
     * Multiplication d'un Vecteur2D par un double
     * @param a double
     * @return Retourne un Vecteur2D
     */
    inline const Vecteur2D operator * (const double & a) const;

    /**
     * Multiplication d'un Vecteur2D par un autre Vecteur2D
     * @param v Vecteur2D
     * @return Retroune un Vecteur2D
     */
    inline double operator * (const Vecteur2D &v) const { return this->x * v.x + this->y * v.y; }

    /**
     * Calcule le Vecteur2D au carré
     * @return Retourne un double
     */
    inline double longueur2() const { return (*this) * (*this); }

    /**
     * Calcule la racine Carré d'un Vecteur2D²
     * @return Retourne un double
     */
    inline double longueur() const { return sqrt(longueur2()); }

    /**
     * Caclule le Determinant de deux Vecteur2D
     * @param v1 Vecteur2D
     * @param v2 Vecteur2D
     * @return
     */
    inline static double det(const Vecteur2D &v1, const Vecteur2D &v2) { return v1.x * v2.y - v1.y * v2.x; }

    /**
     * Calcule le Determinant de deux Vecteur2d
     * @param v Vecteur2D
     * @return
     */
    inline double det(const Vecteur2D &v) const { return this->x * v.y - this->y * v.x; } // aire signée du parallélogramme engendré par (*this) et v

/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
    inline const Vecteur2D operator - () const;

    /**
     * Operator string
     * @return
     */
    operator string() const;

    /**
     * Renvoie le Vecteur2D sous la forme d'un string
     * @return Retourne un string
     */
    inline string toString() const;

    void setVecteur(const Vecteur2D vecteur2D);
};

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) {
    return u*a;
}

//------------ implémentation des fonctions inline ----------------------

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
//TODO : produit scalaire et determinant et longueur

inline Vecteur2D::operator string() const//
{
    ostringstream os;
    os << this->toString();
    return os.str();
}

inline string Vecteur2D::toString() const{
    return "( " + to_string(x) + ", " + to_string(y) + ")";
}

inline void Vecteur2D::setVecteur(const Vecteur2D vecteur2D) {
    this->x = vecteur2D.x;
    this->y = vecteur2D.y;
}

inline ostream &operator<<(ostream & os, const Vecteur2D & u)//
{
    return os << u.toString();
}

#endif //PPIL_MANUKYAN_LAGLER_VECTEUR2D_H