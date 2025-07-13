# Projet du cursus 42

Ceci est le fruit de recherches dans le but de valider le module CPP00 de l'école 42.

## Calculs en C++

```cpp
#include <iostream>
#include <string>
#include <cmath>

int main ()
{
	int	n1;
	int	const n2(42);
	int	result;

	std::cout << "nb1 : ";
	std::cin >> n1;

	result = n1 + n2;
	std::cout << "      addition = " << result <<std::endl;
	result = n1 - n2;
	std::cout << "  soustraction = " << result <<std::endl;
	result = n1 * n2;
	std::cout << "multiplication = " << result <<std::endl;
	result = n1 / n2;
	std::cout << "      division = " << result <<std::endl;
	result = n1 % n2;
	std::cout << "        modulo = " << result <<std::endl;
	result = sqrt(n1);
	std::cout << "  racine carre = " << result <<std::endl;
	result = pow(n1, 2);
	std::cout << "         carre = " << result <<std::endl;

	return 0;
}
```

## Variables facultatives en C++

```cpp
#include <iostream>
#include <string>
#include <cmath>

int calcule_seconds(int heures = 0, int minutes = 0, int secondes = 0)
{
	int total;

	total = heures * 3600;
	total += minutes * 60;
	total += secondes;

	return total;
}

int main ()
{
	int i;
	int	n1;
	int	n2;

	std::cout << "nb1 : ";
	std::cin >> n1;

	std::cout << "nb2 : ";
	std::cin >> n2;

	for (i = 0; n1 < n2; i++)
	{
		n1++;
		std::cout << n1 <<std::endl;
	}

	n2 = calcule_seconds(0,2,25);
	std::cout << n2 <<std::endl;

	return 0;
}
```

## L’objet string en C++

```cpp
#include <iostream>
#include <string>
 
int main()
{
  std::string maChaine("Premier test");

	std::cout << maChaine <<std::endl;

	int size(maChaine.size());
	
	std::cout << size <<std::endl;

	std::string maChaine2(maChaine.substr(0,10));

	std::cout << maChaine2 <<std::endl;

  return 0;
}
```

## Les variable en C++

```cpp
#include <iostream>
#include <string>

int main ()
{

	std::cout << "Exemple d'utilisation de CPP" <<std::endl;

	int	age;
	std::cout << "Quel est ton age ?";
	std::cin >> age;

	std::cin.ignore();

	std::string prenom;
	std::cout << "Quel est ton prenom ?";
	getline(std::cin, prenom);

	double pi;
	std::cout << "Combien vaut pi ?";
	std::cin >> pi;
	
	int & ref_age(age);

	std::cout << "Hello " << prenom << " tu as " << ref_age << " ans." <<std::endl;
	std::cout << "Tu pense que pi = " << pi <<std::endl;

	pi = 3.14159;

	std::cout << "En fait la vrai value de pi est " << pi <<std::endl;

	std::cout <<std::endl;
	std::cout << "Exemple d'affectations de CPP" <<std::endl;

	int a(4), b(5); //Déclaration de deux variables

	std::cout << "a vaut : " << a << " et b vaut : " << b <<std::endl;

	std::cout << "Affectation !" <<std::endl;
	a = b; //Affectation de la valeur de 'b' à 'a'.

	std::cout << "a vaut : " << a << " et b vaut : " << b << std::endl;

	b = 42;

	std::cout << "a vaut : " << a << " et b vaut : " << b << std::endl;
	

	return 0;

}
```

## Les pointeurs en C++

```cpp
#include <iostream>
#include <string>

int main()
{
   int ageUtilisateur(16);
   int *ptr(0);  

	ptr= &ageUtilisateur;
	
	std::cout << "La valeur est :  " << *ptr << std::endl;   

	int *pointeur(0);
	pointeur = new int;
	if (pointeur == nullptr)
	{
		return 0;
	}

	*pointeur = 42;
	std::cout << "La valeur est :  " << *pointeur << std::endl;   

	delete pointeur;
	pointeur = 0;

	int value;

	value = 37;

	std::cout << "           value = " << value << std::endl;
	std::cout << "adresse de value = " << &value << std::endl;

	int *ptr_value(&value);
	std::cout << "adresse de value = " << ptr_value << std::endl;

	int &ref_value(value);
	std::cout << "           value = " << ref_value << std::endl;
	std::cout << "           value = " << *ptr_value << std::endl;

   return 0;
}
```

