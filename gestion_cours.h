#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
// Classe Date
class Date {
    int annee;
    int mois;
    int jour;
public:
    Date(int a, int m, int j);
    Date operator+(int jours) const;
    bool operator==(const Date& autre) const;
    bool operator!=(const Date& autre) const;
    bool operator<(const Date& autre) const;
    bool operator>(const Date& autre) const;
    bool operator<=(const Date& autre) const;
    bool operator>=(const Date& autre) const;
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};
// Classe Professeur
class Professeur {
public:
    std::string nom;
    std::string specialisation;
    int experience;
    Professeur(std::string n, std::string s, int e);
    bool operator==(const Professeur& autre) const;
    bool operator!=(const Professeur& autre) const;
    friend std::ostream& operator<<(std::ostream& os, const Professeur& prof);
};
// Classe Cours
class Cours {
public:
    std::string nomCours;
    Professeur* enseignant;
    std::vector<std::string> etudiants;
    Date dateDebut;

    Cours(std::string nom, Professeur* prof, Date date);
    bool operator==(const Cours& autre) const;
    bool operator!=(const Cours& autre) const;
    void ajouterEtudiant(const std::string& etudiant);
    void afficherEtudiants() const;
    friend std::ostream& operator<<(std::ostream& os, const Cours& cours);
};
// Classe Ecole
class Ecole {
public:
   string nomEcole;
    vector<Cours> cours;
    vector<Professeur> professeurs;

    Ecole(std::string nom);
    void ajouterCours(const Cours& nouveauCours);
    void ajouterProfesseur(const Professeur& nouveauProfesseur);
    void afficherCoursEtProfesseurs() const;
    int nombreTotalEtudiants() const;
    void supprimerCours(const std::string& nomCoursASupprimer);
    friend std::ostream& operator<<(std::ostream& os, const Ecole& ecole);
};

bool estProfesseurAssigne(const Cours& cours, const Professeur& professeur);
void afficherProfesseursMoinsDe10Ans(const Ecole& ecole);
bool estProfesseurDisponible(const Ecole& ecole, const Professeur& professeur);
Cours* trouverCoursAvecPlusEtudiants(Ecole& ecole);

void afficherMenuPrincipal();
void afficherMenuCours();
void afficherMenuProfesseurs();
void afficherMenuEcole(Ecole& ecole);

