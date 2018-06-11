#include "helper-functions.hpp"
#pragma once
using namespace std;			//temporarily
class big_number 
{
private:
	char sign = '+';
	std::string number;

public:

	big_number(std::string big_num)				// paramterised constructor
	{
		if ( not is_valid_number(big_num)) 
		{
			throw std::invalid_argument("not a valid number");
		}
		
		if ( indicateSign(big_num[0]))					//indicateSign() returns true, if it finds + OR - symbol at the begining of string 
		{
			sign = big_num[0];
		}
		for (int i = checkiszero(big_num);i<big_num.size();i++)
		{
			if (indicateSign(big_num[i]))
			{
				continue;
			}
			number.push_back(big_num[i]-'0');
		}
		std::reverse(number.begin(),number.end());
	}

	big_number operator+ (big_number const & big_num);
	
	big_number operator- (big_number  const& big_num);

	friend ostream& operator<<(ostream &output, big_number const& big_num);

	void printit ()
	{
		for(int i = number.size()-1 ;i>=0; i--)				//for (char ch : number) { }  doesnt work
		{
			std::cout << static_cast<unsigned short>(number[i]);
		}
	}
};

big_number big_number::operator+ ( big_number const & big_num)
{
	std::string temp;
	auto bigger = number;
	auto smaller = big_num.number;
	
	if (bigger.size() < smaller.size())
	{
		bigger= big_num.number;
		smaller = number;
	}

	int hasil=0;
 	int i =0;	
	while(i < smaller.size())
	{
		int sum = bigger[i]+smaller[i]+hasil;
		temp.push_back(sum%10+'0');
		hasil = sum /10;
		i++;
	}
	while (i< bigger.size())
	{
		int sum = bigger[i]+hasil;
		temp.push_back(sum%10+'0');
		hasil = sum/10;
		i++;
	}
	if (hasil)
	{
		temp.push_back('1');
	}
	std::reverse(temp.begin(),temp.end());
	return big_number(temp);
}

big_number big_number::operator- ( big_number const&big_num)
{
	std::string temp;
	std::string bigger; 
	std::string smaller;
	
	if (number.size() > big_num.number.size())
	{
		bigger = number;
		smaller = big_num.number;
	}
	else if (number.size() < big_num.number.size())
	{
		bigger = big_num.number;
		smaller = number;
	}
	else 
	{
		if(strcompare(number,big_num.number))
		{
			bigger = number;
			smaller = big_num.number;
		}
		else
		{
			bigger = big_num.number;
			smaller = number;
		}
	}

	int i = 0 ;
	while ( i < smaller.size() )
	{
		if (bigger[i] >= smaller[i])
		{
			temp.push_back((bigger[i] - smaller[i]) + '0' );
		}
		else
		{
			bigger[i] = bigger[i]+10;
			bigger[i+1] = bigger[i+1]-1;
			temp.push_back( (bigger[i]-smaller[i]) + '0');
		}
		i++;
	}
	
	while (i < bigger.size())
	{
		std::string temp_t;
		temp.push_back(bigger[i]+'0');
		i++;
	}
	std::reverse(temp.begin(),temp.end());
	return big_number(temp);
}

ostream &operator<<(ostream &output,big_number const &big_num)
{	
	std::string toreturn;
	for(int i = big_num.number.size()-1 ;i>=0; i--)		
	{
		toreturn.push_back(big_num.number[i]+'0');
	}

	return output <<  toreturn; 
}
