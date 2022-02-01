#include "Client.h"

#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"     // ma petite classe d'erreur personnelle

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

//
// Created by Robin Lagler on 25/01/2022.
//

#define L 200
int main(){
    cin.clear();
    Client c;
    c.lancerClient();
    char requete[L];
    c.receiveServeur();
    c.shutClient();
}

