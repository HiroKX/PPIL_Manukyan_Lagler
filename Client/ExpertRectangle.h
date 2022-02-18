//
// Created by Samvel on 18/02/2022.
//

#ifndef CLIENT_EXPERTRECTANGLE_H
#define CLIENT_EXPERTRECTANGLE_H


#include "ExpertForme.h"

class ExpertRectangle : public ExpertForme{
    public:
        Forme * retrouverForme(string s) override;
};


#endif //CLIENT_EXPERTRECTANGLE_H
