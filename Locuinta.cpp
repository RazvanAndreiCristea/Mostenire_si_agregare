#include "Locuinta.h"

Locuinta::Locuinta()
{
	adresa = nullptr;
	valoare = 0;
}

Locuinta::Locuinta(const char* adresa, const int valoare)
{
	this->valoare = valoare;

	if (adresa != nullptr)
	{
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
	}
}

Locuinta::Locuinta(const Locuinta& locuinta)
{
	this->valoare = locuinta.valoare;

	if (locuinta.adresa != nullptr)
	{
		this->adresa = new char[strlen(locuinta.adresa) + 1];
		strcpy(this->adresa, locuinta.adresa);
	}
}

Locuinta::~Locuinta()
{
	if (adresa != nullptr)
		delete[] adresa;
}

Locuinta& Locuinta::operator=(const Locuinta& locuinta)
{
	if (this != &locuinta)
	{
		this->valoare = locuinta.valoare;

		if (adresa != nullptr)
			delete[] adresa;

		if (locuinta.adresa != nullptr)
		{
			this->adresa = new char[strlen(locuinta.adresa) + 1];
			strcpy(this->adresa, locuinta.adresa);
		}
	}

	return *this;
}

std::istream& operator>>(std::istream& intrare, Locuinta& locuinta)
{
	std::cout << "Valoarea locuintei este: ";
	intrare >> locuinta.valoare;

	char* aux = new char[100];

	std::cout << "Introduceti o adresa: ";

	std::cin.ignore();
	std::cin.get(aux, 100);

	if (locuinta.adresa != nullptr)
		delete[] locuinta.adresa;

	locuinta.adresa = new char[strlen(aux) + 1];
	strcpy(locuinta.adresa, aux);

	delete[] aux;

	return intrare;
}

std::ostream& operator<<(std::ostream& iesire, const Locuinta& locuinta)
{
	iesire << "Locuinta are o valoare de: " << locuinta.valoare << " lei \n";

	iesire << "Adresa locuintei este: " << locuinta.adresa << '\n';

	return iesire;
}