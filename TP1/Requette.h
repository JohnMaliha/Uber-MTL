#pragma once
#ifndef Requette_h
#define Requette_h
#include<string>


class Requette {

public: 

	Requette(); 
	void LireRequette(const string& nomFichier); 

private:

	int ID_; 
	int PointDepart_; 
	int PointDArriver_; 
	int TempsVoulu_; 

};



#endif