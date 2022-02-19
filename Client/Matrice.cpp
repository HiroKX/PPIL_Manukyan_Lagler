//
// Created by Samvel on 19/02/2022.
//

#include "Matrice.h"

Matrice::Matrice(int lig, int col) : lig(lig), col(col) {
    vals = new double[lig * col];
}

Matrice::~Matrice() {
    delete[] vals;
}
