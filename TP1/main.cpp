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

//void plusCourtChemin(int orig, int dest);
//void lireFichierPremierePartie(const string& nomFichier); 
void quit(); 



int main() {

	//lireFichierPremierePartie("arrondissements.txt");
	Graph graphe;
	graphe.CreerGraphe(arrondissement); 
	graphe.AfficherGraphe(); 
	int orig = 14;
	int dest = 12;
	graphe.plusCourtChemin(orig, dest);

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

	//=======================Affichage====================================//
		//Menu
	cout << endl << " ----------------------- MENU -----------------------" << endl << endl;

	//controle
	quit();
	cin.clear();
	char value = { };
	cin >> value;

	switch (value)
	{

	case 'd':
		cout << "Menu" << endl;
		break;

	case 'a':
		cout << "Lecture nouvelle carte" << endl;
		break;

	case 'b':
		cout << "plus court chemin securitaire" << endl;
		break;

	case 'c':
		cout << "traiter les requetes" << endl;
		break;


	default:
		break;
	}
	//=======================Affichage====================================//
	
	return 0;
}




/*Écrire la fonction ”traiterRequetes()” qui permet de déterminer, en vous inspirant de l’algorithme
de Dijkstra, la faisabilité de requêtes de clients(nombre maximum de quatre clients à la fois à
l’intérieur de la voiture, charge qui ne baisse pas en dessous de 15 % , contraintes temporelles
des clients) et de déterminer le chemin qu’il faut prendre pour desservir ceux - ci.Les requêtes
proviennent d’un fichier qui s’intitule requetes.txt et elles devront être traitées selon leur ordre
d’arrivée(leur ordre dans le fichier).La fonction affiche le pourcentage final d’énergie dans les
batteries de la voiture, le plus court chemin utilisé(les sommets où les clients ont été ramassés,
ceux où la voiture a été rechargée et les identifiants des clients doivent être clairment identifiés)
et la longueur de ce dernier en minutes.*/

void traiterRequetes() {
}


// ===============================Algo Dijks==========================// 




//===================Affichage========================// 
//Pour l'affichage
// permet davoir le quit
void quit() {
	string quit;
	cin >> quit;
	if (quit == "quitter" || quit == "Quitter") {
		cout << "menu" << endl;
		return;
	}
	return;
}


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