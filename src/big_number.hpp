
#pragma once

#include "helper-functions.hpp"

class big_number 
{

private:

	char sign = '+';
	std::string number;

public:

	big_number(std::string const & big_num)				// paramterised constructor
	{
		if ( not is_valid_number(big_num)) 
		{
			throw std::invalid_argument("not a valid number");
		}
		
		if ( is_sign(big_num[0]))					//is_sign() returns true, if it finds + OR - symbol at the begining of string 
		{
			sign = big_num[0];
		}
		for (int i = skip_zeroes(big_num); i < big_num.size() ; i++)
		{
			number.push_back(big_num[i]-'0');
		}
		std::reverse(number.begin(),number.end());
	}

	big_number operator+ (big_number const & big_num);
	
	big_number operator- (big_number const & big_num);

	friend std::ostream& operator<<(std::ostream &output, big_number const & big_num);

};

big_number big_number::operator+ ( big_number const & big_num)
{
	auto additionLambda = [this,&big_num] () ->big_number {

	std::string temp;
	auto const & bigger  = number.size() > big_num.number.size() ? number : big_num.number;
	auto const & smaller = number.size() <= big_num.number.size() ? number : big_num.number;

	int hasil=0;
 	int i =0;	
	while(i < smaller.size())
	{
		int sum = bigger[i] + smaller[i] + hasil;
		temp.push_back(sum%10+'0');
		hasil = sum /10;
		i++;
	}
	while (i< bigger.size())
	{
		int sum = bigger[i] + hasil;
		temp.push_back(sum%10 + '0');
		hasil = sum/10;
		i++;
	}
	if (hasil)
	{
		temp.push_back('1');
	}
	std::reverse(temp.begin(),temp.end());
	big_number toret(temp);
	};
	if (this->sign == '+' and big_num.sign == '-' and strcompare(this->number,big_num.number) )
	{
		//+ve case
		big_number result = (*this - big_num);
		return result;

	}

	else if (this->sign == '+' and big_num.sign == '-' and not strcompare(this->number,big_num.number) )
	{
		//-ve Case
		big_number result = (*this - big_num);
		result.sign = '-';
		return result;
	}

	else if (this->sign == '-' and big_num.sign == '+' and strcompare(this->number,big_num.number) )
	{
		//-ve case
		big_number result = (*this - big_num);
		result.sign = '-';
		return result;
	}

	else if (this->sign == '-' and big_num.sign == '+' and not strcompare(this->number,big_num.number) ) 
	{
		//+ve Case
		big_number result = (*this - big_num);
		return result;
	}
	else if (this->sign == '+' and big_num.sign == '+' )
	{
		big_number result = additionLambda();
		return result;
	}

	else if (this->sign == '-' and big_num.sign == '-')
	{
		big_number result = additionLambda();
		result.sign = '-';
		return result;
	}
}

big_number big_number::operator- ( big_number const & big_num)
{
	auto subtractingLambda = [this, & big_num] ()-> big_number {
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
		};

	if (this->sign == '-' and big_num.sign == '-' and strcompare(this->number,big_num.number) ) 
	{
		big_number result = subtractingLambda();
		result.sign ='-';
		return result;
	}

	else if (this->sign == '-' and big_num.sign =='-' and not strcompare(this->number,big_num.number) )
	{
		big_number result = subtractingLambda();
		result.sign = '+';
		return result;
	}

	else if (this->sign == '+' and big_num.sign == '-' and strcompare(this->number,big_num.number) )
	{
		big_number result = subtractingLambda();
		result.sign = '+';
		return result;
	} 
	else if (this->sign == '+' and big_num.sign == '-' and not strcompare(this->number,big_num.number) )
	{
		big_number result = subtractingLambda();
		result.sign = '+';
		return result;
	}
	else if (this->sign == '-' and big_num.sign == '+' and strcompare(this->number ,big_num.number) )
	{
		big_number copy1 = *this; copy1.sign ='-';																		
		big_number copy2 = big_num; copy2.sign ='-';
		big_number result = copy1 + copy2;
		return result;								//big_number result = (*this + big_num);
													//result.sign = '-';
													//return result;
	}
	else if (this->sign == '-' and big_num.sign == '+' and not strcompare(this->number ,big_num.number) )
	{
		big_number copy1 = *this; copy1.sign ='-';																	
		big_number copy2 = big_num; copy2.sign ='-';
		big_number result = copy1 + copy2;
		return result;								//big_number result = (*this + big_num);
													//result.sign = '-';
													//return result;
	}
	else if (this->sign == '+' and big_num.sign == '+' and strcompare (this->number,big_num.number) )
	{
		big_number result = subtractingLambda();
		result.sign ='+';
		return result;
	}
	else if (this->sign == '+' and big_num.sign == '+' and not strcompare (this->number, big_num.number) )
	{
		big_number result = subtractingLambda();
		result.sign = '-';
		return result;
	}
	else {
		std::clog<<"Uncaught Case !! An error occured";
	}
}
	
std::ostream &operator<<(std::ostream &output,big_number const &big_num)
{	
	std::string toreturn;
	toreturn.push_back(big_num.sign);
	for(int i = big_num.number.size()-1 ;i>=0; i--)		
	{
		toreturn.push_back(big_num.number[i]+'0');
		//output << big_num.number[i] + '0';
	}

	return  output << toreturn; 
}
