#pragma once

#include <string>

class Aliment {

	Aliment(std::string nume, double val_energetica,double grasimi, double glucide, double fibre,double proteine,double cantitate)
	{
		this->nume = nume;
		this->val_energetica = val_energetica;
		this->grasimi = grasimi;
		this->glucide = glucide;
		this->fibre = fibre;
		this->proteine = proteine;
		this->sare = sare;
		this->cantitate = cantitate;
	}

private :
	std::string nume;
	double val_energetica;
	double grasimi;
	double glucide;
	double fibre;
	double proteine;
	double sare;
	double cantitate;
};