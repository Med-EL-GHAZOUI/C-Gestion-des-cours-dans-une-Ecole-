#include "gestion_cours.h"

Date::Date(int a, int m, int j) : annee(a), mois(m), jour(j) {}
// Surcharge de l'opérateur +
Date Date::operator+(int jours) const {
    Date nouvelleDate = *this;
    nouvelleDate.jour += jours;
    return nouvelleDate; // Implémentation à améliorer pour les mois/années
}
// Surcharge de l'opérateur ==
bool Date::operator==(const Date& autre) const {
    return (annee == autre.annee && mois == autre.mois && jour == autre.jour);
}
// Surcharge de l'opérateur !=
bool Date::operator!=(const Date& autre) const {
    return !(*this == autre);
}
// Surcharge de l'opérateur <
bool Date::operator<(const Date& autre) const {
    if (annee != autre.annee) return annee < autre.annee;
    if (mois != autre.mois) return mois < autre.mois;
    return jour < autre.jour;
}
// Surcharge de l'opérateur >
bool Date::operator>(const Date& autre) const {
    return autre < *this;
}
// Surcharge de l'opérateur <=
bool Date::operator<=(const Date& autre) const {
    return !(autre < *this);
}
// Surcharge de l'opérateur >=
bool Date::operator>=(const Date& autre) const {
    return !(*this < autre);
}
// Surcharge de l'opérateur <<
ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.jour << "/" << date.mois << "/" << date.annee;
    return os;
}

Professeur::Professeur(string n, string s, int e) : nom(n), specialisation(s), experience(e) {}
// Surcharge de l'opérateur ==
bool Professeur::operator==(const Professeur& autre) const {
    return (nom == autre.nom);
}
// Surcharge de l'opérateur !=
bool Professeur::operator!=(const Professeur& autre) const {
    return !(*this == autre);
}
// Surcharge de l'opérateur <<
ostream& operator<<(std::ostream& os, const Professeur& prof) {
    os << "Nom: " << prof.nom << ", Specialisation: " << prof.specialisation << ", Experience: " << prof.experience << " ans";
    return os;
}

Cours::Cours(std::string nom, Professeur* prof, Date date) : nomCours(nom), enseignant(prof), dateDebut(date) {}
// Surcharge de l'opérateur ==
bool Cours::operator==(const Cours& autre) const {
    return (nomCours == autre.nomCours);
}
// Surcharge de l'opérateur !=
bool Cours::operator!=(const Cours& autre) const {
    return !(*this == autre);
}

void Cours::ajouterEtudiant(const std::string& etudiant) {
    if (find(etudiants.begin(), etudiants.end(), etudiant) == etudiants.end()) {
        etudiants.push_back(etudiant);
    }
}

void Cours::afficherEtudiants() const {
    cout << "Etudiants inscrits au cours de " << nomCours << ":" << endl;
    if (etudiants.empty()) {
        cout << "Aucun étudiant inscrit pour le moment." << endl;
    } else {
        for (const auto& etudiant : etudiants) {
            cout << "- " << etudiant << endl;
        }
    }
}
// Surcharge de l'opérateur <<
ostream& operator<<(std::ostream& os, const Cours& cours) {
    os << "Cours: " << cours.nomCours << ", Enseignant: " << *cours.enseignant << ", Date de debut: " << cours.dateDebut;
    return os;
}

Ecole::Ecole(string nom) : nomEcole(nom) {}

void Ecole::ajouterCours(const Cours& nouveauCours) {
    if (find(cours.begin(), cours.end(), nouveauCours) == cours.end()) {
        cours.push_back(nouveauCours);
    }
}

void Ecole::ajouterProfesseur(const Professeur& nouveauProfesseur) {
    if (find(professeurs.begin(), professeurs.end(), nouveauProfesseur) == professeurs.end()) {
        professeurs.push_back(nouveauProfesseur);
    }
}

