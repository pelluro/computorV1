//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Sample.h"

//le constructeur et destructeur n'ont pas de type de retour donc c'est toujour un void dans le parametres

Sample::Sample(int a1, float b1, char c1, float const f) : a(a1) ,b(b1), c(c1), pi(f) {
//j'initialise mon attribut a a la valeur de a1
    std::cout << "constructor Called" << std::endl;
//    std::cout << "this a "<< this->a << std::endl;
//    std::cout << "this b "<< this->b << std::endl;
//    std::cout << "this c "<< this->c << std::endl;
//    std::cout << "this pi"<< this->pi << std::endl;
    // this est un pointeur qui pointe sur l'instance courante

//    this->_funtion_private();
//    this->funtion_inside_class();
    return;
}


Sample:: ~Sample(void) {
    std::cout << "destructor Called" << std::endl;
    return;

}

void Sample :: funtion_inside_class( void ) const {
    std :: cout << "function inside has been called" << std :: endl;
    return;
}




int Sample ::getFoo(void) const {
    return this->_foo;
}


void Sample ::setFoo(int v) {

    if (v >= 3)
        this->_foo = v;
    else {
        std::cout << "error set foo" << std::endl;
    }
    return;
}

int Sample:: compare(Sample * other) const{
    if (this-> _foo < other->getFoo() )
        return (-1);
    else if (this->_foo > other->getFoo() )
        return (1);
    return 0;

}







void Sample ::_funtion_private() const {
    std :: cout << "function private has been called" << std :: endl;


    return;
}