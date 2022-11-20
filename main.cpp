#include "Oras.h"

int main()
{
	Oras o;

	std::cin >> o;

	std::cout << o;

	sortareDupaTaxe(o);

	std::cout << "\nLocuitorii din oras sortati dupa taxe vor aparea mai jos! \n\n";

	std::cout << o;

	std::cout << "\nAdaugam un nou locuitor pe a 2 a pozitie! \n";

	o.adaugaLocuitori();

	std::cout << o;

	o.setPrimar("Nicusor Dan");

	std::cout << "\nAm schimbat numele primarului din oras! \n";

	std::cout << o;

	return 0;
}