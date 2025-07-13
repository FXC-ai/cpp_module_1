# CPP02

# A propos de la surcharge operator+

Dans votre question, vous avez donné deux signatures différentes pour la fonction de surcharge de l'opérateur `+`:

- `Fixed operator+(Fixed const &rhs);`
- `Fixed& operator+(Fixed const &rhs);`

La différence entre ces deux signatures se trouve dans le type de valeur retourné par la fonction.

1. `Fixed operator+(Fixed const &rhs);` renvoie une nouvelle instance de `Fixed` par valeur. Cela signifie qu'une copie de l'objet est effectuée lorsque la fonction est appelée et que cette copie est renvoyée à l'appelant. C'est généralement approprié pour la surcharge d'opérateurs comme `+`, car ces opérateurs ne modifient généralement pas les objets originaux, mais créent plutôt une nouvelle valeur basée sur ces objets.
2. `Fixed& operator+(Fixed const &rhs);` renvoie une référence à une instance de `Fixed`. Cela signifie que la fonction ne fait pas une nouvelle copie de l'objet, mais renvoie plutôt une référence à un objet existant. Ce prototype n'est généralement pas approprié pour la surcharge de l'opérateur `+`, car cela impliquerait que l'opérateur modifie l'un des objets d'origine (ce qui n'est généralement pas le comportement attendu pour l'opérateur `+`).

Par conséquent, votre signature originale (`Fixed operator+(Fixed const &rhs);`) est probablement la plus appropriée pour ce que vous essayez de faire. De plus, si vous optez pour le prototype renvoyant une référence (`Fixed& operator+(Fixed const &rhs);`), vous risquez de renvoyer une référence à un objet qui a été détruit (c'est-à-dire que l'objet "result" dans votre implémentation serait détruit une fois la fonction terminée, ce qui entraînerait un comportement indéfini si vous essayez d'utiliser la valeur renvoyée par l'opérateur `+`).

# A propos de la surcharge operator=

Pour la surcharge de cette opérateur, on utilise le prototype suivant : `Fixed& operator=(Fixed const &rhs);` 

L’objet en paramètre est l’objet à droite du = (Right Hand Side). Il n’est donc pas modifié, c’est pour cela qu’il est envoyé en `const`. 

La fonction peut être mieux comprise en illustrant par cette syntaxe : `operator=(&a, &b);` Elle n’est pas fonctionelle mais elle permet de comprendre.

```cpp
int main()
{
	Fixed a;
	Fixed b(18.2f);

	a = b /*operator=(&a, &b);*/

	return 0;
}
```

# A propos de l’incrementation

Voici un code à executer en C qui montre bien la difference :

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 0;

	printf("i = %d\n", i);
	printf("i = %d\n", i++);
	printf("i = %d\n", i);
	
	printf("\n");

	i = 0;
	printf("i = %d\n", i);
	printf("i = %d\n", ++i);
	printf("i = %d\n", i);

	return 0;
}
```

Output :

i = 0
i = 0
i = 1

i = 0
i = 1
i = 1

i++ ⇒ dans le cas `i++`, on évalue la variable, on incrémente, mais on renvoie la variable *avant incrémentation.* 

Dans le cas de l'opérateur postfixé, on doit:

- faire une copie locale de l'objet
- renvoyer la copie de l'objet, donc impossible de renvoyer une référence.

d'où surcoût (qui  peut ne pas être négligeable,  suivant la taille de
l'objet).  Moralité: utilisez  *toujours* la  version préfixée,
sauf nécessité absolue.

++i ⇒ d’abord on incremente ensuite on lit la variable. Plus simple a recréer dans un objet car il suffit d’ajouter 1 à l’objet en cours.

La distinction entre les deux est que l'opérateur de pré-incrémentation retourne une référence à l'objet incrémenté, tandis que l'opérateur de post-incrémentation retourne une copie de l'objet avant l'incrémentation.

Voici comment vous pourriez le faire:

```cpp
class Fixed
{
    //...

    // Pré-incrémentation
    Fixed& operator++()
    {
        // Implementation...
        return *this;
    }

    // Post-incrémentation
    Fixed operator++(int)
    {
        Fixed temp(*this);
        // Incrementation...
        return temp;
    }

    //...
};
```

L'argument `int` dans `operator++(int)` est juste un paramètre factice utilisé pour différencier le pré-incrément et le post-incrément. Il n'a pas de valeur réelle et ne doit pas être utilisé dans la fonction.

# A propos des fonctions membres statiques

En déclarant une fonction membre comme statique, vous la rendez indépendante de tout objet particulier de la classe. Une fonction membre statique peut être appelée même s'il n'y a pas d'objets de la classe. 
Les fonctions statiques sont accessibles uniquement à l'aide du nom de la classe et de l'opérateur de résolution de portée "**::**".

Une fonction membre statique ne peut accéder qu’à un membre de données statique, à d’autres fonctions membres statiques et à toute autre fonction extérieure à la classe.

Les fonctions membres statiques ont une portée de classe et elles n'ont pas accès au pointeur **this** de la classe. Vous pouvez utiliser une fonction membre static pour déterminer si certains objets de la classe ont été créés ou non.

```cpp
#include <iostream>
using namespace std;
 
class Voiture
{
private:
    int Id;
    double Vitesse;
 
public:
    static int nbVoitures;
    Voiture();
    static int getNombreObjets();
};
 
int Voiture::nbVoitures = 0;
int Voiture::getNombreObjets()
{
    return nbVoitures;
}
 
Voiture::Voiture()
{
    Id = 1;
    Vitesse = 240;
    nbVoitures += 1;
}
 
int main()
{
    Voiture v1, v2, v3, v4;
    cout << "Nombre d'objets : " << Voiture::getNombreObjets() << endl;
    return 0;
}
```

# Sources

[Point à l'intérieur d'un triangle ? - Algorithmes et structures de données](https://www.developpez.net/forums/d3690/general-developpement/algorithme-mathematiques/algorithmes-structures-donnees/point-l-interieur-d-triangle/)

[Les flottants ou comment représenter les nombres réels en machine ?](https://www.redlab.io/le-monde-merveilleux-des-flottants/)

[Introduction to Fixed Point Number Representation](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)

[Utiliser la méthode du complément à 2 en binaire - Maxicours](https://www.maxicours.com/se/cours/utiliser-la-methode-du-complement-a-2-en-binaire/)

[Tutoriel : Maîtrisez les nombres à virgule en C](http://sdz.tdct.org/sdz/maitrisez-les-nombres-a-virgule-en-c.html)

[Surcharge d'opérateurs d'incrémentation et de décrémentation (C++)](https://learn.microsoft.com/fr-fr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170)

[Surcharger fonctions et opérateurs](https://www.calmip.univ-toulouse.fr/c++/surch.html)

[C++ Static Const Member Variable](https://cookierobotics.com/032/)
