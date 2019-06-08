//
// Created by pelluro on 01/05/19.
//

#include "Monome.hpp"
#include "functions.hpp"

Monome::Monome(string s) {
    cout << "Creation Monome a partir de '" << s << "'" << endl;
    vector<string> arr;
    arr = ft_strsplit(s,'x');

    if(arr.size() > 0) {
    	cout << arr[0] << endl;
        this->_coeff = ComplexNumber(arr[0]);
        if (arr.size() == 1) {
            if (s[s.size() - 1] == 'x')
                this->_degree = 1;
            else
                this->_degree = 0;
        } else {
            if (arr[1][0] == '^') {
                arr[1].erase(0, 1);
            }
            this->_degree = stoi(arr[1]);
        }
    }
    else
    {
        this->_degree = 1;
        this->_coeff = ComplexNumber(1,0);
    }
    print();
}

Monome::Monome(ComplexNumber coeff, int degree)
{
    this->_degree = degree;
    this->_coeff = coeff;
}

Monome::~Monome()
{
}

ComplexNumber Monome::getCoeff ( void ){
	return this->_coeff;
}

int Monome::getDegree ( void ){
	return this->_degree;
}

void Monome::setCoeff ( ComplexNumber c){
	this->_coeff = c;
}
void Monome::setDegree ( int d){
	this->_degree = d;
}

void Monome::print(void) {
    cout <<"degree est " << this->_degree << endl;
    cout <<"coeff est " << this->_coeff << endl;

}