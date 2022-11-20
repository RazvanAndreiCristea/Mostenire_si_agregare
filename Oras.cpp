#include "Oras.h"

Oras::Oras()
{
	locuitori = nullptr;
	primar = nullptr;
	nrLocuitori = 0;
}

//Oras::Oras(const Locuitor* locuitori, const int nrLocuitori, const char* primar)
//{
//	this->nrLocuitori = nrLocuitori;
//
//	if (primar != nullptr)
//	{
//		this->primar = new char[strlen(primar) + 1];
//		strcpy(this->primar, primar);
//	}
//
//	if (locuitori != nullptr)
//	{
//		this->locuitori = new Locuitor[nrLocuitori];
//
//		for (auto j = 0; j < nrLocuitori; j++)
//			this->locuitori[j] = locuitori[j];
//	}
//}

Oras::~Oras()
{
	if (primar != nullptr)
		delete[] primar;

	if (locuitori != nullptr)
		delete[] locuitori;
}

void Oras::setPrimar(const char* primar)
{
	if (this->primar != nullptr)
		delete[] this->primar;

	if (primar != nullptr)
	{
		this->primar = new char[strlen(primar) + 1];
		strcpy(this->primar, primar);
	}
}

void Oras::adaugaLocuitori()
{
	int poz = 2;
	int taxe[3] = { 155, 300, 20 };

	Locuitor* extindere = new Locuitor[nrLocuitori + 1];

	for (auto j = poz - 1; j < nrLocuitori; j++)
		extindere[j + 1] = locuitori[j];

	extindere[poz - 1] = Locuitor("Georgiana", taxe, 3, "Strada Frigului nr.23", 3700);

	for (auto j = 0; j < poz - 1; j++)
		extindere[j] = locuitori[j];

	nrLocuitori++;

	if (locuitori != nullptr)
		delete[] locuitori;

	locuitori = new Locuitor[nrLocuitori];

	for (auto j = 0; j < nrLocuitori; j++)
		locuitori[j] = extindere[j];

	delete[] extindere;
}

std::istream& operator>>(std::istream& intrare, Oras& oras)
{
	std::cout << "Numarul de locuitori este: ";
	intrare >> oras.nrLocuitori;

	char* aux = new char[100];

	std::cout << "Introduceti un nume de primar: ";

	std::cin.ignore();
	std::cin.get(aux, 100);

	if (oras.primar != nullptr)
		delete[] oras.primar;

	oras.primar = new char[strlen(aux) + 1];
	strcpy(oras.primar, aux);

	delete[] aux;

	if (oras.locuitori != nullptr)
		delete[] oras.locuitori;

	oras.locuitori = new Locuitor[oras.nrLocuitori];

	std::cout << "\nCreati o lista de locuitori cu toate caracteristicile ei! \n\n";

	for (auto j = 0; j < oras.nrLocuitori; j++)
	{
		std::cout << "Locuitorul " << j + 1 << "\n\n";
		intrare >> (Locuitor&)oras.locuitori[j];
		std::cout << "\n===================================================================\n\n";
	}

	return intrare;
}

std::ostream& operator<<(std::ostream& iesire, const Oras& oras)
{
	iesire << "\n===================================================================\n\n";

	iesire << "Orasul are un numar de locuitori egal cu: " << oras.nrLocuitori << '\n';

	iesire << "Primarul orasului este: " << oras.primar << '\n';

	iesire << "\n===================================================================\n";

	iesire << "Locuitorii orasului vor aparea mai jos! \n";

	for (auto j = 0; j < oras.nrLocuitori; j++)
	{
		iesire << "Locuitorul " << j + 1 << " are mai jos urmatoarele informatii! \n";
		iesire << (Locuitor&)oras.locuitori[j];

		iesire << "\n\n===================================================================\n\n";
	}

	return iesire;
}

void sortareDupaTaxe(Oras& orasel)
{
	for (auto j = 0; j < orasel.nrLocuitori - 1; j++)
		for (auto jdex = j + 1; jdex < orasel.nrLocuitori; jdex++)
		{
			if (orasel.locuitori[j].totalTaxe() > orasel.locuitori[jdex].totalTaxe())
			{
				Locuitor aux(orasel.locuitori[j]);
				orasel.locuitori[j] = orasel.locuitori[jdex];
				orasel.locuitori[jdex] = aux;
			}
		}
}