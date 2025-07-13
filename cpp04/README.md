# CPP04

# Resolution statique des liens

Le problème apparait quand on “cast” un objet dans un emplacement mémoire de type “parent”.

## Cas 1 :

```cpp
#include <iostream>

class Vehicule
{
    public:
     void affiche() const;  //Affiche une description du Vehicule

    protected:
    int m_prix;  //Chaque véhicule a un prix
};

class Voiture : public Vehicule //Une Voiture EST UN Vehicule
{
    public:
     void affiche() const;

    private:
    int m_portes;  //Le nombre de portes de la voiture
};

class Moto : public Vehicule  //Une Moto EST UN Vehicule
{
    public:
     void affiche() const;
 
    private:
    double m_vitesse;  //La vitesse maximale de la moto
};

void Vehicule::affiche() const
{
    std::cout << "Ceci est un vehicule." << std::endl;;
}

void Voiture::affiche() const
{
    std::cout << "Ceci est une voiture." << std::endl;;
}

void Moto::affiche() const
{
    std::cout << "Ceci est une moto." << std::endl;;
}

void presenter(Vehicule v)
{
	v.affiche();
}

int main()
{
	Vehicule Vehicule0;
	Moto    Moto0;
	Voiture Voiture0;

    Vehicule Vehicule;

	Vehicule0.affiche();
	Moto0.affiche();
	Voiture0.affiche();

	presenter(Moto0);

	return 0;
}
```

On obtient l’output suivant :

Ceci est un vehicule.
Ceci est une moto.
Ceci est une voiture.
Ceci est un vehicule.

## Cas 2 :

```cpp
#include <iostream>

class Vehicule
{
    public:
    virtual void affiche() const;

    protected:
    int m_prix; 
};

class Voiture : public Vehicule 
{
    public:
    virtual void affiche() const;

    private:
    int m_portes;
};

class Moto : public Vehicule 
{
    public:
    virtual void affiche() const;
 
    private:
    double m_vitesse;
};

void Vehicule::affiche() const
{
    std::cout << "Ceci est un vehicule." << std::endl;;
}

void Voiture::affiche() const
{
    std::cout << "Ceci est une voiture." << std::endl;;
}

void Moto::affiche() const
{
    std::cout << "Ceci est une moto." << std::endl;;
}

void presenter(Vehicule const& v)
{
	v.affiche();
}

void presenter_avec_un_pointeur(Vehicule const* v)
{
	v->affiche();
}

int main()
{
	Vehicule Vehicule0;
	Moto    Moto0;
	Voiture Voiture0;

  Vehicule Vehicule;

	Vehicule0.affiche();
	Moto0.affiche();
	Voiture0.affiche();

	presenter(Moto0);
	presenter_avec_un_pointeur(&Moto0);

	return 0;
}
```

On obient l’output suivant :

Ceci est un vehicule.
Ceci est une moto.
Ceci est une voiture.
Ceci est une moto.
Ceci est une moto.

## Explications

Pour résoudre le problème il faut envoyer une reference à la fonction afficher et il faut mettre la fonction afficher() en virtual. Cela fonctionne aussi avec les pointeurs.
