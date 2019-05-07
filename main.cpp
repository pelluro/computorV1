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
/*je redirige tout dans la sortie standard avec le double chevron */

	char c = '=';
	cout << "Hello! " << endl; /*jecris sur la sortie standard (count), puis j'ajoute le saut de la ligne (endl) */
    cout << "please enter a polynome : ";

    getline(cin, buff); //getline doesn't need the std:: prefix here because C++ has ADL(argument-dependent lookup).
	size_t found = buff.find(c);

    if (buff == "") {
        cerr << "error input"  << endl;
    }
    else if (found == string::npos){
			cerr << "Not a polynome valid " << endl;
    }
    else {
        cout << "you entered : [" << buff << "]" << endl;
        Polynome* poly = new Polynome( buff);
        poly->getRacines();
		delete(poly);
	}
    return 0;
}

