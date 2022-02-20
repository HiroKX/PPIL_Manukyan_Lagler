//
// Created by Samvel on 19/02/2022.
//

#include <cmath>
#include "Matrice2x2.h"

Matrice2x2::Matrice2x2(double (*val)[2]) {
    this->val[0][0] = val[0][1];
    this->val[0][1] = val[0][1];
    this->val[1][0] = val[1][0];
    this->val[1][1] = val[1][1];
}

Matrice2x2::Matrice2x2(double ang) {
    this->val[0][0] = cos(ang);
    this->val[0][1] = -sin(ang);
    this->val[1][0] = sin(ang);
    this->val[1][1] = cos(ang);
}

/*const Matrice2x2 Matrice2x2::operator*(const Vecteur2D& v) const {
    double val[2][2];
    val[0][0] = this->val[0][0] * v.x;
    val[0][1] = this->val[0][1] * v.y;
    val[1][0] = this->val[1][0] * v.x;
    val[1][1] = this->val[1][1] * v.y;
    return Matrice2x2(val);
}*/

ostream &operator<<(ostream &os, const Matrice2x2 &m) {
    os << "M:[" << m.val[0][0] << " " << m.val[0][1] << "]" << endl;
    os << "  [" << m.val[1][0] << " " << m.val[1][1] << "]" << endl;
    return os;
}

