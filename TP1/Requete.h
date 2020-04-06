#pragma once
#ifndef Requette_h
#define Requette_h

#include "RequeteUnique.h"
#include "Graph.h"

using namespace std; 

class Requete {

public: 

	Requete() : premierPoint(99999) {};
	void LireRequete(const string& Fichier); 
	void traiterRequetes();
private:

	int premierPoint;
	RequetteUnique listeRequete[10];
};



#endif