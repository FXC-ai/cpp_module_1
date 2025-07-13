#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include "Brain.hpp"

int main()
{
	{
		std::cout << "---------- SCOPE 1 ----------" << std::endl;

		std::cout << "\033[1;32mInstaciation Dog avec Default Constructor :\033[0m" << std::endl;
		Dog Pilou;
		std::cout << "\n";

		std::cout << "\033[1;35mTests sur l'objet brain de l instance Dog :\033[0m" << std::endl;
		Pilou.getBrain()->setIdea(0,"Manger");
		Pilou.getBrain()->setIdea(1,"Jouer");
		Pilou.getBrain()->setIdea(2,"Se promener");
		std::cout << Pilou.getBrain()->getIdea(2) << std::endl;
		std::cout << Pilou.getBrain()->getIdea(0) << std::endl;
		std::cout << "\n";

		std::cout << "\033[1;32mInstanciation Dog avec Copy Constructor :\033[0m" << std::endl;
		Dog Kiki(Pilou);

		std::cout << "\n";
		std::cout << "\033[1;35mTests sur l'objet brain de la copie :\033[0m" << std::endl;
		std::cout << Kiki.getBrain()->getIdea(1) << std::endl;
		std::cout << "\n";


		std::cout << "\033[1;32mInstaciation Cat avec Default Constructor :\033[0m" << std::endl;
		Cat Caramel;
		Caramel.getBrain()->setIdea(0, "Dormir");
		Caramel.getBrain()->setIdea(1, "Miauler");
		Caramel.getBrain()->setIdea(2, "Boire");
		std::cout << "\n";

		std::cout << "\033[1;35mTests sur l'objet brain de l instance Cat :\033[0m" << std::endl;
		std::cout << Caramel.getBrain()->getIdea(1) << std::endl;

		std::cout << "\n";

		std::cout << "\033[1;32mInstanciation Cat avec Copy Constructor :\033[0m" << std::endl;
		Cat Doris(Caramel);
		std::cout << "\n";

		std::cout << "\033[1;35mTests sur l'objet brain de la copie Cat :\033[0m" << std::endl;
		std::cout << Doris.getBrain()->getIdea(2) << std::endl;
		std::cout << "\n";
	}
	std::cout << "\n";
	{
		std::cout << "---------- SCOPE 2 ----------" << std::endl;
		std::cout << "\n";
	
		Animal *Arche[10];
		int i;
		std::cout << "\033[1;32mInstaciation de 5 Dog dans le tableau :\033[0m" << std::endl;
		for (i = 0; i < 5; ++i)
		{
			Arche[i] = new Dog;
			std::cout << "\n";
		}

		std::cout << "\033[1;32mInstaciation de 5 Cat dans le tableau :\033[0m" << std::endl;
		for (i = 5; i < 10; ++i)
		{
			Arche[i] = new Cat;
			std::cout << "\n";
		}

		std::cout << "\033[1;32mTest fonction MakeSound() :\033[0m" << std::endl;
		for (i = 0; i < 10; ++i)
		{
			std::cout << i << " ";
			Arche[i]->makeSound();
		}
		std::cout << "\n";

		std::cout << "\033[1;32mDestruction des 10 objets Animal :\033[0m" << std::endl;
		for (i = 0; i < 10; ++i)
		{
			delete Arche[i];
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	{
		std::cout << "---------- SCOPE 3 ----------" << std::endl;
		std::cout << "\n";
	
		WrongAnimal *Arche[10];
		int i;

		std::cout << "\033[1;32mInstaciation de 10 WrongCat dans le tableau :\033[0m" << std::endl;
		for (i = 0; i < 10; ++i)
		{
			Arche[i] = new WrongCat;
			std::cout << "\n";
		}

		std::cout << "\033[1;32mTest fonction MakeSound() :\033[0m" << std::endl;
		for (i = 0; i < 10; ++i)
		{
			std::cout << i << " ";
			Arche[i]->makeSound();
		}
		std::cout << "\n";

		std::cout << "\033[1;32mDestruction des 10 objets Animal :\033[0m" << std::endl;
		for (i = 0; i < 10; ++i)
		{
			delete Arche[i];
			std::cout << "\n";
		}
	}

	{
		std::cout << "---------- SCOPE 4 ----------" << std::endl;
		std::cout << "\n";

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\n";

		delete j;//should not create a leak
		delete i;
		std::cout << "\n";

	}

	return 0;
}