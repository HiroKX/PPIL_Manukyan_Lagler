//
// Created by Samvel on 17/02/2022.
//

#ifndef CLIENT_EXPERTFORME_H
#define CLIENT_EXPERTFORME_H

#include <vector>
#include "h/Expert/Expert.h"

class ExpertForme : public Expert{
    private:
        ExpertForme *suivant;

    public:
        /**
         * Constructor
         * @param suivant ExpertForme
         */
        ExpertForme(ExpertForme *suivant);

        /**
         * Renvoie l'ExpertForme suivant
         * @return ExpertForme
         */
        ExpertForme *getSuivant() const;

        Forme *resoudre(string s) override;

        /**
         * Retrouve la Forme à partir d'un String et la retourne
         * @param s String
         * @return Retourne une Forme
         */
        virtual Forme * retrouverForme(string s) = 0;

        /**
         * Permet de découper un string suivant un délimiteur
         * @param s String
         * @param delimiteur Char : le délimiteur qui sert à découper la chaîne de caractère
         * @return Renvoie un vector de String
         */
        vector<string> split(string s, char delimiteur);
};


#endif //CLIENT_EXPERTFORME_H