void Ecole::afficherCoursEtProfesseurs() const {
    cout << "Cours de l'ecole :" << nomEcole << ":" << endl;
    if (cours.empty()) {
        cout << "Aucun cours enregistré pour le moment." << endl;
    } else {
        for (const auto& c : cours) {
            cout << c << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Professeurs de l'ecole : " << nomEcole << ":" << endl;
    if (professeurs.empty()) {
        cout << "Aucun professeur enregistré pour le moment." << endl;
    } else {
        for (const auto& p : professeurs) {
            cout << p << endl;
        }
    }
}

int Ecole::nombreTotalEtudiants() const {
    int total = 0;
    for (const auto& c : cours) {
        total += c.etudiants.size();
    }
    return total;
}

void Ecole::supprimerCours(const string& nomCoursASupprimer) {
    cours.erase(remove_if(cours.begin(), cours.end(),[&](const Cours& c){
	 return c.nomCours == nomCoursASupprimer; }),
                cours.end());
}
// Surcharge de l'opérateur <<
ostream& operator<<(std::ostream& os, const Ecole& ecole) {
    os << "Ecole: " << ecole.nomEcole << std::endl;
    return os;
}

bool estProfesseurAssigne(const Cours& cours, const Professeur& professeur) {
    return (*cours.enseignant == professeur);
}

void afficherProfesseursMoinsDe10Ans(const Ecole& ecole) {
    cout << "\nProfesseurs avec moins de 10 ans d'experience :" << endl;
    bool aucunProfesseur = true;
    for (const auto& prof : ecole.professeurs) {
        if (prof.experience < 10) {
           cout << prof << endl;
            aucunProfesseur = false;
        }
    }
    if (aucunProfesseur) {
        cout << "Aucun professeur avec moins de 10 ans d'experience." << endl;
    }
}

bool estProfesseurDisponible(const Ecole& ecole, const Professeur& professeur) {
    return find(ecole.professeurs.begin(), ecole.professeurs.end(), professeur) != ecole.professeurs.end();
}

Cours* trouverCoursAvecPlusEtudiants(Ecole& ecole) {
    if (ecole.cours.empty()) return nullptr;
    Cours* coursMax = &ecole.cours[0];
    for (auto& cours : ecole.cours) {
        if (cours.etudiants.size() > coursMax->etudiants.size()) {
            coursMax = &cours;
        }
    }
    return coursMax;
}

void afficherMenuPrincipal() {
    cout << "\n \tMenu Principal:" << std::endl;
    cout << "****************************************" << endl;
    cout << "* 1. Gestion des Cours                  " << endl;
    cout << "* 2. Gestion des Professeurs            " << endl;
    cout << "* 3. Informations sur l'Ecole           " << endl;
    cout << "* 4. Quitter                            " << endl;
	cout << "****************************************" << endl;  
    cout << "Choix : ";
    
}

void afficherMenuCours() {
	cout << "\n \tMenu Gestion des Cours:" << endl;
    cout << "****************************************" << endl;
    cout << "* 1. Ajouter un cours                   " << endl;
    cout << "* 2. Supprimer un cours                 " << endl;
    cout << "* 3. Afficher les etudiants d'un cours  " << endl;
    cout << "* 4. Retour au menu principal           " << endl;
	cout << "****************************************" << endl;  
    cout << "Choix : ";
}

void afficherMenuProfesseurs() {
	cout << "\n \tMenu Gestion des Professeurs:" << endl;
    cout << "*****************************************************************" << endl;
    cout << "* 1. Ajouter un professeur" << endl;
    cout << "* 2. Afficher les professeurs avec moins de 10 ans d'experience" << endl;
    cout << "* 3. Verifier la disponibilite d'un professeur " << endl;
    cout << "* 4. Retour au menu principal" << endl;
	cout << "*****************************************************************" << endl;  
    cout << "Choix : ";
}

void afficherMenuEcole(Ecole& ecole) {
	cout << "\n \tMenu Informations sur l'Ecole:" << endl;
    cout << "************************************************" << endl;
    cout << "* 1. Afficher les cours et les professeurs" << endl;
    cout << "* 2. Calculer le nombre total d'etudiants      " << endl;
    cout << "* 3. Trouver le cours avec le plus d'étudiants " << endl;
    cout << "* 4. Retour au menu principal" << endl;
	cout << "************************************************" << endl;  
    cout << "Choix : ";
}