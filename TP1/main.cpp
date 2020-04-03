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

void lireFichierPremierePartie(const string& nomFichier); 
//void quit(); 



int main() {

	lireFichierPremierePartie("arrondissements.txt");



	// ===============================Algo Dijks==========================// 
	
	Graph graphe;
	graphe.remplirListeArrondissements;
	graphe.remplirListeChemins;


	afficherGraphe(graphe);
	plusCourtChemin(graphe.liste_chemins);
	traiterRequetes();
	

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

		//case  :

		//	break;

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


/*�crire une fonction r�cursive �creerGraphe()� qui permet de cr�er le graphe repr�sentant les
routes et les points centraux des arrondissements (sommets) � partir d�un fichier dont le nom est
pass� en param�tre.*/

void creerGraphe() {
}

/*�crire une fonction �afficherGraphe()� qui permet d�afficher le graphe (cf. annexe a. pour un
exemple d�affichage de la carte sous forme de graphe).*/

void afficherGraphe() {
}

/*�crire la fonction �plusCourtChemin()� qui permet de d�terminer, en vous inspirant de l�algorithme
de Dijkstra, le plus court chemin entre un sommet et un autre. L�origine (point de d�part)
et la destination (sommet d�arriv�e) doivent �tre pass�es en param�tres. La fonction affiche le
pourcentage final d��nergie dans les batteries de la voiture, le plus court chemin utilis� (d�apr�s
la liste de ses sommets, selon le format de l�annexe) et la longueur de ce dernier en minutes.*/

void plusCourtChemin(int orig, int dest) {
	int trajetsLongueurs[20]; // L
	bool trajetsFaits[20]; // S

	Chemin cheminsPris[1000]; // enregiste les chemins essay�s
	Chemin minICheminSommet;
	Chemin minICheminTotal;

	int o = 0;
	int q = 20;
	for (int i = 0; i < 20; i++) { trajetsLongueurs[i] = 99999; trajetsFaits[i] = 0;} // tous les chemins infinis et aucun trajet fait
	trajetsLongueurs[orig] = 0; // orig a zero
	trajetsFaits[orig] = 1; // sommet orig fait
	while (trajetsFaits[dest] == false) {
<<<<<<< HEAD
		for (int j = 0; j < 20; j++) {
=======
		for (int j = 0; j < 20; j++) { //pour tous les sommets deja integr�s
>>>>>>> e49a0812c14d90dd2bcb56619600ec9780a1a318
			if (trajetsFaits[j]) {
				int trajetMin = 99999;
				int minID = j;
				for (int k = 0; k < 20; k++) {
					if (tableauChemins[j][k] < trajetsLongueurs[k] && trajetsFaits[k] = false) { // regarde les voisins non integr�s de chaque sommets fait
						if (tableauChemins[j][k] + trajetsLongueurs[j] < trajetMin){ // on recupere le sommet non connu avec le chemin le plus court pour chaque sommet connu
							trajetMin = tableauChemins[j][k] + trajetsLongueurs[j];
							minICheminSommet = Chemin(tableauChemins[j][k], new Arrondissement(j, liste_chemins[j].a_recharge_), new Arrondissement(k, liste_chemins[k].a_recharge_));
						}						
					}
				}
				if (minICheminSommet.get_trajet() < minICheminTotal.get_trajet()) { minICheminTotal = minICheminSommet; } // meilleur sommet inconnu voisin de tous les sommets connus
				trajetsLongueurs[minICheminTotal.get_destination()->getNumero()] = tableauChemins[j][minICheminTotal.get_destination()->getNumero()] + trajetsLongueurs[j]; // om met a jour sa longueur
				trajetsFaits[minICheminTotal.get_destination()->getNumero()] = true; // on l'ajout aux soommets connnus
				cheminsPris[o++] = minICheminTotal;  // on le met dans le tableau de chemins essay�s
			}
		}
	} // destination atteinte, maintenant donner le chemin precis
	bool bonChemin = false;
	int batterie = 100;
	int minutes = 0;
	int listeFinale[20];
	int y = o;
	int x = 1;
	int derniereDest = cheminsPris[o].get_origine()->getNumero();
	listeFinale[0] = cheminsPris[o].get_destination()->getNumero();
	minutes += cheminsPris[o].get_trajet();
	while (!bonChemin)
	{
		while (cheminsPris[y - 1].get_destination()->getNumero() != derniereDest)
		{
			y--;
		}
		minutes += cheminsPris[y - 1].get_trajet(); 
		if (cheminsPris[y-1].get_origine()->getNumero() == orig) {
			bonChemin = true;
			listeFinale[x] = orig;
			break;
		}
		listeFinale[x++] = cheminsPris[y - 1].get_origine()->getNumero();
		derniereDest = cheminsPris[y - 1].get_origine()->getNumero();
	}
	batterie -= minutes; //donner le pourcentage de batterie qui reste
}



/*�crire la fonction �traiterRequetes()� qui permet de d�terminer, en vous inspirant de l�algorithme
de Dijkstra, la faisabilit� de requ�tes de clients(nombre maximum de quatre clients � la fois �
l�int�rieur de la voiture, charge qui ne baisse pas en dessous de 15 % , contraintes temporelles
des clients) et de d�terminer le chemin qu�il faut prendre pour desservir ceux - ci.Les requ�tes
proviennent d�un fichier qui s�intitule requetes.txt et elles devront �tre trait�es selon leur ordre
d�arriv�e(leur ordre dans le fichier).La fonction affiche le pourcentage final d��nergie dans les
batteries de la voiture, le plus court chemin utilis�(les sommets o� les clients ont �t� ramass�s,
ceux o� la voiture a �t� recharg�e et les identifiants des clients doivent �tre clairment identifi�s)
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

		//stocker les arrondissements avec les ar�tes
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
