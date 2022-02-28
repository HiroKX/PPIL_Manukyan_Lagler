#include "Erreur.h"     // ma petite classe d'erreur personnelle
#include "Matrice2x2.h"
#include "ClientWin.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Fenetre.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    Vecteur2D A(200,300), B(250, 250), C(400,400),D(100,100),E(400,400);
    vector<Vecteur2D> v = {A,B,E};
    Polygone p("( 180, 100)",v,"blue");
    Triangle t(A, B, C, "red");
    ClientWin c;
    c.lancerClient();
    char requete[L];
    Fenetre f("awt");
    cout << f.toString();
    c.sendServeur(f.toString());
    cin >> requete;
    c.dessine(t);
    cin >> requete;
    c.sendServeur(p.toString());
    cin >> requete;
    c.sendServeur("dessine");
    cin >> requete;
    c.shutClient();
    /**
   Vecteur2D A(-0.5,-3.8), B(-5.6, 0.3), C(11.5,0.4);

   Triangle t(A,B,C,"red");
   Cercle c(Vector2D(6.3,-2.5),1.3,"blue");
   Cercle c2(Vector2D(100,25),10,"blue");
   Groupe g();
   g->ajouter(t);
   g->ajouter(c2);
   g->ajouter(c);
   Fenetre f("AWT", 600,300);
   f->dessine(g);
    */
    // il lui faut dessiner g sur f

    /*string s = "Cerlce-10-50-60";
    Cercle c("( 10, 50)", 50);
    cout << c.toString() << endl;*/

    /*Matrice2x2 m(5);
    cout << m << endl;
    Vecteur2D v(1, 10);
    Matrice2x2 a = m * v;
    cout << a << endl;*/

        /*ClientWin cw;
        cw.lancerClient();
        cw.sendServeur();
        while(true){
            cw.receiveServeur();
            cw.sendServeur();
        }*/
        //cw.receiveServeur();

        return 0;
}

