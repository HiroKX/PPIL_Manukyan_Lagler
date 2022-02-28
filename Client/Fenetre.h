//
// Created by rlagl on 28/02/2022.
//

#ifndef CLIENT_FENETRE_H
#define CLIENT_FENETRE_H

#include <string>

using namespace std;

class Fenetre {
    int width, height;
    string type;
public:
    inline Fenetre(string t="awt", int w=600,int h=600) {
        width = w;
        type=t;
        height=h;
    }


    inline string toString(){
        return type+"-"+to_string(width)+"-"+to_string(height);
    }
};


#endif //CLIENT_FENETRE_H
