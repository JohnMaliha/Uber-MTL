#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>

#include "Requete.h"

using namespace std;


void Requete::LireRequete(const string& Fichier) {
	char separateur = ',';
	string LigneAvecVirgule;
	vector<int> requetes;
	string LigneSansVirgule;
	ifstream fichierALire(Fichier);
	Requete listeRequetes[20];
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
		premierPoint = requetes[0];
		
		int p = 1;
		for (int i = 0; i< requetes.size()-4; i+=4) {
			listeRequete[p].setID(requetes[i + 1]);
			listeRequete[p].setPointDepart(requetes[i + 2]);
			listeRequete[p].setPointDArriver(requetes[i + 3]);
			listeRequete[p].setTempsVoulu(requetes[i + 4]);
			p++;
		}
		
		listeRequete[0] = RequetteUnique(99999, premierPoint, listeRequete[1].getPointDepart(), 99999);

		fichierALire.close();
	}
}

/*Écrire la fonction ”traiterRequetes()” qui permet de déterminer, en vous inspirant de l’algorithme
de Dijkstra, la faisabilité de requêtes de clients (nombre maximum de quatre clients à la fois à
l’intérieur de la voiture, charge qui ne baisse pas en dessous de 15%, contraintes temporelles
des clients) et de déterminer le chemin qu’il faut prendre pour desservir ceux-ci. Les requêtes
proviennent d’un fichier qui s’intitule requetes.txt et elles devront être traitées selon leur ordre
d’arrivée (leur ordre dans le fichier). La fonction affiche le pourcentage final d’énergie dans les
batteries de la voiture, le plus court chemin utilisé (les sommets où les clients ont été ramassés,
ceux où la voiture a été rechargée et les identifiants des clients doivent être clairment identifiés)
et la longueur de ce dernier en minutes.*/

