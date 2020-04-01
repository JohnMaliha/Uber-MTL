#include <string>
#include <string_view>
using namespace std;

class Arrondissement
{
public:
	Arrondissement(int , bool);
	Arrondissement() {
		numero_ = -1;
		a_recharge_ = 0;
	}

	int getNumero() const;
	bool ARecharge() const;

	void setNumero(int);
	void setRecharge(bool);

private:
	int numero_;
	bool a_recharge_;
};