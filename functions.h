//
// Created by pelluro on 01/05/19.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int     ft_sqrt(int i);
char	**ft_strsplit(char *s, char c);
char	*ft_strtrim(char *s);
char	*ft_strsub(char *s, int start, size_t len);
int	    ft_strlen( char *str);
size_t		ft_strlen_skip_white(char *s);
char            *ft_strcat(char * dest, char *src);
int             ft_atoi(char *str);
vector<string>  split(const std::string &s, char delim);
#endif
