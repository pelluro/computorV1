//
// Created by pelluro on 01/05/19.
//

#include "Monome.h"
#include "functions.h"


Monome::Monome(string s) {
    cout << "Creation monome a partir de '" << s << "'" << endl;
    vector<string> arr;
    arr = ft_strsplit(s,'x');

    if(arr.size() > 0) {
        this->coeff = stoi(arr[0]);
        cout << "Coeff = " << this->coeff << endl;
        if (arr.size() == 1) {
            if (s[s.size() - 1] == 'x')
                this->degree = 1;
            else
                this->degree = 0;
        } else {
            if (arr[1][0] == '^') {
                arr[1].erase(0, 1);
            }
            this->degree = stoi(arr[1]);
        }
        cout << "Degree = " << this->degree << endl;
    }
    else
    {
        this->degree = 1;
        this->coeff = 1;
    }
}

Monome::Monome(float coeff, int degree)
{
    this->degree = degree;
    this->coeff = coeff;
}

void Monome::print(void) {
    cout <<"degree est " << this->degree << endl;
    cout <<"coeff est " << this->coeff << endl;

}