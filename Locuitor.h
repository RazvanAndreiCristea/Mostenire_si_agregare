#pragma once
#include "Impozit.h"
#include "Locuinta.h"

class Locuitor : public Impozit, public Locuinta
{
	char* nume;

public:

	Locuitor();

	Locuitor(const char*, const int*, const int, const char*, const int);

	Locuitor(const Locuitor&);

	~Locuitor();

	Locuitor& operator=(const Locuitor&);

	friend std::istream& operator>>(std::istream&, Locuitor&);

	friend std::ostream& operator<<(std::ostream&, const Locuitor&);
};