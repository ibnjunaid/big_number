

#include <iostream>
#include "big_number.hpp"

int main()
{
	std::string s;
	
	std::cout << "enter any number @ BC:: ";
	
	std::cin >> s;

	big_number const bc(s);

	std::cout << "enter any number @CC:: ";

	std::cin >> s;
	
	big_number const cc(s);

	big_number const big = bc + cc;

	std::cout << "Sum of two numbers is ::" << big;
	
	big_number const lcc = bc - cc;
	
	std::cout << "\n\nDifference is :" << lcc;
}
