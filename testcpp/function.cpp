#include <iostream>
#include <stdlib.h>
#include <stdio.h>


//using namespace std;

int toto = 1;
int f(void) {return 2;}

namespace Alpha {
    int toto = 3;
    int f(void) { return 4;}
}

namespace Beta {
    int toto = 5;
    int f (void) { return 6;}
}

namespace Gamma = Beta;

int main(void)
{
    printf("toto : [%d]\n", toto);
    printf("f()  : [%d]\n\n",f());
    printf("toto in alpha : [%d]\n", Alpha::toto);
    printf("f() in alpha  : [%d]\n\n",Alpha::f());

    return 0;
}
