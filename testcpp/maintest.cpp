#include "Sample.h"
#include <iostream>
using namespace std;

int main(){

    Sample i(42,2.4f,'s',3.14f);
    //je definie une variable i de type Sample, donc  i  est une instance de la class Sample
    // cette ligne permet d'appeler et executer le code dans le constructeur
    // Sample est constance, i est dynamique
    //i.a = 32;
    //std::cout << i.toto << std::endl;
    i.a = 32;
    std::cout << i.a << std::endl;
    i.funtion_inside_class();
    i.setFoo(782);
    std::cout << "instance get foo: " << i.getFoo() << std::endl;
    i.setFoo(-5);
    std::cout <<"instance get foo: " << i.getFoo() << std::endl;



    
    return 0;

}

