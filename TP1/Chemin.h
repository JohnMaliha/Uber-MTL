#pragma once

#include <string>
#include <string_view>
#include "Arrondissement.h"
using namespace std;

class Chemin
{
public:

	Chemin(int , Arrondissement , Arrondissement);
	Chemin() {
		origine_ = Arrondissement();
		destination_ = Arrondissement();
		trajet_ =99999;

	};

	int get_trajet() const;
	Arrondissement get_origine() const;
	Arrondissement get_destination() const;

	void set_trajet(int);
	void set_origine(Arrondissement); // prend un ptr, pr match avec lattribut
	void set_destination(Arrondissement);

private:
	int trajet_;
	Arrondissement origine_;
	Arrondissement destination_;
};
