//
// Created by Samvel on 19/02/2022.
//

#ifndef CLIENT_MATRICE2X2_H
#define CLIENT_MATRICE2X2_H

#include <ostream>
#include "Vecteur2D.h"

class Matrice2x2 {
    private:
        double val[2][2];

    public:
        Matrice2x2(double (*val)[2]);

        Matrice2x2(double ang);

        inline const Matrice2x2 operator*(const Vecteur2D& v) const;

        friend ostream &operator<<(ostream &os, const Matrice2x2 &x2);
};

const Matrice2x2 Matrice2x2::operator*(const Vecteur2D& v) const {
    double val[2][2];
    val[0][0] = this->val[0][0] * v.x;
    val[0][1] = this->val[0][1] * v.y;
    val[1][0] = this->val[1][0] * v.x;
    val[1][1] = this->val[1][1] * v.y;
    return Matrice2x2(val);
}

#endif //CLIENT_MATRICE2X2_H
