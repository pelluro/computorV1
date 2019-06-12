//
// Created by pelluro on 01/05/19.
//

#include "Monome.hpp"
#include "functions.hpp"


void Monome::caseOne( void )
{
	this->_coeff = ComplexNumber(-1,0);
	this->_degree = 0;
}

void Monome::caseTwo( void )
{
	this->_coeff = ComplexNumber(-1,0);
	this->_degree = 1;
}

void Monome::caseThree( void )
{
	this->_coeff = ComplexNumber(-1,0);
	this->_degree = 2;
}


bool Monome::chooseCase(std::string const &case_name)
{
	static const tChooseCase			casePicker[4] = {
	 	{"-X^0", &Monome::caseOne},
	 	{"-X", &Monome::caseTwo},
	 	{"-X^1", &Monome::caseTwo},
	 	{"-X^2", &Monome::caseThree}
	};
	for (int i = 0; i <4; i++)
	{
		if (case_name.compare(casePicker[i].nameCase) == 0){
			(this->*casePicker[i].funName)();
			return (true);
		}
	}
	return (false);

}


Monome::Monome(string s) {
    cout << "Creation Monome a partir de '" << s << "'" << endl;
    vector<string> arr;
    size_t f = s.find('X');

    if (this->chooseCase( s)) {
    	return ;
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
				}
			}
			else
			{
				cout << "coef = '" << arr[0] << "'" << endl;
				this->_coeff = ComplexNumber(arr[0]);
				if (f != string::npos)
					this->_degree = 1;
				else
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
			catch (std::out_of_range &)
			{
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