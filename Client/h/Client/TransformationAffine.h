//
// Created by rlagl on 03/03/2022.
//

#ifndef CLIENT_TRANSFORMATIONAFFINE_H
#define CLIENT_TRANSFORMATIONAFFINE_H


#include "h/Formes/Vecteur2D.h"

class TransformationAffine {



public:
    /**
     * Données nécessaire lors d'une transformation affine.
     */
    double lambda1;
    double lambda2;
    double a;
    double b;
    /**
     * constructeur
     * @param P1 Coordonnées P1 du monde
     * @param P2 Coordonnées P2 du monde
     * @param P1e Coordonées P1e de l'écran
     * @param P2e Coordonnées P2e de l'écran
     */
    TransformationAffine(Vecteur2D& P1, Vecteur2D P2, Vecteur2D& P1e, Vecteur2D& P2e);
    /**
     * Effectue unetransformation affine sur un vecteur pour qu'il soit adapté à la taille de l'écran
     * @param p Vecteur avec coord monde
     * @return  Vecteur avec coord écran
     */
    Vecteur2D transAffine(Vecteur2D p) const;
};


#endif //CLIENT_TRANSFORMATIONAFFINE_H
