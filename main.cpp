//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Polynome.h"
#include <string>
#include <cstring>
#include "functions.h"

using namespace std; /* std est un namespace special */

void utilstest(char *q, char *res, int rr){
	char buff[256];
	int ret;
	// clean
	ret = getArgument(buff, q);
	if (strcmp(res, buff) || ret != rr ){
		printf("ko \n");
	}
	printf("sdf \n");

}

void test_get_argument()
{
	utilstest("x + 8 = 0", "-8" , 0);
}


int getArgument(string buff, string s){


}

int main( int ac, char** av) {

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
        vector<float> racines = poly->getRacines();
        for (int i = 0; i < racines.size(); i++) {
            cout << "Racine " << i << " = " << racines[i] << endl;
        }
		delete poly;
	}
    return 0;
}


//4* x^3 - 2*x^3 + x^2 = -2