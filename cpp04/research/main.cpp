#include <iostream>
#include <vector>

class Vehicule
{
    public:
        Vehicule();
        Vehicule(int prix);
        virtual void affiche() const;
        virtual ~Vehicule();

    protected:
        int m_prix;
};

class Voiture : public Vehicule
{
    public:
        Voiture();
        Voiture(int prix, int portes);
        virtual void affiche() const;
        virtual ~Voiture();

    private:
        int m_portes;
};

class Moto : public Vehicule
{
    public:
        virtual void affiche() const;
        Moto();
        Moto(int prix, double vitesse);
        virtual ~Moto();
        
    private:
        double m_vitesse;
};

Vehicule::Vehicule(){}

Vehicule::Vehicule(int prix) : m_prix(prix){}

Vehicule::~Vehicule()
{
    std::cout << "Vehicule destructor called" << std::endl;
}

Voiture::Voiture(){}

Voiture::Voiture(int prix, int portes) : Vehicule(prix)
{
    this->m_portes = portes;

}

Voiture::~Voiture()
{
    std::cout << "Voiture destructor called" << std::endl;
}

void Vehicule::affiche() const
{
    std::cout << "Ceci est un vehicule." << std::endl;;
}

void Voiture::affiche() const
{
    std::cout << "Ceci est une voiture avec " << this->m_portes << " portes." << std::endl;;
}

Moto::Moto(){}

Moto::Moto(int prix, double vitesse) : Vehicule(prix)
{
    this->m_vitesse = vitesse;
}

void Moto::affiche() const
{
    std::cout << "Ceci est une moto capable de rouler a " << this->m_vitesse <<std::endl;;
}

Moto::~Moto()
{
    std::cout << "Moto destructor called" << std::endl;
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
    
    std::vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000, 5));
    listeVehicules.push_back(new Voiture(12000, 3));
    listeVehicules.push_back(new Moto(2000, 212.5));  

    listeVehicules[0]->affiche();
    //On affiche les informations de la première voiture
    
    listeVehicules[2]->affiche();
    //Et celles de la moto
    std::cout << "\n";

    for(int i(0); i<listeVehicules.size(); ++i)
    {
        delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }
    

    return 0;
}
