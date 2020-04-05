#include<iostream>
#include <string>
#include<vector>
#include<fstream>
#include <sstream>

#include "Graph.h"
#include"Arrondissement.h"
#include "Chemin.h"
#include"Coordonne.h"
using namespace std;

const string& arrondissement = "arrondissements.txt";
const string& requetes = "requetes.txt"; 

int main() {

	Graph graphe;

	//=======================Affichage====================================//
	//controle
	char value = { }; 
	string quitter = "Quitter"; 

	//Menu
	cin.clear();
	cout << endl << "Bienvenu sur POLY Uber " << endl << endl;

	do {

		cout << endl << " ----------------------- MENU -------------------------------------------------------------" << endl << endl;
		cout << " a- Mettre à jour la carte. " << endl << " b- Déterminer le plus court chemin sécuritaire. " << endl
			<< " c- Traiter les requêtes." << endl << " d- Quitter " << endl << " Veuillez indiquer une option : " << endl;
		

		cin >> value;
		switch (value){

		case 'a':
			cout << "Lecture nouvelle carte : ";

			//graphe.CreerGraphe(arrondissement);
			graphe.AfficherGraphe();
			break;

		case 'b':

			cout << "Plus court chemin securitaire : " << endl;
			cin.clear();
			cin.get();
			cout << "Veillez indiquer un point de depart (de 1 a 19) : ";

			int orig, dest;
			cin >> orig;
			cout << "Veuillez indiquer un point d'arriver: ";
			cin >> dest;
			graphe.CreerGraphe(arrondissement);  // reinitialisation.
			graphe.plusCourtChemin(orig, dest);
			cin.clear();
			break;


		case 'c':
			cout << "Traiter les requetes : " << endl;
			graphe.CreerGraphe(arrondissement);  // reinitialisation. 


			break; 

		case 'd':
			cout << "Au revoir!" << endl;
			cin.clear();
			exit(EXIT_FAILURE);
			break;

		default : 
			cout << "Au revoir!" << endl;
			exit(EXIT_FAILURE); // force un quit. 
			break; 
			
		}
	}               
	while (value != 'd' && getline(cin, quitter)); // verifie si on a d ou quitter. 



	//=======================Affichage====================================//


	return 0;
}

/*
// ===============================Algo Dijks==========================//

Graph graphe;
graphe.remplirListeArrondissements;
graphe.remplirListeChemins;


afficherGraphe(graphe);
plusCourtChemin(graphe.liste_chemins);
traiterRequetes();
*/

// ===============================Algo Dijks==========================// 




// ===============================Algo Dijks==========================// 





/*

//========================Lecture=======================// 
//Fonction pour la lecture 
void lireFichierPremierePartie(const string& nomFichier)
{

	char separateur = ',';
	string LigneAvecVirgule;
	vector<int> arrondissement;
	vector<int> borne;
	vector<int> ArrondissementBorne;
	vector<int> areteEntreArrondissement;
	string LigneSansVirgule;
	ifstream fichierALire(nomFichier);

	if (fichierALire.fail())
		cout << "Probleme d'ouverture!" << endl;
	else {
		int i = 0;
		while (!ws(fichierALire).eof()) {
			getline(fichierALire, LigneAvecVirgule);
			stringstream ChaineDeCaractere(LigneAvecVirgule);//brise la chaine de caractere
			while (getline(ChaineDeCaractere, LigneSansVirgule, separateur)) {
				ArrondissementBorne.push_back(stoi(LigneSansVirgule));//stoi: convertit string en int
			}
		}
		//stocker les bornes de recharge
		int SizeVector = ArrondissementBorne.size();
		int nbImpairs = 19;
		for (int n = 0; n < nbImpairs; n++) {
			int ElementsImpairs = 2 * n + 1;
			borne.push_back(ArrondissementBorne[ElementsImpairs]);
		}
		for (auto it : borne) {
			cout << it << endl;
		}

		//stocker les arrondissements
		cout << endl << endl;
		int pairs = 19;
		for (int n = 0; n < pairs; n++) {
			int ElementsPairs = 2* n;
			arrondissement.push_back(ArrondissementBorne[ElementsPairs]);
		}
		for (auto it : arrondissement) {
			cout << it << endl;
		}

		//stocker les arrondissements avec les arêtes
		cout << endl << endl;
		int positionDeDepart = 38;
		for (positionDeDepart; positionDeDepart < ArrondissementBorne.size(); positionDeDepart++) {
			areteEntreArrondissement.push_back(ArrondissementBorne[positionDeDepart]);
		}
		for (auto it : areteEntreArrondissement) {
			cout << it << endl;
		}
		fichierALire.close();
	}
}
*/