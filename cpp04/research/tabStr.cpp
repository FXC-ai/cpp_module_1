#include <iostream>
#include <string>	




int main()
{
	std::string CPP_tab[10];

	CPP_tab[0] = "chaine 0";
	CPP_tab[1] = "chaine 1";

	std::cout << "0 : " << &CPP_tab[0] << " : " << CPP_tab[0] <<std::endl;
	std::cout << "1 : " << &CPP_tab[1] << " : " << CPP_tab[1] <<std::endl;

	return 0;
}