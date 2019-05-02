//
// Created by pelluro on 01/05/19.
//

#include "Monome.h"
#include "functions.h"


Monome::Monome(float coeff, int degree){
    this->coeff = coeff;
    this->degree = degree;
}

Monome::Monome(char *s) {
    char **str = ft_strsplit(s,'x');

    this->coeff = ft_atoi(str[0]);
    if (str[1] == nullptr)
        this->degree = 0;
    else
    {
        this->degree = ft_atoi(str[1]++);
    }
}