#pragma once
#ifndef Requette_h
#define Requette_h

using namespace std; 

class Requete {

public: 

	Requete(); 
	void LireRequete(const string& Fichier); 

private:

	int ID_; 
	int PointDepart_; 
	int PointDArriver_; 
	int TempsVoulu_; 

};



#endif