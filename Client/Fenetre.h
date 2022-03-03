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

    int getWidth() const{
        return width;
    }

    void setWidth(int w){
        width = w;
    }

    int getHeight() const{
        return height;
    }

    void setHeight(int h){
        height = h;
    }
};


#endif //CLIENT_FENETRE_H
