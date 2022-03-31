#include "h/Autres/Erreur.h"     // ma petite classe d'erreur personnelle
#include "h/Autres/Matrice2x2.h"
#include "h/Client/ClientWin.h"
#include "h/Formes/Polygone.h"
#include "h/Client/VisiteurDessine.h"

using namespace std;
#include <corecrt_math_defines.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    ClientWin c;
    Fenetre f("awt", 800, 800);
    c.lancerClient();
    c.ouvreFenetre(f);
    VisiteurDessine vis(&c);
    Vecteur2D A(1,0), B(4, -2), C(4,2),D(7,0),E(11,-1),F(15,-1),G(15,1),H(11,1),I(17,0);
    vector<Vecteur2D> v = {E,F,G,H};
    Triangle t1(A,B,C,"green");
    Cercle c1(D,2,"yellow");
    Polygone r1(v,"blue");
    Cercle c2(I,1,"yellow");
    GroupeForme G1("red");
    G1.addForme(&t1);
    G1.addForme(&c1);
    G1.addForme(&r1);
    G1.addForme(&c2);
    G1.translation(Vecteur2D(-4,0));
    G1.rotation(M_PI/4,G1.getCentre());
    cout <<"Calcul de l'aire : "<<  G1.aire() << endl;
    G1.draw(&vis);
    c.dessine();
    vis.sauvegarder(&G1);
    vis.enregistrer("majoliefigure2.txt");
    vector<Forme*> lformes = vis.charger("majoliefigure2.txt");
    Forme *G2 = lformes.at(0);









    /**
    Polygone p(v,"red");
    Triangle t(D, E, F, "red");
    Fenetre f("awt", 500, 500);
    Cercle cer(A, 20, "red");
    GroupeForme g("red");
    GroupeForme g2("blue");
    Segment s(G,H,"blue");

    g2.addForme(&p);
    g.addForme(&g2);
    g.addForme(&t);

    //g.draw(&vis);
    /**
    vis.sauvegarder(&t);
    vis.sauvegarder(&p);
    vis.sauvegarder(&g);
    vis.enregistrer("monfichier.txt");

    vector<Forme*> lformes = vis.charger("monfichier.txt");

    //p.draw(&vis);
    s.draw(&vis);
    cer.draw(&vis);
    g.draw(&vis);
    g2.draw(&vis);
     */
    c.dessine();
    c.shutClient();
    return 0;
}