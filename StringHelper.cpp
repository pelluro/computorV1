//
// Created by pelluro on 08/06/19.
//

#include "StringHelper.hpp"
using namespace std;


string StringHelper::AddPlusBeforeMinus(string str){

	int i = 0;
	int j = 0 ;
	int minus = CountMinus(str);
	if(minus == 0)
		return  str;
	string strNew;
	while (str[i])
	{
		if (str[i] == '-'){
			strNew += '+';
		}
		strNew += str[i];
		i++;
	}
	return strNew;
}

int StringHelper:: CountMinus(string str) {
	int i = 0;
	int minus = 0;
	while (str[i]){
		if (str[i] == '-')
			minus++;
		i++;
	}
	return minus;
}
