#pragma once
#include <iostream>
#include <string>
#pragma warning (disable : 4996)
#pragma warning (disable : 6031)

class Locuinta
{
protected:

	char* adresa;
	int valoare;

public:

	Locuinta();

	Locuinta(const char*, const int);

	Locuinta(const Locuinta&);

	~Locuinta();

	Locuinta& operator=(const Locuinta&);

	friend std::istream& operator>>(std::istream&, Locuinta&);

	friend std::ostream& operator<<(std::ostream&, const Locuinta&);

};