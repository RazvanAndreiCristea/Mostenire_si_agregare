#include "Locuitor.h"

Locuitor::Locuitor() : Impozit(), Locuinta()
{
	nume = nullptr;
}

Locuitor::Locuitor(const char* nume, const int* taxe, const int nrTaxe, const char* adresa, const int valoare) : Impozit(taxe, nrTaxe), Locuinta(adresa, valoare)
{
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
}

Locuitor::Locuitor(const Locuitor& locuitor) : Impozit(locuitor), Locuinta(locuitor)
{
	if (locuitor.nume != nullptr)
	{
		this->nume = new char[strlen(locuitor.nume) + 1];
		strcpy(this->nume, locuitor.nume);
	}
}

Locuitor::~Locuitor()
{
	delete[] nume;
}

Locuitor& Locuitor::operator=(const Locuitor& locuitor)
{
	if (this != &locuitor)
	{
		Impozit::operator=(locuitor); // sau (Impozit&)(*this) = locuitor;
		Locuinta::operator=(locuitor);

		if (this->nume != nullptr)
			delete[] this->nume;

		if (locuitor.nume != nullptr)
		{
			this->nume = new char[strlen(locuitor.nume) + 1];
			strcpy(this->nume, locuitor.nume);
		}
	}

	return *this;
}

std::istream& operator>>(std::istream& intrare, Locuitor& locuitor)
{
	intrare >> (Locuinta&)locuitor; //operator>>(intrare, (Locuinta&) locuitor);
	intrare >> (Impozit&)locuitor;

	char* aux = new char[100];

	std::cout << "Introduceti un nume: ";

	std::cin.ignore();
	std::cin.get(aux, 100);

	if (locuitor.nume != nullptr)
		delete[] locuitor.nume;

	locuitor.nume = new char[strlen(aux) + 1];
	strcpy(locuitor.nume, aux);

	delete[] aux;

	return intrare;
}

std::ostream& operator<<(std::ostream& iesire, const Locuitor& locuitor)
{
	iesire << (Locuinta&)locuitor;
	iesire << (Impozit&)locuitor;

	iesire << "Numele locuitorului este: " << locuitor.nume << '\n';

	return iesire;
}