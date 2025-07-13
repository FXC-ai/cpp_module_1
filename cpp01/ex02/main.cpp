#include <string>
#include <iostream>

int main ()
{	
	std::string	chain("HI THIS IS BRAIN");
	std::string	*stringPTR = &chain;
	std::string	&stringREF = chain;

	std::cout << "Adresse de la string en mémoire = " << &chain << std::endl;
	std::cout << "Adresse stockee dans stringPTR  = " << stringPTR << std::endl;
	std::cout << "Adresse stockee dans stringREF  = " << &stringREF << std::endl;

	std::cout << "           Valeur de la string  = " << chain << std::endl;
	std::cout << "  Valeur pointee par stringPTR  = " << *stringPTR << std::endl;
	std::cout << "  Valeur pointée par stringREF  = " << stringREF << std::endl;

	return 0;
}