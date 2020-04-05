#pragma once
#ifndef Graph_h
#define Graph_h

#include "Chemin.h"
#include "Arrondissement.h"
using namespace std;

class Graph {
public:

	Graph();

	void CreerGraphe(const string& nomFichier);
	void AfficherGraphe();
	void plusCourtChemin(int origine, int destination); 

private:

	int liste_trajets[20][20]; //arrondissement x arrondissement remplir avec trajet = 99999 si pas de chemin
	Arrondissement liste_arrondissements[19]; // pr les sommets + continet borne.
	Chemin liste_chemins[40]; // les arcs
};   

#endif 