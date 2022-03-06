#include "h/Autres/Erreur.h"     // ma petite classe d'erreur personnelle
#include "h/Autres/Matrice2x2.h"
#include "h/Client/ClientWin.h"
#include "h/Formes/Polygone.h"
#include "h/Client/VisiteurDessine.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    Vecteur2D A(-3,5), B(-3.2, 100), C(5,-6),D(10,10),E(15,15),F(20,15),G(18,18),H(2,-12);
    vector<Vecteur2D> v = {A,B,E,C};
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

    ClientWin c;
    c.lancerClient();
    c.ouvreFenetre(f);

    VisiteurDessine vis(&c);
    //g.draw(&vis);
    /**
    vis.sauvegarder(&t);
    vis.sauvegarder(&p);
    vis.sauvegarder(&g);
    vis.enregistrer("monfichier.txt");

    vector<Forme*> lformes = vis.charger("monfichier.txt");
    */
    //p.draw(&vis);
    s.draw(&vis);
    cer.draw(&vis);
    g.draw(&vis);
    g2.draw(&vis);
    c.dessine();
    c.shutClient();
    return 0;
}