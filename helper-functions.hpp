#include<iostream>
#include<string>
#pragma once

void strprint(std::string const & str);
bool permittedCharacters (char ch);
bool indicateSign(char ch);
int checkiszero(std::string const &);

bool is_valid_number(std::string const &str)
{
	if ( str.empty() || not permittedCharacters(str[0]))
	{
		return false;
	}
	for (int i = 1; i< str.size(); i++)
	{
		if (not std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

bool permittedCharacters (char ch)
{
	return std::isdigit(ch) or ch == '+' or ch == '-';
}
bool indicateSign(char ch)
{
	return (ch == '+' || ch =='-');
}
void strprint(std::string const & str)
{
	for (char ch : str)
	{
		std::cout<<static_cast<unsigned short>(ch);
	}
}
int checkiszero(std::string const &str)
{
	for(int i=0 ;i< str.size();i++)
	{
		if ( indicateSign(str[i]))
		{
			continue;
		}
		if (not(str[i]-'0' == 0))
		{
			return i;
		}	
	}

	return str.size()-1;
}

bool  strcompare(std::string const &str1, std::string const &str2)
{
	for (int i = 0;i<str1.size();i++)
	{
		if (str1[i] > str2[i])
		{
			return true;
		}
		else if (str2[i] > str1[i])
		{
			return false;
		}
	}
	return true;
}
