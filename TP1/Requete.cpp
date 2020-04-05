#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>

#include "Requete.h"

using namespace std;

Requete::Requete() {

}

void Requete::LireRequete(const string& Fichier) {
	char separateur = ',';
	string LigneAvecVirgule;
	vector<int> requetes;
	string LigneSansVirgule;
	ifstream fichierALire(Fichier);

	if (fichierALire.fail())
		cout << "Probleme d'ouverture!" << endl;
	else {
		int i = 0;
		while (!ws(fichierALire).eof()) {
			getline(fichierALire, LigneAvecVirgule);
			stringstream ChaineDeCaractere(LigneAvecVirgule);//brise la chaine de caractere
			while (getline(ChaineDeCaractere, LigneSansVirgule, separateur)) {
				requetes.push_back(stoi(LigneSansVirgule));//stoi: convertit string en int
			}
		}
		for (auto it : requetes) {
			cout << it << endl;
		}
		fichierALire.close();
	}


}