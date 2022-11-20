#pragma once
#include <iostream>
#include <string>
#pragma warning (disable : 4996)
#pragma warning (disable : 6031)

class Impozit
{
protected:

	int* taxe;
	int nrTaxe;

public:

	Impozit();

	Impozit(const int*, const int);

	Impozit(const Impozit&);

	~Impozit();

	Impozit& operator=(const Impozit&);

	int totalTaxe() const;

	friend std::istream& operator>>(std::istream&, Impozit&);

	friend std::ostream& operator<<(std::ostream&, const Impozit&);

};