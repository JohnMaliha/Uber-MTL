#pragma once
#include <vector>

class Coordonnees {
public:
	Coordonnees(); 
	int x;
	int y;
	int z;

	//std::vector<int> valeurs; 
	
};


class Liste_Coord {
public:
	Liste_Coord(); 
	int getNbElement() { return nbElement_; };
	Coordonnees liste[];

private:

	static const int nbElement_ =20 ;
};
