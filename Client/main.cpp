#include "Client.h"

//
// Created by Robin Lagler on 25/01/2022.
//

#define L 200
int main(){
    cin.clear();
    Client c;
    c.lancerClient();
    char requete[L];
    cout << "Tapez la chaîne à mettre en majuscule ou tapez \"quitter\" : ";
    cin >> requete;
    c.sendServeur(requete);
    c.shutClient();
}

