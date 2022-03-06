//
// Created by Robin Lagler on 13/01/2022.
//
using namespace std;

#include <string>
#include <iostream>

#ifndef VISITOR_ERREUR_H
#define VISITOR_ERREUR_H




class Erreur
{
public:
    const static int LONGUEURMESSAGE = 100;
    char message[1+LONGUEURMESSAGE];
    Erreur();
    Erreur(const char * messageErreur);

    operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);

#endif



