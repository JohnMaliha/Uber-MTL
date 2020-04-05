#pragma once
#ifndef Requette_h
#define Requette_h
#include<string>


class Requete {

public: 

	Requete(); 
	void LireRequete(const string& nomFichier); 

private:

	int ID_; 
	int PointDepart_; 
	int PointDArriver_; 
	int TempsVoulu_; 

};



#endif