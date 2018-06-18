

#include <iostream>
#include "big_number.hpp"

int main()
{
	std::string s;
	
	std::cout << "enter any number @ BC:: ";
	
	std::cin >> s;

	big_number  bc(s);

	std::cout << "enter any number @CC:: ";

	std::cin >> s;
	
	big_number  cc(s);

	const big_number big = bc + cc;

	std::cout << "Sum of two numbers is ::" << big;
	
	big_number const lcc = bc - cc;
	
	std::cout << "\n\nDifference is :" << lcc;
}
