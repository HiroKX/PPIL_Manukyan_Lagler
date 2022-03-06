//
// Created by Samvel on 05/03/2022.
//

#include "h/Formes/Triangle.h"

int main(){
    Vecteur2D v1(2, 5), v2(5, 6), v3(7, 1);
    Triangle t(v1, v2, v3, "red");

    Triangle t2("( 5, 6)", "( 8, 9)", "( 9, 10)", "blue");

    cout << "t = " << t << endl;
    cout << "t2 = " << t2 << endl;
    return 0;
}