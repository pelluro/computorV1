//degree
// Created by pelluro on 01/05/19.
//

#ifndef MONOME_H
#define MONOME_H
#include <string>
#include "ComplexNumber.hpp"

using namespace std;

class Monome {

public:

    Monome(string s);
    Monome(ComplexNumber coeff, int degree);

    void print(void);
	~Monome( void );

	ComplexNumber getCoeff ( void );
	int getDegree ( void );
	void setCoeff ( ComplexNumber );
	void setDegree ( int );


private:
	ComplexNumber _coeff;
	int _degree;
};


#endif
