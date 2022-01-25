#include "Client.h"

//
// Created by Robin Lagler on 25/01/2022.
//

#define L 200
int main(){
    cin.clear();
    Client c;
    c.lancerClient();
    cout << "oui" << endl;
    c.sendServeur("oui2\r\n");
    //c.shutClient();
}

