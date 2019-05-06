//
// Created by pelluro on 01/05/19.
//

#include "functions.h"

using namespace std;

template <class Container>
void split(const string& str, Container& cont, char delim)
{
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}


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

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
    size_t	i;
    char	*dest;

    i = 0;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (NULL);
    if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len && s[start])
    {
        dest[i] = s[start];
        start++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char	**ft_strsplit(const char *s, char c)
{
    char			**res;
    unsigned int	i;
    unsigned int	j;
    unsigned int	size;

    i = 0;
    j = 0;
    if (!s || !c ||
        !(res = (char **)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
        return (NULL);
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            size = 0;
            while (s[i + size] && (s[i + size] != c))
                size++;
            res[j++] = ft_strsub(s, i, size);
            i = i + size;
        }
    }
    res[j] = 0;
    return (res);
}
