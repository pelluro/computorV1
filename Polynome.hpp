//
// Created by pelluro on 01/05/19.
//

#ifndef POLYNOME_H
#define POLYNOME_H

#include "Monome.hpp"
#include <exception>
#include <string>
#include <vector>

using namespace std;

class Polynome {

public:

	class DegreeTooHighException : public std::exception {
	public:
		DegreeTooHighException();
		DegreeTooHighException(DegreeTooHighException const &);
		~DegreeTooHighException();
	private:
		DegreeTooHighException &	operator =(DegreeTooHighException const &);
	};
    vector<Monome> tabMonomes;
    int degreeMax;

    Polynome(string str);


    void refactor ( void );
	ComplexNumber getDiscriminant ( void ) throw (DegreeTooHighException);
    vector<ComplexNumber> getRacines ( void ) throw (DegreeTooHighException);

	~Polynome( void );

private:
    int getMaxDegree ( void );
};


#endif //COMPUTOR1_POLYNOME_H
