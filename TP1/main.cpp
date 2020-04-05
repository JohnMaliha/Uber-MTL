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
		cout << " a- Mettre � jour la carte. " << endl << " b- D�terminer le plus court chemin s�curitaire. " << endl
			<< " c- Traiter les requ�tes." << endl << " d- Quitter " << endl << " Veuillez indiquer une option : " << endl;
		

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
			break;
		

		default : 

			cin.clear(); 
			string cmp; 
			getline(cin, cmp); 

			if (cmp == "uitter" ) {

				cout << "Au revoir!" << endl;
				exit(-1); // force un quit. 
				cin.clear();

			}
			else {
				cout << "Veuillez selectionner une valeur permise. " << endl << endl;
				
			}
		}
	}               
	while (value != 'd' || !getline(cin, quitter) ); // verifie si on a d ou quitter. 
	cin.clear(); 


	//=======================Affichage====================================//


	return 0;
}



