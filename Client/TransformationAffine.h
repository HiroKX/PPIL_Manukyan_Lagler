//
// Created by rlagl on 03/03/2022.
//

#ifndef CLIENT_TRANSFORMATIONAFFINE_H
#define CLIENT_TRANSFORMATIONAFFINE_H


#include "Vecteur2D.h"

class TransformationAffine {



public:
    double lambda1;
    double lambda2;
    double a;
    double b;
    TransformationAffine(Vecteur2D& P1, Vecteur2D P2, Vecteur2D& P1e, Vecteur2D& P2e);
    Vecteur2D transAffine(Vecteur2D p) const;
};


#endif //CLIENT_TRANSFORMATIONAFFINE_H
