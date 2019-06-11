//
// Created by pelluro on 01/05/19.
//

#include "Polynome.hpp"
#include "functions.hpp"
#include "StringHelper.hpp"


using namespace std;


Polynome::DegreeTooHighException::DegreeTooHighException() {}
Polynome::DegreeTooHighException::DegreeTooHighException(DegreeTooHighException const &) {}
Polynome::DegreeTooHighException::~DegreeTooHighException() {}


int Polynome::getMaxDegree ( void ){
    if (this->tabMonomes.size() == 0)
        return 0;
    int degreeMax = 0;
    for (int j = 0; j < this->tabMonomes.size(); j++) {
        int degree = this->tabMonomes[j].getDegree();
        if(degree > degreeMax)
            degreeMax = degree;
    }
    this->degreeMax = degreeMax;
    return degreeMax;
}


void Polynome::refactor ( void ){
    vector<Monome> newTab;
	cout << "Before refactor :" << endl;
	for (int k = 0; k < this->tabMonomes.size(); ++k) {
		ComplexNumber c = this->tabMonomes[k].getCoeff();
		int d = this->tabMonomes[k].getDegree();
		cout << "(" << c << " * X ^" << d << ")" << endl;
	}

    for (int i = 0; i <= this->degreeMax; ++i) {
		ComplexNumber zero = ComplexNumber(0, 0);
        Monome m(zero,0);
        newTab.push_back(m);
    }
    for (int j = 0; j < this->tabMonomes.size(); j++) {
		ComplexNumber coeff = this->tabMonomes[j].getCoeff() ;
        int degree = this->tabMonomes[j].getDegree();
		ComplexNumber c = ComplexNumber(newTab[degree].getCoeff());
		ComplexNumber c2 = ComplexNumber(c + coeff);
        newTab[degree].setCoeff(c2);
        newTab[degree].setDegree(degree);
	}
    this->tabMonomes.clear();
	for (int j = 0; j < newTab.size() ; j++) {
		if(newTab[j].getCoeff() != ComplexNumber() || newTab[j].getDegree() == 0)
        	this->tabMonomes.push_back(newTab[j]);
    }
	this->degreeMax = this->getMaxDegree();
	cout << "Reduced form : " << endl;
    for (int k = this->tabMonomes.size() - 1; k >= 0; --k) {
    	if (k > 0 && this->tabMonomes[k].getDegree() == 0)
			continue;
        ComplexNumber c = this->tabMonomes[k].getCoeff();
        int d = this->tabMonomes[k].getDegree();
        if(k < this->tabMonomes.size() - 1)
		{
        	if (c.getReal() > 0)
				cout << "+";
		}
        if(d > 0)
        	cout << c << "*X^" << d;
        else
		{
        	if (c != ComplexNumber(0,0))
				cout << c;
		}
	}
    cout << " = 0 " << endl;
}



ComplexNumber Polynome::getDiscriminant ( void ) throw (DegreeTooHighException){

    if (this->degreeMax != 2) {
		throw DegreeTooHighException();
    }
    ComplexNumber a = this->tabMonomes[0].getCoeff();
    ComplexNumber b = this->tabMonomes[1].getCoeff();
    ComplexNumber c = this->tabMonomes[2].getCoeff();

    ComplexNumber toto = ComplexNumber(4,0);

	ComplexNumber discriminant = (b  * b) - (toto * a * c);
    return discriminant;
}


vector<ComplexNumber> Polynome:: getRacines ( void ) throw (DegreeTooHighException){
    vector<ComplexNumber> tabRacine;
	this->refactor();

    if(this->degreeMax > 2)
	{
    	cout << "Polynomial degree is not 2 or less. I can't solve it." << endl;
		return tabRacine;
	}
    else if ( this->degreeMax == 1)
	{
		ComplexNumber b = this->tabMonomes[0].getCoeff();
		ComplexNumber a = this->tabMonomes[1].getCoeff();
		ComplexNumber r =  ComplexNumber() - b / a;
		tabRacine.push_back(r);
	}
	else if ( this->degreeMax == 0)
	{
		ComplexNumber a = this->tabMonomes[0].getCoeff();
		if(a == ComplexNumber())
			cout << "Infite number of roots" << endl;
		else
			cout << "No root" << endl;
	}
	else
		{

		ComplexNumber discriminant = this->getDiscriminant();
        cout << "Discriminant is: "<<discriminant <<endl;
        if (discriminant == ComplexNumber()) {
			ComplexNumber b = this->tabMonomes[1].getCoeff();
			ComplexNumber a = this->tabMonomes[2].getCoeff();
			ComplexNumber r = (ComplexNumber() - b) / (ComplexNumber(2,0) * a);
            cout << "r1 = r2 = " << r << endl;
            tabRacine.push_back(r);
        }
        else {
			ComplexNumber b = this->tabMonomes[1].getCoeff();
			ComplexNumber a = this->tabMonomes[2].getCoeff();
			vector<ComplexNumber> deltas = discriminant.getSquareRoots();

			for (int i = 0; i < deltas.size(); ++i)
			{
				ComplexNumber delta = deltas[i];
 				ComplexNumber r = (ComplexNumber() - b + delta) / (ComplexNumber(2,0) * a);
				tabRacine.push_back(r);
			}
        }
    }
    return tabRacine;
}




Polynome ::Polynome(string str) {

    string s;
    string leftEquation;
    string rightEquation;

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
    vector<string> x = ft_strsplit(str, '=');

    leftEquation = StringHelper::AddPlusBeforeMinus(x[0]);
    rightEquation = StringHelper::AddPlusBeforeMinus(x[1]);

    cout << leftEquation << endl;
    cout << rightEquation << endl;

    vector<string> leftMonomes;
    vector<string> rightMonomes;
    leftMonomes = ft_strsplit(leftEquation,'+');
    rightMonomes = ft_strsplit(rightEquation, '+');
    int leftSize = leftMonomes.size();
    int rightSize = rightMonomes.size();

    cout << "Lecture des monomes de gauche (" << leftSize << ") elements" << endl;
    this->tabMonomes.clear();
    for (int i = 0; i < leftSize; i++) {
        string s = leftMonomes[i];
        cout << "Conversion de '" << s << "' en monome" << endl;
        try {
        	Monome m(s);
			this->tabMonomes.push_back(m);

		}
        catch (std::invalid_argument &e)
		{
        	throw (e);
		}

    }

    cout << "Lecture des monomes de droite (" << rightSize<< ") elements" << endl;
    for (int i = 0; i < rightSize; i++) {
        string s = rightMonomes[i];
        cout << "Conversion de '" << s << "' en monome" << endl;

		try {
			Monome m(s);
			ComplexNumber c((m.getCoeff()) * ComplexNumber(-1, 0));
			cout << c << endl;
			m.setCoeff(c);
			this->tabMonomes.push_back(m);
		}
		catch (std::invalid_argument &e)
		{
			throw (e);
		}
    }

    this->degreeMax = this->getMaxDegree();

}


Polynome::~Polynome()
{
	//std::cout << "call destructeur Polynome" << std::endl;
}
