//
// Created by pelluro on 01/05/19.
//

#include "Monome.h"
#include "functions.h"

Monome::Monome(string s) {
    vector<string> arr;
    split(s, arr,'x');

    this->coeff = stoi(arr[0]);
    if (arr.size() == 1) {
        if(s[s.size()-1] == 'x')
            this->degree = 1;
        else
            this->degree = 0;
    }
    else {
        if(arr[1][0] == '^')
        {
            arr[1].erase(0,1);
        }
        this->degree = stoi(arr[1]);
    }
}