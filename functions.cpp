//
// Created by pelluro on 01/05/19.
//

#include "functions.h"
#include <string>
using namespace std;


int	ft_sqrt(int nb)
{
    int i;

    i = 1;
    if (nb < 0)
        return (0);
    while (i <= nb && i <= 46340)
    {
        if (i * i == nb)
        {
            return (i);
        }
        i++;
    }
    return (0);
}

vector<string>	ft_strsplit(string s, char c)
{
    vector<string>			res;
    unsigned int	i;
    unsigned int	size;

    i = 0;
    cout << "split de s = " << s << " avec le char '"<<c<<"'"<< endl;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            size = 0;
            while (s[i + size] && (s[i + size] != c))
                size++;
            string split = s.substr(i, size);
            cout << "split de s en i = " << i << " et size = " << size << " donne : " << split << endl;
            res.push_back(split);
            i = i + size;
        }
    }
    cout << "Creation d'un tableau de " << res.size() << " elements" << endl;
    return (res);
}
