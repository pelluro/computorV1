//
// Created by pelluro on 01/05/19.
//

#ifndef POLYNOME_H
#define POLYNOME_H

#include "Monome.h"
#include <string>
using namespace std;

class Polynome {

public:
    Monome * tabMonomes = nullptr;

    Polynome(string str);

    int getMaxDegree ( void );
    void refactor ( void );
    float getDiscriminant ( void );
    float* getRacines ( void );

private:
    char* addPlusBeforeMinus(char* str);
    int countMinus(char * str);
    Monome* parseString(char* str);
};


#endif //COMPUTOR1_POLYNOME_H
