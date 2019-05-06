//
// Created by pelluro on 01/05/19.
//

#include "Polynome.h"
#include "functions.h"

using namespace std;


int Polynome:: getMaxDegree ( void ){
    if (this->tabMonomes == nullptr)
        return 0;

    int i = 0;
    int degree = 0;
    Monome  *currentPointeur = &(this->tabMonomes[0]);
    while ( currentPointeur != nullptr){
        if (currentPointeur->degree > degree) {
            degree = currentPointeur->degree;
        }
        i++;
        currentPointeur = &(this->tabMonomes[i]);
    }

    return degree;

}


void Polynome:: refactor ( void ){
    int i = 0;
    int degreeMax = this->getMaxDegree();
    Monome * newTab = (Monome*)malloc((degreeMax + 1) *sizeof(Monome));
    Monome  *currentPointeur = &(this->tabMonomes[0]);
    while ( currentPointeur != nullptr) {
        newTab[currentPointeur->degree].coeff += currentPointeur->coeff;
        newTab[currentPointeur->degree].degree = currentPointeur->degree;
        i++;
        currentPointeur = &(this->tabMonomes[i]);
    }
    this->tabMonomes = newTab;
}



float Polynome:: getDiscriminant ( void ){
    cout << "je rentre dans getDiscriminant" << endl;

    int degreeMax = this->getMaxDegree();
    if (degreeMax != 2) {
        throw std::invalid_argument(" degree of polynome has to be 2");
    }
    this->refactor();
    float discriminant = this->tabMonomes[1].coeff * this->tabMonomes[1].coeff - 4 * this->tabMonomes[0].coeff * this->tabMonomes[2].coeff;
    return discriminant;
}


float* Polynome:: getRacines ( void ){
    cout << "je rentre dans getRacines" << endl;
    float discriminant = this->getDiscriminant();
    float *tabRacine;
    if ( discriminant < 0)
    {
        cout << " polynome has racine irreel " << endl;
        return nullptr;
    }
    else if (discriminant == 0)
    {
        tabRacine = (float *) malloc (sizeof(float) * 1);
        tabRacine[0]  = 0 - (this->tabMonomes[1].coeff / 2* this->tabMonomes[0].coeff);
        return tabRacine ;
    }
    else
    {
        tabRacine = (float *) malloc (sizeof(float) * 2);
        tabRacine[0] = 0 -( ft_sqrt(discriminant) / 4 * 2* this->tabMonomes[0].coeff * 2* this->tabMonomes[2].coeff);
        tabRacine[1] = -tabRacine[0];
        return tabRacine;
    }
}

string Polynome::addPlusBeforeMinus(string str){


    int i = 0;
    int j = 0 ;
    int minus = this->countMinus(str);
    char *strNew = (char*) malloc(sizeof(char)*(str.size() + minus + 1));


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
    }
    return minus;
}

//rechecke les protection de malloc pour eviter le crash toussa toussa

Polynome ::Polynome(string str) {

    string s;
    string leftEquation;
    string rightEquation;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    vector<string> x;
    split(str, x, '=');

    leftEquation = addPlusBeforeMinus(x[0]);
    rightEquation = addPlusBeforeMinus(x[1]);

    vector<string> leftMonomes;
    vector<string> rightMonomes;
    split(leftEquation,  leftMonomes,'+');
    split(rightEquation, rightMonomes, '+');
    ulong leftSize = leftEquation.size();
    ulong rightSize = rightEquation.size();

    Monome* leftTabMonomes = (Monome*)malloc(sizeof(Monome)*leftSize);
    Monome* rightTabMonomes = (Monome*)malloc(sizeof(Monome)*rightSize);
    for (int i = 0; i < leftSize; i++) {
        Monome m(leftMonomes[i]);
        leftTabMonomes[i] = m;
    }

    for (int i = 0; i < rightSize; i++) {
        Monome m(rightMonomes[i]);
        rightTabMonomes[i] = m;
        rightTabMonomes[i].coeff *= -1;
    }
    this->tabMonomes= (Monome*)malloc(sizeof(Monome)*(leftSize + rightSize));
    for (int i = 0; i < leftSize+rightSize; i++) {
        if (i < leftSize) {
            this->tabMonomes[i] = leftTabMonomes[i];
        } else {
            this->tabMonomes[i] = rightTabMonomes[i - leftSize];
        }
    }
}

