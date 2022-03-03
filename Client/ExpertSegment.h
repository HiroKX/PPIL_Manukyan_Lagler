//
// Created by Samvel on 18/02/2022.
//

#ifndef CLIENT_EXPERTSEGMENT_H
#define CLIENT_EXPERTSEGMENT_H


#include "ExpertForme.h"

class ExpertSegment : public ExpertForme{
    public:
    ExpertSegment(ExpertForme *suivant);

    Forme * retrouverForme(string s) override;
};


#endif //CLIENT_EXPERTSEGMENT_H

