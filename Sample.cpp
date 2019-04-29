//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Sample.h"

//le constructeur et destructeur n'ont pas de type de retour donc c'est toujour un void dans le parametres

Sample::Sample(void) {

    std::cout << "constructor Called" << std::endl;
    return;
}


Sample::~Sample(void) {
    std::cout << "destructor Called" << std::endl;
    return;

}