//
// Created by pelluro on 01/05/19.
//

#include "functions.h"


template<typename Out>

void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


char *ft_strtrim(char *s)
{
    int			i;
    int			j;
    size_t		size;
    char		*dest;

    i = 0;
    j = 0;
    size = ft_strlen_skip_white(s) + 1;
    if (!s || !(dest = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;
    while (size--)
    {
        dest[j] = s[i + j];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

char **ft_strsplit(char *s, char c)
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


char *ft_strsub(char *s, int start, size_t len)
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




char	*ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
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

size_t	ft_strlen_skip_white(char *s)
{
    size_t i;
    int j;

    i = 0;
    if (!s)
        return (0);
    j = ft_strlen(s) - 1;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;
    if (s[i] == '\0')
        return (0);
    while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
        j--;
    return (j - i);
}

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strcat(char * dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i])
        i++;
    while (src[j])
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

int		ft_atoi( char *str)
{
    int		i;
    long	result;
    int		signe;

    i = 0;
    result = 0;
    signe = 1;
    while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == ' '
           || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
        signe = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] <= '9' && str[i] >= '0')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    result = result * signe;
    if (result < -2147483648 || result > 2147483647)
        return (0);
    return ((int)result);
}
