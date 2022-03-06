//
// Created by Samvel on 19/02/2022.
//

#ifndef CLIENT_MATRICE2X2_H
#define CLIENT_MATRICE2X2_H

#include <ostream>
#include "h/Formes/Vecteur2D.h"
// a voir, modifier en tableau de Vecteur2D
class Matrice2x2 {
    private:
        double val[2][2];

    public:
        /**
         * Constuctor
         * @param val un Tableau de double
         */
        Matrice2x2(double (*val)[2]);

        /**
         * Constructor
         * @param ang double
         */
        Matrice2x2(double ang);

        /**
         * Multiplication d'une Matrice2x2 par un Vecteur2D
         * @param v Vecteur2D
         * @return Vecteur2D
         */
        inline const Vecteur2D operator*(const Vecteur2D& v) const;

        friend ostream &operator<<(ostream &os, const Matrice2x2 &x2);
};

const Vecteur2D Matrice2x2::operator*(const Vecteur2D& v) const { // à réecrire en utilisant le produit scalaire
    double u_x = this->val[0][0] * v.x + this->val[0][1] * v.y;
    double u_y = this->val[1][0] * v.x + this->val[1][1] * v.y;
    return Vecteur2D(u_x, u_y);
}

#endif //CLIENT_MATRICE2X2_H
