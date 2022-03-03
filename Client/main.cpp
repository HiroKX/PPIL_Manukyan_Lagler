#include "Erreur.h"     // ma petite classe d'erreur personnelle
#include "Matrice2x2.h"
#include "ClientWin.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Fenetre.h"
#include "VisiteurDessine.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    Vecteur2D A(-10,5), B(-3.2, 400), C(5,-6),D(100,100),E(400,400);
    vector<Vecteur2D> v = {A,B};
    Polygone p("( 3.2, 1.6)",v,"red");
    Triangle t(A, B, C, "red");
    Fenetre f("awt",1500,1000);
    GroupeForme g("red");
    GroupeForme g2("blue");
    g2.addForme(&p);
    g.addForme(&g2);
    g.addForme(&t);

    ClientWin c;
    c.lancerClient();
    c.ouvreFenetre(f);
    VisiteurDessine vis(&c);
    g.draw(&vis);
    c.dessine();
    //vis.sauvegarder( &t);
    // vis.sauvegarder(&t);
    //vis.enregistrer("monfichier.txt");

    while(true){

    }

        return 0;
}

