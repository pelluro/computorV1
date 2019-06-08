//
// Created by pelluro on 01/05/19.
//

#include "Polynome.hpp"
#include "functions.hpp"
#include "StringHelper.hpp"


using namespace std;


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
    for (int i = 0; i < this->degreeMax; ++i) {
        Monome m(ComplexNumber(),0);
        newTab.push_back(m);
    }
    for (int j = 0; j < this->tabMonomes.size(); j++) {
		ComplexNumber coeff = this->tabMonomes[j].getCoeff() ;
        int degree = this->tabMonomes[j].getDegree();

        newTab[degree].setCoeff(newTab[degree].getCoeff() + coeff);
        newTab[degree].setDegree(degree);
    }
    this->tabMonomes.clear();
    for (int j = 0; j <= this->degreeMax; j++) {
        this->tabMonomes.push_back(newTab[j]);
    }
    cout << "Refactor done :" << endl;
    for (int k = 0; k < this->tabMonomes.size(); ++k) {
        ComplexNumber c = this->tabMonomes[k].getCoeff();
        int d = this->tabMonomes[k].getDegree();
        cout << c << "*x^" << d << endl;
    }
}



ComplexNumber Polynome::getDiscriminant ( void ){
    if (this->degreeMax != 2) {
        cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
		exit(EXIT_FAILURE);
    }
    this->refactor();
    ComplexNumber a = this->tabMonomes[2].getCoeff();
    ComplexNumber b = this->tabMonomes[1].getCoeff();
    ComplexNumber c = this->tabMonomes[0].getCoeff();
	ComplexNumber discriminant = (b  * b) - (ComplexNumber(4,0) * a * c);
    return discriminant;
}


vector<ComplexNumber> Polynome:: getRacines ( void ){
    vector<ComplexNumber> tabRacine;

    if(this->degreeMax == 3)
	{
    	cout << "Polynomial is degree 3. I can't solve it." << endl;
		return tabRacine;
	}
	else
		{

		ComplexNumber discriminant = this->getDiscriminant();
        cout << "Discriminant = "<<discriminant<<endl;
        if (discriminant == ComplexNumber()) {
			ComplexNumber b = this->tabMonomes[1].getCoeff();
			ComplexNumber a = this->tabMonomes[2].getCoeff();
			ComplexNumber r = (ComplexNumber() - b) / (ComplexNumber(2,0) * a);
            cout << "r1 = r2 = " << r << endl;
            tabRacine.push_back(r);
        } else {
			ComplexNumber b = this->tabMonomes[1].getCoeff();
			ComplexNumber a = this->tabMonomes[2].getCoeff();
			vector<ComplexNumber> deltas = discriminant.getSquareRoots();
			for (int i = 0; i < deltas.size(); ++i)
			{
				ComplexNumber delta = deltas[i];
				ComplexNumber r1 = (ComplexNumber() - b - delta) / (ComplexNumber(2,0) * a);
				ComplexNumber r2 = (ComplexNumber() - b + delta) / (ComplexNumber(2,0) * a);
				tabRacine.push_back(r1);
				tabRacine.push_back(r2);
			}
        }
    }
    return tabRacine;
}


//rechecke les protection de malloc pour eviter le crash toussa toussa

float Polynome::getRacineSimple( void )
{
	float racine = 0;

	return racine;
}

Polynome ::Polynome(string str) {

    string s;
    string leftEquation;
    string rightEquation;

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
    vector<string> x ;
    x = ft_strsplit(str, '=');
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
        Monome m(s);
        this->tabMonomes.push_back(m);
    }

    cout << "Lecture des monomes de droite (" << rightSize<< ") elements" << endl;
    for (int i = 0; i < rightSize; i++) {
        string s = rightMonomes[i];
        cout << "Conversion de '" << s << "' en monome" << endl;
        Monome m(s);
        m.setCoeff(m.getCoeff() * ComplexNumber(-1, 0));
        this->tabMonomes.push_back(m);
    }


    this->degreeMax = this->getMaxDegree();
    // il manque une fonction pour arranger les coeff de meme degree

}


Polynome::~Polynome()
{
}