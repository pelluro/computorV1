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

	void chooseCase(std::string const & case_name, Monome & target);


private:
	void caseOne(Monome & target);
	void caseTwo(Monome & target);
	void caseTwoBis(Monome & target);
	void caseThree(Monome & target);

	void caseForAll(Monome & target);
	ComplexNumber _coeff;
	int _degree;
};


#endif
