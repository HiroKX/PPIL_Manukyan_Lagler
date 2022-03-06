//
// Created by Samvel on 17/02/2022.
//

#ifndef CLIENT_EXPERT_H
#define CLIENT_EXPERT_H

#include <string>
#include "h/Formes/Forme.h"

class Expert {
    public:
        /**
         * Résout un String passé en paramètre et retourne sa Forme
         * @param s String
         * @return Retourne une Forme
         */
        virtual Forme *resoudre(string s) = 0;
};


#endif //CLIENT_EXPERT_H
