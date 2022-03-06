//
// Created by Samvel on 18/02/2022.
//

#ifndef CLIENT_EXPERTPOLYGONE_H
#define CLIENT_EXPERTPOLYGONE_H


#include "ExpertForme.h"

class ExpertPolygone : public ExpertForme{
    public:
        /**
         * Constuctor
         * @param suivant ExpertForme
         */
        ExpertPolygone(ExpertForme *suivant);

        Forme * retrouverForme(string s) override;
};


#endif //CLIENT_EXPERTPOLYGONE_H
