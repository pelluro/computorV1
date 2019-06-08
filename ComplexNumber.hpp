//
// Created by pelluro on 08/06/19.
//

#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP

#include <cmath>
#include <vector>


class ComplexNumber
{
public:
	ComplexNumber ();
	ComplexNumber (float r, float i);
	ComplexNumber (std::string s);
	ComplexNumber (ComplexNumber const &c);

	~ComplexNumber();

	ComplexNumber& operator=(ComplexNumber const & rhs);

	ComplexNumber operator+(ComplexNumber const & rhs) const;
	ComplexNumber operator-(ComplexNumber const & rhs) const;
	ComplexNumber operator*(ComplexNumber const & rhs) const;
	ComplexNumber operator/(ComplexNumber const & rhs) const;


	bool operator==(ComplexNumber const & rhs) const ;
	bool operator!=(ComplexNumber const & rhs) const ;
	float  getReal() const;
	float  getImaginary() const;
	void setReal ( float r );
	void setImaginary ( float i );
	std::vector<ComplexNumber> getSquareRoots();


private:

	float _real;
	float _imaginary;

};


std::ostream & operator <<(std::ostream & t, ComplexNumber const &c);

#endif //COM1_COMPLEXNUMBER_HPP
