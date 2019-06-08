//
// Created by pelluro on 01/05/19.
//

#include "functions.hpp"
#include <string>
using namespace std;


float	ft_sqrt(float nb)
{
    float i;

    i = 1;
    if (nb < 0)
        return (0);
    while (i <= nb && i <= 46340)
    {
        if (i * i >= nb)
        {
            return (i);
        }
        i+= 0.000001;
    }
    return (0);
}

vector<string>	ft_strsplit(string s, char c)
{
    vector<string>			res;
    unsigned int	i;
    unsigned int	size;

    i = 0;
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
            res.push_back(split);
            i = i + size;
        }
    }
    return (res);
}