## Les tableaux simples en C++

```cpp
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

double calculate_mean(double tab[], int size)
{
	double total(0);
	int	i;

	for (i = 0; i < size ;++i)
	{
		total += tab[i];
		std::cout << i << std::endl;
	}

	return total / size;
}

double calculate_mean2(std::vector<int>& tableau)
{
	unsigned int i(0);
	int total(0);

	for (i = 0; i < tableau.size(); i++)
	{
		total += tableau[i];
	}

	total /= tableau.size();

	std::cout << "moyenne = " << total <<std::endl;

	return total;

}

int main ()
{
	double moyenne(0);
	double tab[5];
	int    i;

	i = 5;
	tab[0] = 3.14159;
	tab[1] = -1;
	tab[2] = 0;
	tab[3] = 1;
	tab[4] = 2.71828;

	moyenne = calculate_mean(tab, i);

	std::cout << moyenne <<std::endl;

	std::vector<int> tableau(5, 3);

	std::cout << "tableau[1] = " << tableau[1] <<std::endl;

	tableau.push_back(8);
	tableau.push_back(42000);
	tableau.push_back(8);

	std::cout << "tableau[5] = " << tableau[5] <<std::endl;

	int taille(tableau.size());
	std::cout << "size tableau = " << taille <<std::endl;
	tableau.pop_back();

	taille = tableau.size();
	std::cout << "size tableau = " << taille <<std::endl;

	calculate_mean2(tableau);

	return 0;
}
```

## Les containers

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main ()
{

	std::vector<std::vector<int> > matrix;

	matrix.push_back(std::vector<int>(5,0));
	matrix.push_back(std::vector<int>(5,0));
	matrix.push_back(std::vector<int>(5,0));
	matrix.push_back(std::vector<int>(4,0));

	matrix[3].push_back(42);
	
	std::cout << matrix[3][4] << std::endl;
	std::cout << matrix[1][4] << std::endl;

	matrix[1][4] = 42;

	std::cout << matrix[1][4] << std::endl;
	std::cout << matrix.size() << std::endl;

   std::string prenom("Albert"); 
   std::string nom("Einstein");
   
   std::string total;    //Une chaîne vide
   total += prenom; //On ajoute le prénom à la chaîne vide
   total += " ";    //Puis un espace
   total += nom;    //Et finalement le nom de famille

   std::cout << "Vous vous appelez " << total << "." << std::endl; 

	return 0;
}
```

## Lire et ecrire dans un fichier en C++

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main ()
{
	std::string line_to_add;									//Declaration de la variable de type str

	std::cout << "Ecrivez quelque chose :" <<std::endl;			//Affichage d'une phrase dans le terminal console OUT

	std::getline(std::cin, line_to_add);						//stocke du flux de la console dans line_to_add

	std::string nomFichier("learn.txt");						//Declaration de la variable str nomFichier
	std::ofstream monFlux(nomFichier.c_str(), std::ios::app);	//Declaration de l'objet monFlux qui permet de rediriger le flux vers le fichier nomFichier
																														//ios::app signifie append, il s'agit d'ajouter la ligne a la fin du fichier
																

	if (monFlux)
	{
		monFlux << line_to_add <<std::endl;
	}

	monFlux.close();											//fermeture du flux pour ecrire
/*--------------------------------------------------------------------------------------------*/
	std::ifstream inFile(nomFichier.c_str());					//Declaration de la variable inFile qui contient un objet ifstream
	int pos_caract(0);

	if (inFile)
	{
		while (std::getline(inFile, line_to_add))				//Lecture de la ligne pour la copier dans line_to_add
		{
			std::cout << line_to_add;							//Affichage de la ligne lue
			pos_caract = inFile.tellg();
			std::cout << " | Position du curseur : " << pos_caract << std::endl;				//Affichage de la ligne lue
			
		}
		//pos_caract = inFile.seekg(12, std::ios::end);
		std::cout << "Position du curseur : " << pos_caract << std::endl;				//Affichage de la ligne lue

	}


	return 0;
}
```
## Sources
[FAQ C++, le club des développeurs et IT Pro](https://cpp.developpez.com/faq/cpp/?page=Conversions)
