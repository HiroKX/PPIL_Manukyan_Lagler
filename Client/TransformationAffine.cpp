//
// Created by rlagl on 03/03/2022.
//

#include "TransformationAffine.h"

TransformationAffine::TransformationAffine(Vecteur2D &P1, Vecteur2D P2, Vecteur2D &P1e, Vecteur2D &P2e) {
    double tempX = abs(P2e.x-P1e.x)/abs(P2.x-P2.x);
    double tempY = abs(P2e.y-P1e.y)/abs(P2.y-P1.y);
    double lambda = min(tempX,tempY);
    int epsilon1;
    if(P2.x-P2.x == P2e.x-P1e.x){
        epsilon1=1;
    }
    else{
        epsilon1=-1;
    }

    int epsilon2;
    if(P2.y-P2.y == P2e.y-P1e.y){
        epsilon2=1;
    }
    else{
        epsilon2=-1;
    }

    lambda1 = epsilon1*lambda;
    lambda2 = epsilon2*lambda;
    double Cxe = (P2e.x+P1e.x)/2;
    double Cye = (P2e.y+P1e.y)/2;
    double Cx = (P2.x+P1.x)/2;
    double Cy = (P2.y+P1.y)/2;
    a = Cxe - lambda1*Cx;
    b = Cye - lambda2*Cy;
}

Vecteur2D TransformationAffine::transAffine(Vecteur2D p) const {
    return Vecteur2D(lambda1*p.x+a, lambda2*p.y+b);
}
