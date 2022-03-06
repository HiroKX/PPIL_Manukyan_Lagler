//
// Created by Samvel on 05/03/2022.
//

#include "Vecteur2D.h"
#include "Cercle.h"

int main(){
    Vecteur2D v1(2, 5);
    Cercle c(v1, 50, "red");

    Cercle c2("( 5, 6)", 90, "blue");

    cout << "c = " << c << endl;
    cout << "c2 = " << c2 << endl;
    return 0;
}