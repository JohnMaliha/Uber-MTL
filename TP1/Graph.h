#include "Chemin.h"
#include "Arrondissement.h"
using namespace std;

class Graph {

public:
	//lire la premiere section de arrondissements.txt pour les mettre dans liste_arrondissements[] en utilisant le constructeur d'arrondissement
	void remplirListeArrondissements();
	//lire la deuxieme section de arrondissements.txt pour ajouter les trajets en utilisant le constructeur de chemin (il faut utiliser le bon arrondissement de listeArrondissements) et les mettre dans listeChemins[]
	void remplirListeChemins(); 

private:
	Chemin liste_chemins[1][1]; //arrondissement x arrondissement remplir avec trajet = 99999 si pas de chemin
	Arrondissement liste_arrondissements[0];
};   