# CPP03

# Rappel au sujet du modèle coplien

From now on, all your classes must be designed in the Orthodox Canonical Form, unless explicitely stated otherwise. Then, they will implement the four required member functions below:

- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

Split your class code into two files. The header file (.hpp/.h) contains the class definition whereas the source file (.cpp) contains the implementation.

# Precisions au sujet de const

Si on envoie en paramètre à une fonction un objet avec le mot clé const. Il faut absolument que toutes les fonctions que l’on utilise sur cette objet dans la fonction soit également de type constant.

Exemple :

```cpp
std::string	ClapTrap::getName()
{
	return this->_name;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	return *this;
}
```

```cpp
std::string	ClapTrap::getName() const
{
	return this->_name;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs.getName();
	return *this;
}
```

# Surcharge de l’opérateur << pour l’objet ostream

Le prototype de la fonction est :

```cpp
std::ostream &	operator<<(std::ostream& o, class const & i);
```

Exemple d’implémentation de cette surcharge pour un class A :

```cpp
class A
{
	public :
		void display(){return "Je suis un objet de type A."}
}

std::ostream& operator<<(std::ostream& o, A const & i)
{
	o << i.display();
	return o;
}
```

C’est un opérateur binaire :

1. A gauche nous avons une référence sur l’objet ostream
2. A droite une refernce sur un objet

A l’intérieur de la fonction on peut utiliser l’opérateur << sur une variable de type scalaire.

