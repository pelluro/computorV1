//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Polynome.hpp"
#include <string>
#include <cstring>
#include "functions.hpp"
#include "StringHelper.hpp"

using namespace std; /* std est un namespace special */


int main( int ac, char** const av) {

    string buff;
/*je redirige tout dans la sortie standard avec le double chevron */

	int	 returnVal = 0;
	char c = '=';
	vector<ComplexNumber> racines;

	Polynome *poly;
	if (ac == 2)
		buff = av[1];
	size_t found = buff.find(c);
    if (buff == "" || found == 0 || found == buff.size() -1 ) {
        cerr << "error input"  << endl;
		returnVal = EXIT_FAILURE;
    }
    else if (found == string::npos){
    	cerr << "Not a polynome valid " << endl;
		returnVal = EXIT_FAILURE;
    }
    else {
        cout << "you entered : [" << buff << "]" << endl;
        try
		{
			poly = new Polynome(buff);
			racines = poly->getRacines();
			for (int i = 0; i < racines.size(); i++) {
				cout << "Racine " << i + 1 << " = " << racines[i] << endl;
			}
//			delete poly;
		} catch (Polynome::DegreeTooHighException &) {
			cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
			returnVal = EXIT_FAILURE;
		} catch (std::invalid_argument)
		{
			std::cout << "Invalid Argument" << endl;
			returnVal = EXIT_FAILURE;
		}
		delete poly;
	}
    return returnVal;
}


//4* x^3 - 2*x^3 + x^2 = -2
//2 * x^2 + 4*x + 5 = 0
///"5 * X^0 + 3 * X^1 + 3 * X^6 = 1 * X^0 + 0 * X => refactor merde

// 4 * X = 4 * X  => segfault
//5 * X^0 = 5 * X^0 => segfault
//
