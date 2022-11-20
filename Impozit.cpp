#include "Impozit.h"

Impozit::Impozit()
{
	taxe = nullptr;
	nrTaxe = 0;
}

Impozit::Impozit(const int* taxe, const int nrTaxe)
{
	this->nrTaxe = nrTaxe;

	if (taxe != nullptr)
	{
		this->taxe = new int[nrTaxe];

		for (auto j = 0; j < nrTaxe; j++)
			this->taxe[j] = taxe[j];
	}
}

Impozit::Impozit(const Impozit& impozit)
{
	this->nrTaxe = impozit.nrTaxe;

	if (impozit.taxe != nullptr)
	{
		this->taxe = new int[impozit.nrTaxe];

		for (auto j = 0; j < impozit.nrTaxe; j++)
			this->taxe[j] = impozit.taxe[j];
	}
}

Impozit::~Impozit()
{
	if (taxe != nullptr)
		delete[] taxe;
}

Impozit& Impozit::operator=(const Impozit& impozit)
{
	if (this != &impozit)
	{
		this->nrTaxe = impozit.nrTaxe;

		if (this->taxe != nullptr)
			delete[] this->taxe;

		if (impozit.taxe != nullptr)
		{
			this->taxe = new int[impozit.nrTaxe];

			for (auto j = 0; j < impozit.nrTaxe; j++)
				this->taxe[j] = impozit.taxe[j];
		}
	}

	return *this;
}

int Impozit::totalTaxe() const
{
	int suma(0);

	for (auto j = 0; j < nrTaxe; j++)
		suma += taxe[j];

	return suma;
}

std::istream& operator>>(std::istream& intrare, Impozit& impozit)
{
	std::cout << "Numarul de taxe este: ";
	intrare >> impozit.nrTaxe;

	if (impozit.taxe != nullptr)
		delete[] impozit.taxe;

	impozit.taxe = new int[impozit.nrTaxe];

	for (auto j = 0; j < impozit.nrTaxe; j++)
	{
		std::cout << "Valoarea taxei " << j + 1 << " este: ";
		intrare >> impozit.taxe[j];
	}

	return intrare;
}

std::ostream& operator<<(std::ostream& iesire, const Impozit& impozit)
{
	iesire << "Numarul de taxe care trebuie achitat este: " << impozit.nrTaxe << '\n';

	iesire << "Valorile taxelor care trebuiesc achitate sunt: ";

	for (auto j = 0; j < impozit.nrTaxe; j++)
		iesire << impozit.taxe[j] << "\t";

	iesire << '\n';

	return iesire;
}