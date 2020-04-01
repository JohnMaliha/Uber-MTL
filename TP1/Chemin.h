#include <string>
#include <string_view>
#include "Arrondissement.h"
using namespace std;

class Chemin
{
public:
	Chemin(int , Arrondissement , Arrondissement);
	Chemin() {
		origine_ = nullptr;
		destination_ = nullptr;
		trajet_ =99999;
		nb_trajtet_modifié = 0;
	};

	int get_trajet() const;
	Arrondissement get_origine() const;
	Arrondissement get_destination() const;

	void set_trajet(int);
	void set_origine(Arrondissement);
	void set_destination(Arrondissement);

private:
	int trajet_;
	Arrondissement* origine_;
	Arrondissement* destination_;
	int nb_trajtet_modifié;
};
