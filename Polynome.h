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
    vector<float> getRacines ( void );

    string addPlusBeforeMinus(string str);
    int countMinus(string str);
//	~Polynome( void );

};


#endif //COMPUTOR1_POLYNOME_H
