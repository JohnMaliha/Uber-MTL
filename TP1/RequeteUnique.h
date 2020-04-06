#pragma once
#ifndef RequetteUnique_h
#define RequetteUnique_h

using namespace std;

class RequetteUnique {

public:

	RequetteUnique() : ID_(99999), PointDepart_(99999), PointDArriver_(99999), TempsVoulu_(99999) {};
	RequetteUnique(int a, int b, int c, int d) : ID_(a), PointDepart_(b),PointDArriver_(c), TempsVoulu_(d) {};

	void setID(int a) {ID_ = a;}
	void setPointDepart(int a) { PointDepart_ = a; }
	void setPointDArriver(int a) { PointDArriver_ = a; }
	void setTempsVoulu(int a) { TempsVoulu_ = a; }
	void setDepose(bool a) { deposé_ = a; }

	int getID() { return ID_; }
	int getPointDepart() { return PointDepart_ ; }
	int getPointDArriver() { return PointDArriver_ ; }
	int getTempsVoulu() { return TempsVoulu_ ; }
	bool getDepose() { return deposé_; }

private:
	int ID_;
	int PointDepart_;
	int PointDArriver_;
	int TempsVoulu_;
	bool deposé_ = false;
};

#endif