void Requete::traiterRequetes() {
	
	bool contournement = false;
	int positionActuelle = premierPoint;
	bool faisable = true;
	bool resteClients = true;
	int batterieFinale = 100;
	int nbPlacePrises = 0;
	int listeEnsemblePassages[200];
	int tempsTotal = 0;
	for (int h = 0; h < 200; h++) {
		listeEnsemblePassages[h] = 0;
	}
	listeEnsemblePassages[0] = premierPoint;
	int passage = 1;
	bool letmesleep = false;
	bool doitRecharger = false;
	bool rechargefaite = true;

	for (int w = 0; w < 20; w++) {

	}

	Graph graphe;
	graphe.CreerGraphe("arrondissements.txt");

	
			for (int client = 0; client <= 9; client++) {

				bool trajetIntermediaire = false;

				int origine = listeRequete[client].getPointDepart();
				int destination = listeRequete[client].getPointDArriver();

				if (doitRecharger) {
					client -= 1;
					if (!letmesleep) {
						origine = listeRequete[client].getPointDepart();
						letmesleep = false;
					}
					else
					{
						origine = listeRequete[client].getPointDArriver();
					} 
					for (int ir = 1; ir < 20; ir++) { // le noeud origine
						if (graphe.getTrajet(origine,ir) < 99999 && graphe.getArrondissement(ir-1).ARecharge() ){
								destination = ir;
								
								cout << "Risque de plus de batterie, direction la borne la plus proche : " << ir<<endl;
								break;
						}
					}
				}
				
				else if (client >1  && listeRequete[client].getPointDepart() != positionActuelle) {
					origine = positionActuelle;
					if (contournement) {
						destination = listeRequete[client].getPointDArriver();
						contournement = false;
						cout << "\non termine l'ancien trajet et on depose le client " << client-1 << endl;
						client++;
					}
					else {
						cout << "\non va cherche le prochain client non dans la voiture\n";
						destination = listeRequete[client].getPointDepart();
					}
					trajetIntermediaire = true;
					client -= 1;
				}

				

				if (client >= 1 && trajetIntermediaire == false && doitRecharger == false) {
					cout << endl << "Prevision embarquement du client " << client-1 << endl;
					nbPlacePrises++;
					tempsTotal = 0;
				}
				

				int trajetsLongueurs[20]; // L
				bool trajetsFaits[20]; // S

				Chemin cheminsPris[100]; // enregiste les chemins essayés
				for (int u = 0; u < 100;u++) {
					cheminsPris[u] = Chemin();
				}
				Chemin minICheminSommet;
				Chemin minICheminTotal;

				int o = 0;
				int q = 20;
				for (int i = 0; i < 20; i++) { trajetsLongueurs[i] = 99999; trajetsFaits[i] = 0; } // tous les chemins infinis et aucun trajet fait
				trajetsLongueurs[origine] = 0; // orig a zero
				trajetsFaits[origine] = 1; // sommet orig fait
				while (trajetsFaits[destination] == false) {
					minICheminTotal.set_trajet(99999);
					minICheminSommet.set_trajet(99999);
					for (int j = 0; j < 20; j++) { //pour tous les sommets deja integrés
						if (trajetsFaits[j]) {
							int trajetMin = 99999;
							int minID = j;
							for (int k = 0; k < 20; k++) {
								if (graphe.getTrajet(j, k) < trajetsLongueurs[k] && trajetsFaits[k] == false) { // regarde les voisins non integrés de chaque sommets fait
									if (graphe.getTrajet(j, k) + trajetsLongueurs[j] < trajetMin) { // on recupere le sommet non connu avec le chemin le plus court pour chaque sommet connu
										trajetMin = graphe.getTrajet(j, k) + trajetsLongueurs[j];
										minICheminSommet = Chemin(trajetMin, Arrondissement(j, graphe.getChemin(j).get_origine().ARecharge()), Arrondissement(k, graphe.getChemin(k).get_destination().ARecharge()));
									}
								}
							}
							if (minICheminSommet.get_trajet() < minICheminTotal.get_trajet()) { minICheminTotal = minICheminSommet; } // meilleur sommet inconnu voisin de tous les sommets connus
						}
					}
					trajetsLongueurs[minICheminTotal.get_destination().getNumero()] = minICheminTotal.get_trajet(); // om met a jour sa longueur
					trajetsFaits[minICheminTotal.get_destination().getNumero()] = true; // on l'ajout aux soommets connnus
					cheminsPris[++o] = minICheminTotal;  // on le met dans le tableau de chemins essayés
					//cout << cheminsPris[o].get_origine().getNumero() << " " << cheminsPris[o].get_destination().getNumero() << " " << cheminsPris[o].get_trajet() << endl;
				} // destination atteinte, maintenant donner le chemin precis
				
				
				int minutes = 0;
				int listeFinale[20];
				for (int t = 0; t < 20;t++)
					listeFinale[t] = 0;
				int y = o + 1;
				int x = 2;
				int derniereDest = cheminsPris[o].get_origine().getNumero();
				listeFinale[0] = cheminsPris[o].get_destination().getNumero();
				listeFinale[1] = derniereDest;
				if (y != 1 && derniereDest != origine) {
					
						while (cheminsPris[y - 1].get_destination().getNumero() != derniereDest && derniereDest != origine)
						{
							y--;
							if (cheminsPris[y - 1].get_destination().getNumero() == derniereDest){ 
								listeFinale[x++] = cheminsPris[y - 1].get_origine().getNumero();
								derniereDest = cheminsPris[y - 1].get_origine().getNumero();
							}
						}
						
						

						for (int m = x-2; m != 0;m--) {
							if (20 > listeFinale[m] > 0) {
								listeEnsemblePassages[passage++] = listeFinale[m];
								
								if (graphe.getArrondissement(listeEnsemblePassages[passage]).getNumero() == listeRequete[client + 1].getPointDepart() && nbPlacePrises < 4) {
									//prend le prochain client qui est sur le chemin
									listeRequete[client + 1].setPointDepart(graphe.getArrondissement(listeEnsemblePassages[passage]).getNumero());
									nbPlacePrises++;
									cout << "on recupre en avance le prochain client!" << endl;
								}
							}
						}
						listeEnsemblePassages[passage++] = listeFinale[0];
						
						
						
						derniereDest = listeFinale[1];

						
						listeRequete[client].setTempsVoulu(listeRequete[client].getTempsVoulu() - minutes);
						int minutesT = 0;
						cout << "depart : point " << origine << ", destination : point " << destination << endl;
						if (derniereDest != origine) {
							for (int z = x; z != 1; z--) {
								minutesT = graphe.getTrajet(listeFinale[z-1],listeFinale[z - 2]);
								batterieFinale -= minutesT; //donner le pourcentage de batterie qui reste
							
								if (batterieFinale < 15 && doitRecharger != true) {
									doitRecharger = true;
									listeEnsemblePassages[--passage] = 0;
									batterieFinale += minutesT;
									rechargefaite = false;
									if(tempsTotal!=0){ tempsTotal -= minutesT = graphe.getTrajet(listeFinale[z], listeFinale[z - 1]); }
									
									
									break;
					
								}
								if (batterieFinale < 0) {
									faisable = false;
									cout << "trajet non faisable, il faudrait des bornes de recharges dans nos trajets" << endl;
								}

								if (doitRecharger == true) {
									doitRecharger = false;
									batterieFinale = 100;
								}
								

								tempsTotal += minutesT;
								cout << "point " << listeFinale[z-1] << " -> point " << listeFinale[z - 2] << " ; " << minutesT << "mn ; batterie : " << batterieFinale << "%" << endl;
							}
						}
						else  
						{
							cout << "point " << origine << " -> point " << destination << " ; " << 
								minutesT << "mn ; batterie : " << batterieFinale << "%" << endl;; //donner le pourcentage de batterie qui reste 
						}
						if (!doitRecharger) {
							cout << "duree totale du trajet : " << tempsTotal << "mn" << endl;
						}

						
				}
				else {

					listeEnsemblePassages[passage++] = derniereDest;
					int minutesT = graphe.getTrajet(origine, destination);
					batterieFinale -= graphe.getTrajet(origine,destination); //donner le pourcentage de batterie qui reste

					if (doitRecharger == true) {
						doitRecharger = false;
						batterieFinale = 100;
						tempsTotal += 10;
						cout << "10mn pour la recharge" << endl;
						rechargefaite = true;
						client -= 1;
						contournement = true;
					}

					if (graphe.getArrondissement(listeEnsemblePassages[passage]).ARecharge() && batterieFinale < 15) {
						batterieFinale = 100;
						tempsTotal += 10;
					}
					minutes += minutesT;
					tempsTotal += minutes;
					cout << "depart : point " << origine << ", destination : point " << destination << endl;
					cout << "point " << origine << " -> point " << destination << " ; " <<
						minutesT << "mn ; batterie : " << batterieFinale << "%" << endl;; //donner le pourcentage de batterie qui reste 
					cout << "duree totale du trajet : " << tempsTotal << "mn\n" << endl;
					
				}
				if (!doitRecharger) {
					positionActuelle = listeFinale[0];
					if (!contournement && !trajetIntermediaire && client != 0) {
						if (nbPlacePrises == 1 && client != 9) {
							cout << "Prochain client pas sur le chemin ou perdrait du temps  (respect du fil des requetes)" << endl;
						}
						cout << "le client " << client - 1 << " a ete depose a sa destination\n" << endl;

						nbPlacePrises--;
					}
				}
				if (trajetIntermediaire && doitRecharger) { letmesleep = true; }
				
			} cout << "\n";	

}