//
// Created by Samvel on 17/02/2022.
//

#ifndef CLIENT_EXPERT_H
#define CLIENT_EXPERT_H

#include <string>
#include "Forme.h"

class Expert {
    public:
        virtual Forme *resoudre(string s) = 0;
};


#endif //CLIENT_EXPERT_H
