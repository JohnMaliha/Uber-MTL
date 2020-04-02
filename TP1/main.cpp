#include<iostream>
#include <string>
#include "Graph.h"
#include<vector>
using namespace std;

using namespace std; 


int main() {
	Graph graphe;
	graphe.remplirListeArrondissements;
	graphe.remplirListeChemins;

	
	afficherGraphe(graphe);
	plusCourtChemin(graphe.liste_chemins);
	traiterRequetes();

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
	for (int i = 0; i < 20; i++) { trajetsLongueurs[i] = 99999; trajetsFaits[i] = 0;} // tous les chemins infinis et aucun trajet fait
	trajetsLongueurs[orig] = 0; // orig a zero
	trajetsFaits[orig] = 1; // sommet orig fait
	while (trajetsFaits[dest] == false) {
		for (int j = 0; j < 20; j++) { 
			if (trajetsFaits[j]) {
				int trajetMin = 99999;
				int minID = j;
				for (int k = 0; k < 20; k++) {
					if (tableauChemins[j][k] < trajetsLongueurs[k] && trajetsFaits[k] = false) { // regarde les voisins non atteints de chaque sommets fait
						if (tableauChemins[j][k] + trajetsLongueurs[j] < trajetMin){
							trajetMin = tableauChemins[j][k] + trajetsLongueurs[j];
							minID = k;
						}
						trajetsLongueurs[minID] = tableauChemins[j][minID] + trajetsLongueurs[j];
						trajetsFaits[minID] = true;
					}
				}
			}
		}
	}
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