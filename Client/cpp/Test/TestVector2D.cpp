#include <iostream>
#include "h/Formes/Vecteur2D.h"

//
// Created by rlagl on 28/02/2022.
//
using namespace std;

int main(){
    Vecteur2D v1(3,2), v2(-2,3);
    double p;
    p = v1*v2; // p = v1.operator*(v2)
    p = v1.longueur2();// calcul la longueur de v1 élevée au carré
    p = v1.det(v2);
    return 0;
}
