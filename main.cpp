//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Polynome.h"
#include <string>
#include "functions.h"

using namespace std; /* std est un namespace special */

int main() {

    string buff;
/*je redirige tout dans la sortie standard avev le double chevron */


    cout << "Hello! " << endl; /*jecris sur la sortie standard (count), puis j'ajoute le saut de la ligne (endl) */
    cout << "please enter a polynome : ";
    getline(cin, buff); //getline doesn't need the std:: prefix here because C++ has ADL(argument-dependent lookup).
//    cin >> buff; /*cin est mon objet de l'entree standard aue je redirige vers mon buff */
//
    if (buff == "") {
        cerr << "error input";
    } else {
        cout << "you entered : [" << buff << "]" << endl;
        Polynome poly( buff);

        poly.getRacines();
    }
    return 0;
}

