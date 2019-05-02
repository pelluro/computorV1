//
// Created by pelluro on 01/05/19.
//

#include "Polynome.h"
#include <iostream>
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

char* Polynome::addPlusBeforeMinus(char* str){

    int i = 0;
    int j = 0 ;
    int minus = this->countMinus(str);
    char *strNew = (char*) malloc(sizeof(char)*(ft_strlen(str) + minus + 1));

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

int Polynome:: countMinus(char *str) {
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
    char * str1;
    char * leftEquation;
    char * rightEquation;
    char **leftMonomes;
    char **rightMonomes;


    str1 = ft_strtrim(str);

    s = ft_strsplit(str1, '=');

    leftEquation = this->addPlusBeforeMinus(s[0]);
    rightEquation = this->addPlusBeforeMinus(s[1]);

    leftMonomes = ft_strsplit(leftEquation, '+');
    rightMonomes = ft_strsplit(rightEquation, '+');
    int i = 0;
    while(leftMonomes[i])
    {
        i++;
    }
    Monome* leftTabMonomes = (Monome*)malloc(sizeof(Monome)*i);
    i = 0;
    while(leftMonomes[i])
    {
        Monome m(leftMonomes[i]);
        leftTabMonomes[i] = m;
        i++;
    }

    int j = 0;
    while(rightMonomes[j])
    {
        j++;
    }
    Monome* rightTabMonomes = (Monome*)malloc(sizeof(Monome)*j);
    j = 0;
    while(rightMonomes[j])
    {
        Monome m(rightMonomes[j]);
        rightTabMonomes[j] = m;
        rightTabMonomes[j].coeff *= -1;
        j++;
    }
    int k = i + j;
    this->tabMonomes= (Monome*)malloc(sizeof(Monome)*(k));
    i = 0;
    while(i < k - j)
    {
        this->tabMonomes[i] = leftTabMonomes[i];
        i++;
    }
    j=0;
    while(j < k - i)
    {
        this->tabMonomes[j] = rightTabMonomes[j];
        j++;
    }
}


