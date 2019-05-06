//
// Created by pelluro on 01/05/19.
//

#ifndef POLYNOME_H
#define POLYNOME_H

#include "Monome.h"
#include <string>
#include <vector>

using namespace std;

class Polynome {

public:
    vector<Monome> tabMonomes;

    Polynome(string str);

    int getMaxDegree ( void );
    void refactor ( void );
    float getDiscriminant ( void );
    float* getRacines ( void );

private:
    string addPlusBeforeMinus(string str);
    int countMinus(string str);

};


#endif //COMPUTOR1_POLYNOME_H
