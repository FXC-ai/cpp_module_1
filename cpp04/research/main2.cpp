#include <iostream>

class Vehicule
{
    public:
     void affiche() const;  

    protected:
    int m_prix;  
};

class Voiture : public Vehicule 
{
    public:
     void affiche() const;

    private:
    int m_portes;  
};

class Moto : public Vehicule  
{
    public:
     void affiche() const;
 
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