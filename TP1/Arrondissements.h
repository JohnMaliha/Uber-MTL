#include <string>
#include <string_view>
using namespace std;

class Arrondissements
{
public:
	Arrondissements(int num, bool a_station_recharge);
	
	int getNumero() const;
	bool ARecharge() const;

	void setNumero(int);
	void setRecharge(bool);

protected:
	int numero_;
	bool a_recharge_;
};