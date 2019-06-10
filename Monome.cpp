//
// Created by pelluro on 01/05/19.
//

#include "Monome.hpp"
#include "functions.hpp"

Monome::Monome(string s) {
    cout << "Creation Monome a partir de '" << s << "'" << endl;
    vector<string> arr;
	if (s == "-X^0")
	{
		this->_coeff = ComplexNumber(-1,0);
		this->_degree = 0;
		return;
	}
	if (s == "-X" || s == "-X^1"){
		this->_coeff = ComplexNumber(-1,0);
		this->_degree = 1;
		return;
	}
	if (s == "-X^2"){
		this->_coeff = ComplexNumber(-1,0);
		this->_degree = 2;
		return;
	}

	arr = ft_strsplit(s,'X');

    if(arr.size() > 0) {
    	cout << arr[0] << endl;
        if (arr.size() == 1) {
        	cout << "Size 1" << endl;
			if (arr[0][0] == '^')
			{
				this->_coeff = ComplexNumber(1,0);
				arr[0].erase(0, 1);
				try
				{
					this->_degree = stoi(arr[0]);
				}
				catch (std::invalid_argument &e)
				{
					throw (e);
				}
			}
			else
			{
				cout << "coef = '" << arr[0] << "'" << endl;
				this->_coeff = ComplexNumber(arr[0]);
				this->_degree = 0;
			}
        } else {
			this->_coeff = ComplexNumber(arr[0]);
			if (arr[1][0] == '^') {
				arr[1].erase(0, 1);
			}
			try
			{
				this->_degree = stoi(arr[1]);
			}
			catch (std::invalid_argument &e)
			{
				throw (e);
			}
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
	//std::cout << "call destructeur Momone" << std::endl;
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