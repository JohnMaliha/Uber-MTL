#include<iostream>
#include <string>
#include<vector>
#include<fstream>
#include <sstream>

#include "Graph.h"
#include"Arrondissement.h"
#include "Chemin.h"
#include"Coordonne.h"
#include"Requete.h"
#include"RequeteUnique.h"

using namespace std;

const string& arrondissement = "arrondissements.txt";
const string& requetesFic = "requetes.txt"; 

int main() {

	Graph graphe;	
	Requete requete; 

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
			requete.LireRequete(requetesFic); 
			requete.traiterRequetes(); 

			break; 

		case 'd':
			cout << "Au revoir!" << endl;
			cin.clear();
			break;
		

		default : 

			//cin.clear(); 
			string cmp; 
			getline(cin, cmp); 
			//cout << cmp; 
			if (cmp == "uitter" ) {

				cout << "Au revoir!" << endl;
				exit(-1); // force un quit. 
				cin.clear();

			}
			else {
				cout <<endl << "Veuillez selectionner une valeur permise. " << endl << endl;
				
			}
		}
	}               
	while (value != 'd' || !getline(cin, quitter) ); // verifie si on a d ou quitter. 
	cin.clear(); 


	//=======================Affichage====================================//


	return 0;
}



