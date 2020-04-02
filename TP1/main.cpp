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

	creerGraphe(graphe);
	afficherGraphe(graphe);
	plusCourtChemin(graphe.liste_chemins);
	traiterRequetes();

	return 0;
}

/*Écrire une fonction récursive “creerGraphe()” qui permet de créer le graphe représentant les
routes et les points centraux des arrondissements (sommets) à partir d’un fichier dont le nom est
passé en paramètre.*/
void creerGraphe() {
}
/*Écrire une fonction “afficherGraphe()” qui permet d’afficher le graphe (cf. annexe a. pour un
exemple d’affichage de la carte sous forme de graphe).*/
void afficherGraphe() {
}

	/*Écrire la fonction ”plusCourtChemin()” qui permet de déterminer, en vous inspirant de l’algorithme
de Dijkstra, le plus court chemin entre un sommet et un autre. L’origine (point de départ)
et la destination (sommet d’arrivée) doivent être passées en paramètres. La fonction affiche le
pourcentage final d’énergie dans les batteries de la voiture, le plus court chemin utilisé (d’après
la liste de ses sommets, selon le format de l’annexe) et la longueur de ce dernier en minutes.*/
void plusCourtChemin() {
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