# CPP01

# Allocation heap VS stack

```cpp
#include <string>
#include <iostream>

class Zombie 
{

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void		announce(void);

	private:
		std::string	_name;

};

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie*	newZomb;

	newZomb = new Zombie(name);

	return newZomb;
}

int main ()
{
	
	Zombie	Victor;
	Zombie	*Christina;

	Victor = Zombie("Victor");

	Christina = newZombie("Christina");

	Christina->announce();
	Victor.announce();

	delete Christina;

	return 0;
}
```

# Allouer un tableau d’objets

```cpp
int main ()
{
	Zombie	Victor;
	Zombie	*Christina;
	Zombie	*Horde;

	Victor = Zombie("Victor");

	Christina = newZombie("Christina");

	Christina->announce();
	Victor.announce();

	Horde = new Zombie[42];

	Horde[2].announce();

	delete Christina;
	delete [] Horde;
	return 0;
}
```

# Les références

 Les références sont :

- Des pointeurs constants
- Toujours déréférencé
- Jamais nuls

## Exemple d’un cas complexe :

```cpp
int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();

	return 0;
}
```

Le main envoie la variable club à la classe HumanB

### Concernant la classe Weapon :

```cpp
class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();
		std::string&	getType();
		void	setType(std::string type);
};

Weapon::Weapon(std::string type) : _type(type){}

Weapon::~Weapon(){}

std::string& Weapon::getType()
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
```

Remarque : ici on envoie une référence de la string avec la fonction getType mais cela fonctionnerait aussi en renvoyant la string elle même.

### Concernant la classe HumanB :

```cpp
class HumanB
{
	private:
		std::string	const	_name;
		Weapon*				_weapon;

	public:
		HumanB(std::string const name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};

HumanB::HumanB (std::string const name) : _name(name) {}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->_name + " attacks with their " + this->_weapon->getType() << std::endl;
}
```

Dans le main on appelle : `jim.setWeapon(club);`

Si toutefois la fonction n’utilisait pas une référence :

```cpp
void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}
```

alors ce serait une copie qui aurait été fourni à l’objet “Jim”. Dés lors les modifications apportés à club dans le main n’aurait une aucune influence sur l’objet Weapon de notre instance de Jim. Une autre façon de l’implémenter aurait été :

```cpp
void	HumanB::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
}

// et dans le main

int main()
{
...
	jim.setWeapon(&club);
...
}
```

# Lire un fichier en C++

[Lire le fichier en chaîne en C++](https://www.delftstack.com/fr/howto/cpp/read-file-into-string-cpp/#utilisez-rdbuf-pour-lire-un-fichier-dans-une-cha%c3%aene-de-caract%c3%a8res-en-c)

```cpp
return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
```

Certainly! This is an idiomatic way in C++ to read an entire file into a `std::string`. The code is constructing a `std::string` from an entire file represented by the `std::ifstream` object named `input_file`.

Let's break it down:

- `std::istreambuf_iterator<char>(input_file)`: This creates an input stream buffer iterator that reads `char` types from the input stream `input_file`. The iterator behaves somewhat like a pointer, pointing to individual characters in the buffer associated with `input_file`.
- The expression `std::istreambuf_iterator<char>()` (with no arguments) creates a special "end" iterator. It doesn't point to any valid character, it's a marker that signifies the end of the stream.
- `std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>())`: This constructs a `std::string` using the range specified by the two iterators. In essence, it reads every character from `input_file` and puts them into a `std::string`.

So, the entire line reads the entire contents of `input_file` into a `std::string`, and returns that string. The file is read as a sequence of `char`, so it doesn't matter what the file's contents are - it could be text, or binary data.

Keep in mind that error handling is not addressed here, and the file needs to be open before this line is executed, otherwise it will result in undefined behavior.

# A propos des maps

```cpp
#include <map>
#include <string>
#include <iostream>

int main ()
{
	std::map<std::string, int> listest;

	listest["a"] = 2;
	listest["b"] = 4;

	std::cout << listest["FX"] << std::endl;

	std::map<std::string, int>::iterator it;

	for (it = listest.begin(); it != listest.end(); it++)
	{
		std::cout << it->first << std::endl;
	}

	return (0);
}
```