//
// Created by pelluro on 01/05/19.
//

#ifndef MONOME_H
#define MONOME_H
#include <string>
using namespace std;

class Monome {

public:
    float coeff;
    int degree;

    Monome(string s);

    void print(void);
//	~Monome( void );
};


#endif
