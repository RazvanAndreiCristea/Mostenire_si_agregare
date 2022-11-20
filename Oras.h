#pragma once
#include "Locuitor.h"

class Oras
{
	Locuitor* locuitori;
	int nrLocuitori;
	char* primar;

public:

	Oras();

	//Oras(const Locuitor*, const int, const char*);

	~Oras();

	void setPrimar(const char*);

	void adaugaLocuitori(); //metoda care adauga pe pozitia X un nou locuitor

	friend std::istream& operator>>(std::istream&, Oras&);

	friend std::ostream& operator<<(std::ostream&, const Oras&);

	friend void sortareDupaTaxe(Oras&);

};