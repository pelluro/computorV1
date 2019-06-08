//
// Created by pelluro on 08/06/19.
//

#include <iostream>
#include <vector>
#include <exception>
#include "ComplexNumber.hpp"
#include "StringHelper.hpp"
#include "functions.hpp"

ComplexNumber::ComplexNumber(): _real(0),_imaginary (0)
{
}

ComplexNumber::~ComplexNumber()
{
	//std::cout << " call destructeur ComplexeNumber "  << *this << std::endl;
}

ComplexNumber::ComplexNumber(float r, float i) : _real(r),_imaginary (i)
{
}

ComplexNumber::ComplexNumber(std::string s)
{
	s = StringHelper::AddPlusBeforeMinus(s);
	std::vector<string>splitTab = ft_strsplit(s, '+');
	if (splitTab.size() > 2)
		throw std::exception();
	size_t indexOfi = splitTab[0].find_first_of("i");
	if(indexOfi == std::string::npos)
	{
		if (splitTab.size() == 2)
			this->_imaginary = stoi(splitTab[1]);
		this->_real = stoi(splitTab[0]);
	}
	else
	{
		this->_imaginary = stoi(splitTab[0]);
		if (splitTab.size() == 2)
			this->_real = stoi(splitTab[1]);
	}

}

ComplexNumber::ComplexNumber(ComplexNumber const &c)
{
	*this = c;
}

ComplexNumber& ComplexNumber::operator=(ComplexNumber const & rhs)
{
	this->_real = rhs._real;
	this->_imaginary = rhs._imaginary;
	return *this;

}


ComplexNumber ComplexNumber:: operator+(ComplexNumber const & rhs) const
{
	ComplexNumber c(this->_real + rhs._real, this->_imaginary + rhs._imaginary);
	return c;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber const & rhs) const {
	ComplexNumber c(this->_real - rhs._real, this->_imaginary - rhs._imaginary);

	return c;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber const & rhs) const{
	float real=(this->_real * rhs._real) - (this->_imaginary * rhs._imaginary);
	float imaginary = this->_real * rhs._imaginary + this->_imaginary * rhs._real;

	return ComplexNumber(real, imaginary);
}

ComplexNumber ComplexNumber:: operator/(ComplexNumber const & rhs) const {
	float real = (this->_real * rhs._real + this->_imaginary * rhs._imaginary) /
	(rhs._real * rhs._real + rhs._imaginary * rhs._imaginary);
	float imaginary = (this->_imaginary * rhs._real - this->_real * rhs._imaginary)/
	(rhs._real * rhs._real + rhs._imaginary * rhs._imaginary);

	return ComplexNumber(real, imaginary);
}

bool ComplexNumber:: operator==(ComplexNumber const & rhs) const {
	return (this->_real == rhs._real && this->_imaginary == rhs._imaginary);

}
bool ComplexNumber:: operator!=(ComplexNumber const & rhs) const {
	return (this->_real != rhs._real || this->_imaginary != rhs._imaginary);
}

float ComplexNumber::getReal() const
{
	return this->_real;
}

float ComplexNumber::getImaginary() const
{
	return this->_imaginary;
}

void ComplexNumber::setReal(float r)
{
	this->_real = r;
}
void ComplexNumber::setImaginary(float i)
{
	this->_imaginary = i;
}

//calcul racine nb complexe
std::vector<ComplexNumber> ComplexNumber::getSquareRoots(){
	float absx;
	float absy;
	float a = this->getReal();
	float b = this->getImaginary();
	float t = ft_sqrt(a *a + b* b);

	absx = ft_sqrt((a + t) / 2);
	absy = ft_sqrt((t - a) / 2);

	ComplexNumber c1 (absx, absy);
	ComplexNumber c2 ( -absx, -absy);

	std::vector<ComplexNumber> roots;
	roots.push_back(c1);
	roots.push_back(c2);
	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	return roots;
}



//affichage

std::ostream &operator<<(std::ostream &o, ComplexNumber const &rhs)
{

	if(rhs.getImaginary() == 0)
		o << rhs.getReal();
	else if(rhs.getReal() == 0)
		o << rhs.getImaginary() << "i" ;
	else if(rhs.getImaginary() > 0)
		o << rhs.getReal() << "+" << rhs.getImaginary() << "i" ;
	else
		o << rhs.getReal() << rhs.getImaginary() << "i" ;
	return o;
}