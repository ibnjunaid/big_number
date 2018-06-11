#include <iostream>
#include "big_number.hpp"
int main()
{
	std::string s;
	
	std::cout << "enter any number @ BC:: ";
	
	std::cin >> s;

	big_number bc(s);

	std::cout << "enter any number @CC:: ";

	std::cin >> s;
	
	big_number cc(s);

	big_number big = bc+cc;

	std::cout<<"sum is : ";	big.printit();

	big_number lcc = bc - cc;
	
	std::cout<<"\n\nDifference is : ";lcc.printit();
}
