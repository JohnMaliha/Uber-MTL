#include "Arrondissement.h"

Arrondissement::Arrondissement(int num, bool a_station_recharge) : numero_(num), a_recharge_(a_station_recharge)
{}

//getters

int Arrondissement::getNumero() const
{
	return numero_;
}

bool Arrondissement::ARecharge()  const
{
	return a_recharge_;
}

//setters

void Arrondissement::setNumero(int num)
{
	numero_ = num;
}

void Arrondissement::setRecharge(bool a_station_recharge)
{
	a_recharge_ = a_station_recharge;
}