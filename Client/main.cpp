
#include "Erreur.h"     // ma petite classe d'erreur personnelle
#include "ClientWin.h"


using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//
// Created by Robin Lagler on 25/01/2022.
//

#define L 200
int main(){
    /*cin.clear();
    Client c;
    c.lancerClient();
    char requete[L];
    c.receiveServeur();
    c.shutClient();*/

        ClientWin cw;
        cw.lancerClient();
        cw.sendServeur();
        while(true){
            cw.receiveServeur();
            cw.sendServeur();
        }
        //cw.receiveServeur();

        return 0;
}

