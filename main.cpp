#include "gestion_cours.h"

int main() {
    Ecole monEcole("Emsi");
    Professeur prof1("Mme.ELKORCHI", "IT", 3);
    Professeur prof2("Mr.Rachid", "RS", 5);
    Professeur prof3("Mme.fatima zharae","DB",8);
    monEcole.ajouterProfesseur(prof1);
    monEcole.ajouterProfesseur(prof2);
    monEcole.ajouterProfesseur(prof3);
    Date date1(2022,01,05);
    Date date2(2020,05,04);
    Date date3(2017,10,15);
    Cours cours1("POO", &prof1, date1);
    cours1.ajouterEtudiant("Salah");
    cours1.ajouterEtudiant("ayoub");
    Cours cours2("Resaux",&prof2,date2);
    cours2.ajouterEtudiant("haroune");
    cours2.ajouterEtudiant("anas");
     Cours cours3("BD",&prof3,date2);
     cours3.ajouterEtudiant("Mohamed");
    cours3.ajouterEtudiant("Ilyas");
     
    monEcole.ajouterCours(cours1);
    monEcole.ajouterCours(cours2);
    monEcole.ajouterCours(cours3);

    int choixPrincipal;
    do {
        afficherMenuPrincipal();
        cin >> choixPrincipal;
        cout << "****************************************" << endl;  
        switch (choixPrincipal) {
        	// Gestion des Cours
            case 1: { 
                int choixCours;
                do {
                    afficherMenuCours();
                    cin >> choixCours;
                    cout << "****************************************" << endl;  
                    switch (choixCours) {
					// Ajouter un cours
                        case 1: { 
                            string nomCours;
                            string nomProf;
                            int jour, mois, annee;
                            cout << "Nom du cours : ";
                            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                            getline(std::cin, nomCours);
                            cout << "Nom du professeur : ";
                            getline(std::cin, nomProf);
                            cout << "Date de debut (jj mm aaaa) : ";
                            cin >> jour >> mois >> annee;
                            Professeur* profTrouve = nullptr;
                            for (auto& p : monEcole.professeurs) {
                                if (p.nom == nomProf) {
                                    profTrouve = &p;
                                    break;
                                }
                            }
                            if (profTrouve) {
                                Date dateDebut(annee, mois, jour);
                                Cours nouveauCours(nomCours, profTrouve, dateDebut);
                                monEcole.ajouterCours(nouveauCours);
                                cout << "\n---------------------------------------" <<endl; 
								cout << "Cours ajoute." << endl;
                                cout << "---------------------------------------" << endl; 
                            } else {
                            	cout << "\n---------------------------------------" << endl; 
                                cout << "Professeur non trouve." << endl;
                                cout << "---------------------------------------" << endl; 
                            }
                            break;  
                        }
						// Supprimer un cours
                        case 2: {
                            string nomCours;
                            cout << "Nom du cours a supprimer : ";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(std::cin, nomCours);
                            monEcole.supprimerCours(nomCours);
                            cout << "\n---------------------------------------" << endl; 
                            cout << "Cours supprime (si existant)." << endl;
                            cout << "---------------------------------------" << endl; 
                            break;
                        }
						// Afficher les étudiants d'un cours
                        case 3: {
                            string nomCours;
                            cout << "Nom du cours dont vous souhaitez afficher les etudiants : ";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(std::cin, nomCours);
                            bool coursTrouve = false;
                            for (const auto& c : monEcole.cours) {
                                if (c.nomCours == nomCours) {
                                	cout << "\n---------------------------------------" << endl;
                                    c.afficherEtudiants();
                                    cout << "---------------------------------------" << endl;
                                    coursTrouve = true;
                                    break;
                                }
                            }
                            if (!coursTrouve) {
                            	cout << "\n---------------------------------------" << endl;
                                cout << "Cours non trouve." << endl;
                                cout << "---------------------------------------" << endl;
                            }
                            break;
                        }
                        case 4:
                            break;
                        default:
                        	cout << "\n---------------------------------------" << endl;
                            cout << "Choix invalide." << endl;
                            cout << "---------------------------------------" << endl;
					}
                } while (choixCours != 4);
                break;
            }
            // Gestion des Professeurs
            case 2: { 
                int choixProfesseurs;
                do {
                    afficherMenuProfesseurs();
                    cin >> choixProfesseurs;
					cout << "*****************************************************************" << endl;
                    switch (choixProfesseurs) {
                        case 1: { // Ajouter un professeur
                            string nomProf, specialisationProf;
                            int experienceProf;
                            cout << "Nom du professeur : ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(std::cin, nomProf);
                            cout << "Specialisation : ";
                            getline(std::cin, specialisationProf);
                            cout << "Annees d'expérience : ";
                            cin >> experienceProf;
                            Professeur nouveauProf(nomProf, specialisationProf, experienceProf);
                            monEcole.ajouterProfesseur(nouveauProf);
                            cout << "\n---------------------------------------" << endl;
                            cout << "Professeur ajoute." << endl;
                            cout << "---------------------------------------" << endl;
                            break;
                        }
                        // Afficher les professeurs avec moins de 10 ans d'expérience
                        case 2: 
                        	cout << "\n--------------------------------------------------------------" << endl;
                            afficherProfesseursMoinsDe10Ans(monEcole);
                            cout << "----------------------------------------------------------------" << endl;
                            break;
						//Vérifier la disponibilité d'un professeur
                        case 3: {
                            string nomProf;
                            cout << "Nom du professeur a verifier : ";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(std::cin, nomProf);
                            Professeur profRecherche(nomProf,"",0);
                            if (estProfesseurDisponible(monEcole,profRecherche)){
                            	cout << "\n---------------------------------------" << endl;
                                cout << "Le professeur est disponible." << std::endl;
                                cout << "---------------------------------------" << endl;
                            }
							else{
								cout << "\n---------------------------------------" << endl;
                                cout << "Le professeur n'est pas disponible." <<endl;
                            	cout << "---------------------------------------" << endl;
							}
                            break;
                        }
                        case 4:
                            break;
                        default:
                        	cout << "\n---------------------------------------" << endl;
                            cout << "Choix invalide." << endl;
                            cout << "---------------------------------------" << endl;
                    }
                } while (choixProfesseurs != 4);
                break;
            }
			//Informations sur l'école
            case 3: {
                int choixEcole;
                do {
                    afficherMenuEcole(monEcole);
                    cin >> choixEcole;
					cout << "************************************************" << endl;
                    switch (choixEcole) {
                    	// Afficher les cours et les professeurs
                        case 1: 
                        	cout << "\n--------------------------------------------------------------------------------------------------------------" << endl;
                             monEcole.afficherCoursEtProfesseurs();
                       		cout << "--------------------------------------------------------------------------------------------------------------" << endl;
                            break;
                        // Calculer le nombre total d'étudiants    
                        case 2: 
                        	cout << "\n---------------------------------------" << endl;
                            cout << "Nombre total d'etudiants : " << monEcole.nombreTotalEtudiants() << endl;
                            cout << "---------------------------------------" << endl;
							break;
						// Trouver le cours avec le plus d'étudiants	
                        case 3: {
                            Cours* coursMax = trouverCoursAvecPlusEtudiants(monEcole);
                            if (coursMax) {
                            cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "Le cours avec le plus d'etudiants est : " << *coursMax << std::endl;
                                coursMax->afficherEtudiants();
                                cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            } else {
                            	cout << "\n---------------------------------------" << endl;
                                cout << "Aucun cours enregistre." << endl;
                                cout << "\n---------------------------------------" << endl;
                            }
                            break;
                        }
                        case 4:
                            break;
                        default:
                        	cout << "\n---------------------------------------" << endl;
                            cout << "Choix invalide." << endl;
                            cout << "---------------------------------------" << endl;
                    }
                } while (choixEcole != 4);
                break;
            }
            case 4:
            	
            	cout << "\n   -|------------------------|-" << endl;
            	cout << "    |\t                     |" << std::endl;
                cout << "    |\tProgramme termine    |" << std::endl;
                cout << "    |\t                     |" << std::endl;
                cout << "   -|------------------------|-" << endl;
                break;
            default:
                cout << "\n---------------------------------------" << endl;
                cout << "Choix invalide." << endl;
                cout << "---------------------------------------" << endl;
        }
    } while (choixPrincipal != 4);
    return 0;
}