//
// Created by Samvel on 05/03/2022.
//

#include "h/Formes/Vecteur2D.h"
#include "h/Formes/Segment.h"

int main(){
    Vecteur2D v1(2, 5), v2(5, 6), v3(7, 1);
    Segment s(v1, v2, "red");

    Segment s2("( 5, 6)", "( 9, 10)", "blue");

    cout << "s = " << s << endl;
    cout << "s2 = " << s2 << endl;
    return 0;
}