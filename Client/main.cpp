#include "Erreur.h"     // ma petite classe d'erreur personnelle
#include "Matrice2x2.h"
#include "ClientWin.h"

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//

// Created by Robin Lagler on 25/01/2022.
//
#define L 200
int main(){
    cin.clear();
    ClientWin c;
    c.lancerClient();
    char requete[L];
    c.receiveServeur();
    c.shutClient();
    Triangle T = Trangle(point x , point y, etc...);
    client->envoie(t)
    client->dessine()
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

