#include "Arrondissements.h"

Arrondissements::Arrondissements(int num, bool a_station_recharge) : nom_(num), prix_(a_station_recharge)
{}

//getters

int Arrondissements::getNumero() const
{
	return numero_;
}

bool Arrondissements::ARecharge()  const
{
	return a_recharge_;
}

//setters

void Arrondissements::setNumero(int num)
{
	numero_ = num;
}

void Arrondissements::setRecharge(bool a_station_recharge)
{
	a_recharge_ = a_station_recharge;
}