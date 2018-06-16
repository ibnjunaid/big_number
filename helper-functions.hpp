

#pragma once

#include<iostream>
#include<string>

void strprint(std::string const & str);
bool is_allowed_char (char ch);
bool is_sign(char ch);
int skip_zeroes(std::string const &);

bool is_valid_number(std::string const &str)
{
	if ( str.empty() || not is_allowed_char(str[0]) )
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

bool is_allowed_char(char ch)
{
	return std::isdigit(ch) or ch == '+' or ch == '-';
}
bool is_sign(char ch)
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
int skip_zeroes(std::string const &str)
{
	// for(int i = is_sign(str[0]); i< str.size() ; i++)
	// {
	// 	if ( str[i] != '0')
	// 	{
	// 		return i;
	// 	}	
	// }
	// return str.size() - 1;

	int i = is_sign(str[0]);
	while(i < str.size() && str[i++] == '0');
	return i - 1;
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
