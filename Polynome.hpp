//
// Created by pelluro on 01/05/19.
//

#ifndef POLYNOME_H
#define POLYNOME_H

#include "Monome.hpp"
#include <string>
#include <vector>

using namespace std;

class Polynome {

public:
    vector<Monome> tabMonomes;
    int degreeMax;

    Polynome(string str);


    void refactor ( void );
	ComplexNumber getDiscriminant ( void );
    float getRacineSimple (void);
    vector<ComplexNumber> getRacines ( void );

	~Polynome( void );

private:
    int getMaxDegree ( void );
};


#endif //COMPUTOR1_POLYNOME_H
