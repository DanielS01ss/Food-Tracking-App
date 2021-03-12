#pragma once
#include <string>

enum BMI { Under = 0, Normal, Over, Obese, ObeseExtreme };
enum Activitate { Sedentar = 0, Usoara, Moderata, Intensa };
enum Scop { Scadere_in_greutate = 0, Mentinere, Crestere_in_greutate };
enum Metabolism { Lent = 0, Norm, Rapid };

class User {

public:

	User()
	{
		std::cout << "Just an empty constructor =))";
	}

	User(std::string nume, int varsta, bool sex, double greutate, double inaltime, double greutate_dorita, BMI b1, Activitate act, Scop s, Metabolism
		m1)
	{
		this->nume = nume;
		this->varsta = varsta;
		this->sex = sex;
		this->greutate = greutate;
		this->inaltime = inaltime;
		this->greutate_dorita = greutate_dorita;
		this->person_bmi = b1;
		this->activity = act;
		this->personal_purpose = s;
		this->person_metabolism = m1;
	}

	

	std::string getNume()
	{
		return this->nume;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	bool getSex()
	{
		return this->sex;
	}
	double getGreutate()
	{
		return this->greutate;
	}
	double getInaltime()
	{
		return this->inaltime;
	}
	double getGreutate_dorita()
	{
		return this->greutate_dorita;
	}
	BMI getPersonBmi()
	{
		return this->person_bmi;
	}
	Scop getPersonScope()
	{
		return this->personal_purpose;
	}
	Metabolism getPersonMetabolism()
	{
		return this->person_metabolism;
	}

private:
	std::string nume;
	int varsta;
	bool sex;
	double greutate, inaltime,greutate_dorita;
	BMI person_bmi;
	Activitate activity;
	Scop personal_purpose;
	Metabolism person_metabolism;

};