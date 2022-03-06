//
// Created by Samvel on 05/03/2022.
//

#include "h/Formes/Vecteur2D.h"
#include "h/Formes/Polygone.h"

int main(){
    Vecteur2D v1(2, 5), v2(50, 9.5), v3(8, 54.5), v4(4.22, 5.6);
    vector<Vecteur2D> v = {v1, v2, v3, v4};

    Polygone p(v, "green");

    cout << "p = " << p << endl;
    return 0;
}