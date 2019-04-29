//
// Created by pelluro on 29/04/19.
//

#include <iostream>
using namespace std; /* std est un namespace special */

int main()
{
    std::string buff;
/*je redirige tout dans la sortie standard avev le double chevron */
    std::cout << "Hello World! im here" << std::endl; /*jecris sur la sortie standard (count), puis j'ajoute le saut de la ligne (endl) */
    std::cout << "input a word: ";
    getline(std::cin, buff); //getline doesn't need the std:: prefix here because C++ has ADL(argument-dependent lookup).
    //std:: cin >> buff; /*cin est mon objet de l'entree standard aue je redirige vers mon buff */
    if (buff.empty())
    {
        std:: cerr << "error input";
    }
    else {
        std::cout << "you entered : [" << buff << "]" << std::endl;
    }
    return 0;
}
