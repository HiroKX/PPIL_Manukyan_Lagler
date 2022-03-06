#include "Erreur.h"     // ma petite classe d'erreur personnelle
#include "Matrice2x2.h"
#include "ClientWin.h"
#include "Polygone.h"
#include "VisiteurDessine.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    Vecteur2D A(-10,5), B(-3.2, 400), C(5,-6),D(100,100),E(400,400), vc1(2, 5);
    vector<Vecteur2D> v = {A,B};
    Polygone p(v,"red");
    Triangle t(A, B, C, "red");
    Fenetre f("awt",1500,1000);
    Cercle cer(vc1, 50, "red");
    GroupeForme g("red");
    GroupeForme g2("blue");
    g.addForme(&t);
    g2.addForme(&p);
    g2.addForme(&t);
    g.addForme(&g2);
    g.addForme(&t);
    g.addForme(&cer);

    ClientWin c;
    c.lancerClient();
    c.ouvreFenetre(f);

    VisiteurDessine vis(&c);
    //g.draw(&vis);
    vis.sauvegarder(&t);
    vis.sauvegarder(&t);
    vis.sauvegarder(&p);
    vis.sauvegarder(&g);
    vis.enregistrer("monfichier.txt");

    vector<Forme*> lformes = vis.charger("monfichier.txt");
   /* for(Forme* a : lformes){
        a->draw(&vis);
    }*/
    t.draw(&vis);
    p.draw(&vis);
    cer.draw(&vis);
    //c.sendServeur("dessin");
    c.dessine();

    Vecteur2D Z(30,200), Y(90, 200), X(45, 50);
    Triangle t5(Z, Y, X, "red");
    cout << "air t5 : " << t5.air() << endl;

    Vecteur2D P1(175,135), P2(270, 200), P3(200,220), P4(130,180);
    vector<Vecteur2D> v5 = {P1, P2, P3, P4};
    Polygone p5(v5, "red");
    cout << "air p5 : " << p5.air() << endl;
    cout << "test" << endl;

    int entier;
    cin >> entier;
    c.shutClient();
    return 0;
}