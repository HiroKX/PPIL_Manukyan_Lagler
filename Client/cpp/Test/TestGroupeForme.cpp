//
// Created by Samvel on 05/03/2022.
//

#include "h/Formes/Vecteur2D.h"
#include "h/Formes/Polygone.h"
#include "h/Formes/Segment.h"
#include "h/Formes/Triangle.h"
#include "h/Formes/Cercle.h"
#include "h/Formes/GroupeForme.h"

int main(){
    Vecteur2D vc1(2, 5);
    Cercle c(vc1, 50, "red");
    Cercle c2("( 5, 6)", 90, "blue");

    Vecteur2D vt1(2, 5), vt2(5, 6), vt3(7, 1);
    Triangle t(vt1, vt2, vt3, "red");
    Triangle t2("( 5, 6)", "( 8, 9)", "( 9, 10)", "blue");

    Vecteur2D vs1(2, 5), vs2(5, 6), vs3(7, 1);
    Segment s(vs1, vs2, "red");
    Segment s2("( 5, 6)", "( 9, 10)", "blue");

    Vecteur2D vp1(2, 5), vp2(50, 9.5), vp3(8, 54.5), vp4(4.22, 5.6);
    vector<Vecteur2D> v = {vp1, vp2, vp3, vp4};
    Polygone p(v, "green");

    GroupeForme g("red");
    g.addForme(&c);
    g.addForme(&t);
    g.addForme(&s);
    g.addForme(&p);
    g.addForme(&c2);
    g.addForme(&t2);
    g.addForme(&s2);

    cout << "g = " << g << endl;
    return 0;
}