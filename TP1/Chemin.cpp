#include "Chemin.h"

Chemin::Chemin(int trajet, Arrondissement origine, Arrondissement destination) : trajet_(trajet), origine_(origine), destination_(destination)
{}

//getters

int Chemin::get_trajet() const
{
	return trajet_;
}

Arrondissement Chemin::get_origine() const
{
	return origine_;
}

Arrondissement Chemin::get_destination() const
{
	return destination_;
}

//setters

void Chemin::set_trajet(int trajet)
{
	trajet_ = trajet;
}

void Chemin::set_origine(Arrondissement origine)
{
	origine_ = origine;
}

void Chemin::set_destination(Arrondissement destination)
{
	destination_ = destination;
}