#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Classe de base
class Pokemon {
protected:
    string nom;
    double poids;

public:
    Pokemon(string n, double p) : nom(n), poids(p) {}

    virtual double vitesse() const = 0; // méthode abstraite
    virtual string toString() const = 0; // méthode abstraite

    virtual ~Pokemon() {} // destructeur virtuel
};

// Pokémons sportifs
class PokemonSportif : public Pokemon {
private:
    int nbPattes;
    double taille; // en mètres
    int frequenceCardiaque;

public:
    PokemonSportif(string n, double p, int nbP, double t, int freq) 
        : Pokemon(n, p), nbPattes(nbP), taille(t), frequenceCardiaque(freq) {}

    double vitesse() const override {
        return nbPattes * taille * 3;
    }

    string toString() const override {
        ostringstream oss;
        oss << "Pokemon Sportif - Nom: " << nom << ", Poids: " << poids << " kg, "
            << "Nombre de pattes: " << nbPattes << ", Taille: " << taille << " m, "
            << "Fréquence cardiaque: " << frequenceCardiaque << " bpm, "
            << "Vitesse: " << vitesse() << " m/s";
        return oss.str();
    }
};

// Pokémons casaniers
class PokemonCasanier : public Pokemon {
private:
    int nbPattes;
    double taille;
    int heuresTV;

public:
    PokemonCasanier(string n, double p, int nbP, double t, int hTV) 
        : Pokemon(n, p), nbPattes(nbP), taille(t), heuresTV(hTV) {}

    double vitesse() const override {
        return nbPattes * taille * 3;
    }

    string toString() const override {
        ostringstream oss;
        oss << "Pokemon Casanier - Nom: " << nom << ", Poids: " << poids << " kg, "
            << "Nombre de pattes: " << nbPattes << ", Taille: " << taille << " m, "
            << "Heures TV/jour: " << heuresTV << ", "
            << "Vitesse: " << vitesse() << " m/s";
        return oss.str();
    }
};

// Pokémons des mers
class PokemonMer : public Pokemon {
private:
    int nbNageoires;

public:
    PokemonMer(string n, double p, int nbN) 
        : Pokemon(n, p), nbNageoires(nbN) {}

    double vitesse() const override {
        return (poids / 25.0) * nbNageoires;
    }

    string toString() const override {
        ostringstream oss;
        oss << "Pokemon de Mer - Nom: " << nom << ", Poids: " << poids << " kg, "
            << "Nombre de nageoires: " << nbNageoires << ", "
            << "Vitesse: " << vitesse() << " m/s";
        return oss.str();
    }
};

// Pokémons de croisière
class PokemonCroisiere : public Pokemon {
private:
    int nbNageoires;

public:
    PokemonCroisiere(string n, double p, int nbN) 
        : Pokemon(n, p), nbNageoires(nbN) {}

    double vitesse() const override {
        return ((poids / 25.0) * nbNageoires) / 2.0;
    }

    string toString() const override {
        ostringstream oss;
        oss << "Pokemon de Croisière - Nom: " << nom << ", Poids: " << poids << " kg, "
            << "Nombre de nageoires: " << nbNageoires << ", "
            << "Vitesse: " << vitesse() << " m/s";
        return oss.str();
    }
};

// Programme principal
int main() {
    PokemonSportif sportif("PikaSport", 10, 4, 0.5, 120);
    PokemonCasanier casanier("Relaxachu", 8, 2, 0.6, 6);
    PokemonMer mer("Aquali", 12, 6);
    PokemonCroisiere croisiere("Navikachu", 20, 8);

    cout << sportif.toString() << endl << endl;
    cout << casanier.toString() << endl << endl;
    cout << mer.toString() << endl << endl;
    cout << croisiere.toString() << endl;

    return 0;
}
