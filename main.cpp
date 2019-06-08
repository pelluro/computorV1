//
// Created by pelluro on 29/04/19.
//

#include <iostream>
#include "Polynome.hpp"
#include <string>
#include <cstring>
#include "functions.hpp"

using namespace std; /* std est un namespace special */

//void utilstest(char *q, char *res, int rr){
//	char buff[256];
//	int ret;
//	// clean
//	ret = getArgument(buff, q);
//	if (strcmp(res, buff) || ret != rr ){
//		printf("ko \n");
//	}
//	printf("ok \n");
//
//}
//
//void test_get_argument()
//{
//	utilstest("x + 8 = 0", "-8" , 0);
//}
//
//
//int getArgument(string buff, string s){
//
//
//}

int main( int ac, char** const av) {

    string buff;
/*je redirige tout dans la sortie standard avec le double chevron */

	char c = '=';
	if (ac == 2)
		buff = av[1];
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
        vector<ComplexNumber> racines = poly->getRacines();
        for (int i = 0; i < racines.size(); i++) {
            cout << "Racine " << i << " = " << racines[i] << endl;
        }
		delete poly;
	}
    return 0;
}


//4* x^3 - 2*x^3 + x^2 = -2