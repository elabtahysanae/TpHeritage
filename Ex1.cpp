
#include <iostream>
#include <string>
using namespace std;

// Classe Date
class Date {
private:
    int jour, mois, annee;

public:
    Date(int j = 1, int m = 1, int a = 2000) {
        jour = j;
        mois = m;
        annee = a;
    }

    void afficher() const {
        cout << jour << "/" << mois << "/" << annee;
    }
};

// Classe Equipement
class Equipement {
protected:
    string code;
    Date dateAcquisition;
    bool etat; // true = opérationnel, false = non
    double prixAchat;

public:
    Equipement(string c, bool e) : code(c), etat(e), prixAchat(0) {}

    void setDateAcquisition(Date d) { dateAcquisition = d; }
    void setPrixAchat(double p) { prixAchat = p; }

    void afficher() const {
        cout << "Code: " << code << endl;
        cout << "Date d'acquisition: ";
        dateAcquisition.afficher();
        cout << endl;
        cout << "Etat: " << (etat ? "Opérationnel" : "Non opérationnel") << endl;
        cout << "Prix d'achat: " << prixAchat << " euros" << endl;
    }
};

// Classe Ordinateur
class Ordinateur : public Equipement {
private:
    string marque;
    double tailleEcran;

public:
    Ordinateur(string c, bool e, string m, double t) : Equipement(c, e), marque(m), tailleEcran(t) {}

    void afficher() const {
        Equipement::afficher();
        cout << "Marque: " << marque << endl;
        cout << "Taille écran: " << tailleEcran << " pouces" << endl;
    }
};

// Classe Table
class Table : public Equipement {
private:
    double longueur;
    double largeur;

public:
    Table(string c, bool e, double l, double L) : Equipement(c, e), longueur(l), largeur(L) {}

    void afficher() const {
        Equipement::afficher();
        cout << "Longueur: " << longueur << " m, Largeur: " << largeur << " m" << endl;
    }
};

// Classe Imprimante
class Imprimante : public Equipement {
private:
    string marque;
    string numeroSerie;

public:
    Imprimante(string c, bool e, string m, string n) : Equipement(c, e), marque(m), numeroSerie(n) {}

    void afficher() const {
        Equipement::afficher();
        cout << "Marque: " << marque << endl;
        cout << "Numéro de série: " << numeroSerie << endl;
    }
};

// Programme principal
int main() {
    // Création d'objets
    Ordinateur ordi("ORD123", true, "Dell", 15.6);
    ordi.setDateAcquisition(Date(15, 4, 2022));
    ordi.setPrixAchat(1200);

    Table table("TAB456", false, 2.0, 1.5);
    table.setDateAcquisition(Date(10, 3, 2021));
    table.setPrixAchat(150);

    Imprimante imprimante("IMP789", true, "HP", "SN123456");
    imprimante.setDateAcquisition(Date(20, 6, 2020));
    imprimante.setPrixAchat(300);

    // Affichage
    cout << "\n--- Ordinateur ---" << endl;
    ordi.afficher();

    cout << "\n--- Table ---" << endl;
    table.afficher();

    cout << "\n--- Imprimante ---" << endl;
    imprimante.afficher();

    return 0;
}
