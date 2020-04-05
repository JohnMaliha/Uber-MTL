#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>

#include "Graph.h"


using namespace std;
const string& Fichierarrondissement = "arrondissements.txt";

Graph::Graph() {

}

/*Écrire une fonction récursive “creerGraphe()” qui permet de créer le graphe représentant les
routes et les points centraux des arrondissements (sommets) à partir d’un fichier dont le nom est
passé en paramètre.*/
void Graph::CreerGraphe(const string& nomFichier) {

	char separateur = ',';
	string LigneAvecVirgule;
	vector<int> arrondissement;
	vector<int> borne;
	vector<int> ArrondissementBorne;
	vector<int> areteEntreArrondissement;
	string LigneSansVirgule;
	ifstream fichierALire(Fichierarrondissement);

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
			//cout << n << "  "<< borne[n] <<endl;
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

			//cout << graph.liste_arrondissements[i].getNumero() << endl;
			//	cout << graph.liste_arrondissements[i].ARecharge() <<endl; 
		}

		//stocker les arrondissements avec les arêtes
		cout << endl << endl;
		int positionDeDepart = 38;
		for (positionDeDepart; positionDeDepart < ArrondissementBorne.size(); positionDeDepart++) {
			areteEntreArrondissement.push_back(ArrondissementBorne[positionDeDepart]);
		}

		//
		for (int i = 0; i < areteEntreArrondissement.size(); i += 3) {
			liste_chemins[i / 3] = Chemin(areteEntreArrondissement[i + 2], Arrondissement(areteEntreArrondissement[i], liste_arrondissements[areteEntreArrondissement[i]].ARecharge()), Arrondissement(areteEntreArrondissement[i + 1], liste_arrondissements[areteEntreArrondissement[i + 1]].ARecharge()));

			//cout << graphe.liste_chemins[i / 3].get_origine().getNumero() << " " <<graphe.liste_chemins[i / 3].get_trajet() << " " << graphe.liste_chemins[i / 3].get_destination().getNumero() << endl;
		}

		fichierALire.close();
	}

	for (int a = 0; a < 20; a++)
	{
		for (int b = 0; b < 20; b++)
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


/*Écrire la fonction ”plusCourtChemin()” qui permet de déterminer, en vous inspirant de l’algorithme
de Dijkstra, le plus court chemin entre un sommet et un autre. L’origine (point de départ)
et la destination (sommet d’arrivée) doivent être passées en paramètres. La fonction affiche le
pourcentage final d’énergie dans les batteries de la voiture, le plus court chemin utilisé (d’après
la liste de ses sommets, selon le format de l’annexe) et la longueur de ce dernier en minutes.*/

void Graph::plusCourtChemin(int origine, int destination) {
	Graph graphe;
	graphe.CreerGraphe(Fichierarrondissement);
	int trajetsLongueurs[20]; // L
	bool trajetsFaits[20]; // S

	Chemin cheminsPris[1000]; // enregiste les chemins essayés
	Chemin minICheminSommet;
	Chemin minICheminTotal;

	int o = 0;
	int q = 20;
	for (int i = 0; i < 20; i++) { trajetsLongueurs[i] = 99999; trajetsFaits[i] = 0; } // tous les chemins infinis et aucun trajet fait
	trajetsLongueurs[origine] = 0; // orig a zero
	trajetsFaits[origine] = 1; // sommet orig fait
	while (trajetsFaits[destination] == false) {
		minICheminTotal.set_trajet(99999);
		minICheminSommet.set_trajet(99999);
		for (int j = 0; j < 20; j++) { //pour tous les sommets deja integrés
			if (trajetsFaits[j]) {
				int trajetMin = 99999;
				int minID = j;
				for (int k = 0; k < 20; k++) {
					if (graphe.liste_trajets[j][k] < trajetsLongueurs[k] && trajetsFaits[k] == false) { // regarde les voisins non integrés de chaque sommets fait
						if (graphe.liste_trajets[j][k] + trajetsLongueurs[j] < trajetMin) { // on recupere le sommet non connu avec le chemin le plus court pour chaque sommet connu
							trajetMin = graphe.liste_trajets[j][k] + trajetsLongueurs[j];
							minICheminSommet = Chemin(trajetMin, Arrondissement(j, graphe.liste_chemins[j].get_origine().ARecharge()), Arrondissement(k, graphe.liste_chemins[k].get_destination().ARecharge()));
						}
					}
				}
				if (minICheminSommet.get_trajet() < minICheminTotal.get_trajet()) { minICheminTotal = minICheminSommet; } // meilleur sommet inconnu voisin de tous les sommets connus
			}
		}
		trajetsLongueurs[minICheminTotal.get_destination().getNumero()] = minICheminTotal.get_trajet(); // om met a jour sa longueur
		trajetsFaits[minICheminTotal.get_destination().getNumero()] = true; // on l'ajout aux soommets connnus
		cheminsPris[++o] = minICheminTotal;  // on le met dans le tableau de chemins essayés
		cout << cheminsPris[o].get_origine().getNumero() << " " << cheminsPris[o].get_destination().getNumero() << " " << cheminsPris[o].get_trajet() << endl;
	} // destination atteinte, maintenant donner le chemin precis
	bool bonChemin = false;
	int batterie = 100;
	int minutes = 0;
	int listeFinale[20];
	int y = o + 1;
	int x = 2;
	int derniereDest = cheminsPris[o].get_origine().getNumero();
	listeFinale[0] = cheminsPris[o].get_destination().getNumero();
	listeFinale[1] = derniereDest;
	minutes += cheminsPris[o].get_trajet();
	if (y != 1 && derniereDest != origine) {
		while (!bonChemin)
		{
			while (cheminsPris[y - 1].get_destination().getNumero() != derniereDest)
			{
				y--;
			}
			if (cheminsPris[y - 1].get_origine().getNumero() == origine) {
				bonChemin = true;
				listeFinale[x] = origine;
				break;
			}
			listeFinale[x++] = cheminsPris[y - 1].get_origine().getNumero();
			derniereDest = cheminsPris[y - 1].get_origine().getNumero();
		}
	}
	cout << "depart : point " << origine << ", destination : point " << destination << endl;
	if (y != 1 && derniereDest != origine) {
		for (int z = x; z != 0; z--) {
			int minutesT = graphe.liste_trajets[listeFinale[z]][listeFinale[z - 1]];
			batterie -= minutesT; //donner le pourcentage de batterie qui reste
			cout << "point " << listeFinale[z] << " -> point " << listeFinale[z - 1] << " ; " << minutesT << "mn ; batterie : " << batterie << "%" << endl;
		}
	}
	else
	{
		cout << "point " << origine << " -> point " << destination << " ; " << graphe.liste_trajets[origine][destination] << "mn ; batterie : " << batterie - graphe.liste_trajets[origine][destination] << "%" << endl;
	}
	cout << "duree totale du trajet : " << minutes << "mn" << endl;
}









/*Écrire une fonction “afficherGraphe()” qui permet d’afficher le graphe (cf. annexe a. pour un
	exemple d’affichage de la carte sous forme de graphe).*/
void Graph::AfficherGraphe() {

	Graph graphe1;
	graphe1.CreerGraphe(Fichierarrondissement);

	for (int i = 0; i < 19; i++) { // le noeud origine

		cout << "noeud " << i << endl;
		cout << graphe1.liste_arrondissements[i].getNumero() << " a borne? " << graphe1.liste_arrondissements[i].ARecharge() << endl << endl;


		//for (int j = 1; j < 19; j++) { // les autres noeuds reliser au premier.  

			//if (graphe.liste_arrondissements[i].getNumero()  ) {

				//cout << "(" << graphe.liste_arrondissements[i].getNumero() << "," << graphe.liste_arrondissements[i].ARecharge() << "," << "(" << "(";
				//cout << graphe.liste_chemins[i].get_destination().getNumero() << "," << graphe.liste_chemins[i].get_trajet() << ",";
			//}

	//	}
		//cout << endl; 
	}

}