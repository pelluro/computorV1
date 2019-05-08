//
// Created by pelluro on 01/05/19.
//

#include "Polynome.h"
#include "functions.h"

using namespace std;


int Polynome:: getMaxDegree ( void ){
    cout << "je rentre dans getMaxDegree" << endl;
    if (this->tabMonomes.size() == 0)
        return 0;
    int degreeMax = 0;

    for (int j = 0; j < this->tabMonomes.size(); j++) {
        int degree = this->tabMonomes[j].degree;
        if(degree>degreeMax)
            degreeMax = degree;
    }
    cout << "Degree max = " << degreeMax << endl;
    return degreeMax;

}


void Polynome:: refactor ( void ){
    cout << "je rentre dans refactor" <<endl;
    vector<Monome> newTab;
    for (int i = 0; i < this->degreeMax; ++i) {
        Monome m(0,0);
        newTab.push_back(m);
    }
    for (int j = 0; j < this->tabMonomes.size(); j++) {
        float coeff = this->tabMonomes[j].coeff;
        int degree = this->tabMonomes[j].degree;

        newTab[degree].coeff += coeff;
        newTab[degree].degree = degree;
    }
    this->tabMonomes.clear();
    for (int j = 0; j <= this->degreeMax; j++) {
        this->tabMonomes.push_back(newTab[j]);
    }
    cout << "Refactor done :" << endl;
    for (int k = 0; k < this->tabMonomes.size(); ++k) {
        float c = this->tabMonomes[k].coeff;
        int d = this->tabMonomes[k].degree;
        cout << c << "*x^" << d << endl;
    }
}



float Polynome:: getDiscriminant ( void ){
    cout << "je rentre dans getDiscriminant" << endl;
    if (this->degreeMax != 2) {
        cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
		exit(EXIT_FAILURE);
    }
    this->refactor();
    float a = this->tabMonomes[2].coeff;
    float b = this->tabMonomes[1].coeff;
    float c = this->tabMonomes[0].coeff;
    float discriminant = (b  * b) - (4 * a * c);
    return discriminant;
}


vector<float> Polynome:: getRacines ( void ){
    cout << "je rentre dans getRacines" << endl;
    vector<float> tabRacine;

    if(this->degreeMax == 2) {
        float discriminant = this->getDiscriminant();
        cout << "Discriminant = "<<discriminant<<endl;
        if (discriminant < 0) {
            cout << " polynome has racine irreel " << endl;
        } else if (discriminant == 0) {
            float b = this->tabMonomes[1].coeff;
            float a = this->tabMonomes[2].coeff;
            float r = (0 - b) / (2 * a);
            cout << "r1 = r2 = " << r << endl;
            tabRacine.push_back(r);
        } else {
            float b = this->tabMonomes[1].coeff;
            float a = this->tabMonomes[2].coeff;
            float delta = ft_sqrt(discriminant);
            cout << "Delta = " << delta << endl;
            float r1 = (0 - b - delta) / (2 * a);
            float r2 = (0 - b + delta) / (2 * a);
            cout << "r1 = " << r1 << endl;
            cout << "r2 = " << r2 << endl;
            tabRacine.push_back(r1);
            tabRacine.push_back(r2);
        }
    }
    return tabRacine;
}

string Polynome::addPlusBeforeMinus(string str){

    cout << "Add+Before- de '" << str << "'" << endl;
    int i = 0;
    int j = 0 ;
    int minus = this->countMinus(str);
    cout << "Found " << minus << " - " << endl;
    if(minus == 0)
        return  str;
    string strNew;
    while (str[i])
    {
        if (str[i] == '-'){
            strNew += '+';
        }
        strNew += str[i];
        i++;
    }
    return strNew;
}

int Polynome:: countMinus(string str) {
    int i = 0;
    int minus = 0;
    while (str[i]){
        if (str[i] == '-')
            minus++;
        i++;
    }
    return minus;
}

//rechecke les protection de malloc pour eviter le crash toussa toussa

Polynome ::Polynome(string str) {

    string s;
    string leftEquation;
    string rightEquation;
    cout << "je suis dans polynome" <<endl;

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << "my str is " << str <<endl;
    vector<string> x ;
    x = ft_strsplit(str, '=');
    cout << "x[0] = " << x[0] <<endl;
    cout << "x[1] = " << x[1] <<endl;
    leftEquation = addPlusBeforeMinus(x[0]);
    rightEquation = addPlusBeforeMinus(x[1]);
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

    cout << "Lecture des monomes de droite(" << rightSize<< ") elements" << endl;
    for (int i = 0; i < rightSize; i++) {
        string s = rightMonomes[i];
        cout << "Conversion de '" << s << "' en monome" << endl;
        Monome m(s);
        m.coeff *= -1;
        this->tabMonomes.push_back(m);
    }


    this->degreeMax = this->getMaxDegree();
    // il manque une fonction pour arranger les coeff de meme degree
    cout << "je sors de polynome" <<endl;

}

