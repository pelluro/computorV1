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
    return degreeMax;

}


void Polynome:: refactor ( void ){
    cout << "je rentre dans refactor" <<endl;
    int degreeMax = this->getMaxDegree();
    vector<Monome> newTab;
    for (int j = 0; j < this->tabMonomes.size(); j++) {
        float coeff = this->tabMonomes[j].coeff;
        int degree = this->tabMonomes[j].degree;

        newTab[degree].coeff += coeff;
        newTab[degree].degree = degree;
    }
    this->tabMonomes.clear();
    for (int j = 0; j <= degreeMax; j++) {
        this->tabMonomes.push_back(newTab[j]);
    }
}



float Polynome:: getDiscriminant ( void ){
    cout << "je rentre dans getDiscriminant" << endl;

    int degreeMax = this->getMaxDegree();
    cout << "degreeMax " << degreeMax<<endl;
    cout << "je sors getMaxDegrees" << endl;

    if (degreeMax != 2) {
        cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
		EXIT_FAILURE;
    }
    this->refactor();
    float discriminant = this->tabMonomes[1].coeff * this->tabMonomes[1].coeff - 4 * this->tabMonomes[0].coeff * this->tabMonomes[2].coeff;
    return discriminant;
}


vector<float> Polynome:: getRacines ( void ){
    cout << "je rentre dans getRacines" << endl;
    float discriminant = this->getDiscriminant();
    vector<float> tabRacine;
    if ( discriminant < 0)
    {
        cout << " polynome has racine irreel " << endl;
        return tabRacine;
    }
    else if (discriminant == 0)
    {
        tabRacine[0]  = 0 - (this->tabMonomes[1].coeff / 2* this->tabMonomes[0].coeff);
        return tabRacine;
    }
    else
    {
        tabRacine[0] = 0 -( ft_sqrt(discriminant) / 4 * 2* this->tabMonomes[0].coeff * 2* this->tabMonomes[2].coeff);
        tabRacine[1] = -tabRacine[0];
        return tabRacine;
    }
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
            strNew[j] = '+';
            j++;
        }
        strNew[j] = str[i];
        i++;
        j++;
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

    vector<string> leftMonomes;
    vector<string> rightMonomes;
    leftMonomes = ft_strsplit(leftEquation,'+');
    rightMonomes = ft_strsplit(rightEquation, '+');
    int leftSize = leftMonomes.size();
    int rightSize = rightMonomes.size();

    cout << "Lecture des monomes de gauche (" << leftSize << ") elements" << endl;
    this->tabMonomes.clear();
    for (int i = 0; i < leftSize; i++) {
        string s = leftMonomesx[i];
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

    // il manque une fonction pour arranger les coeff de meme degree
    cout << "je sors de polynome" <<endl;

}

