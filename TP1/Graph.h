#pragma once

#include "Chemin.h"
#include "Arrondissement.h"
using namespace std;

class Graph {
	public:
	Graph() {
		
		char separateur = ',';
		string LigneAvecVirgule;
		vector<int> arrondissement;
		vector<int> borne;
		vector<int> ArrondissementBorne;
		vector<int> areteEntreArrondissement;
		string LigneSansVirgule;
		ifstream fichierALire("arrondissements.txt");

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
		

			//stocker les arrondissements
			cout << endl << endl;
			int pairs = 19;
			for (int n = 0; n < pairs; n++) {
				int ElementsPairs = 2 * n;
				arrondissement.push_back(ArrondissementBorne[ElementsPairs]);
			}
			

			for (int i = 0; i < 19; i++) {
				liste_arrondissements[i] = Arrondissement(arrondissement[i], borne[i]);
			}

			//stocker les arrondissements avec les arêtes
			cout << endl << endl;
			int positionDeDepart = 38;
			for (positionDeDepart; positionDeDepart < ArrondissementBorne.size(); positionDeDepart++) {
				areteEntreArrondissement.push_back(ArrondissementBorne[positionDeDepart]);
			}
			

			for (int i = 0; i < areteEntreArrondissement.size(); i += 3) {
				liste_chemins[i / 3] = Chemin(areteEntreArrondissement[i + 2], Arrondissement(areteEntreArrondissement[i], liste_arrondissements[areteEntreArrondissement[i]].ARecharge()), Arrondissement(areteEntreArrondissement[i + 1], liste_arrondissements[areteEntreArrondissement[i + 1]].ARecharge()));

				//cout << graphe.liste_chemins[i / 3].get_origine().getNumero() << " " <<graphe.liste_chemins[i / 3].get_trajet() << " " << graphe.liste_chemins[i / 3].get_destination().getNumero() << endl;
			}

			fichierALire.close();
		}

		for (int a = 0; a < 21; a++)
		{
			for (int b = 0; b < 21; b++)
			{
				liste_trajets[a][b] = 99999;
			}
		}

		for (int i = 0; i < 39; i++)
		{
			liste_trajets[liste_chemins[i].get_origine().getNumero()][liste_chemins[i].get_destination().getNumero()] = liste_chemins[i].get_trajet();
			liste_trajets[liste_chemins[i].get_destination().getNumero()][liste_chemins[i].get_origine().getNumero()] = liste_chemins[i].get_trajet();
		}
		
	}

	int liste_trajets[20][20]; //arrondissement x arrondissement remplir avec trajet = 99999 si pas de chemin
	Arrondissement liste_arrondissements[19];
	Chemin liste_chemins[40];
};   