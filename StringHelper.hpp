//
// Created by pelluro on 08/06/19.
//

#ifndef STRINGHELPER_HPP
#define STRINGHELPER_HPP

#include <iostream>
class StringHelper
{
public:
	StringHelper();
	~StringHelper();
/*
	class StringNotValidException : public std::exception {
	public:
		StringNotValidException();
		StringNotValidException(StringNotValidException const &);
		~StringNotValidException();
	private:
		StringNotValidException &	operator =(StringNotValidException const &);
	};
*/
	static std::string AddPlusBeforeMinus (std::string s);

private:
	static int CountMinus (std::string s);

};

#endif //COM1_STRINGHELPER_HPP
