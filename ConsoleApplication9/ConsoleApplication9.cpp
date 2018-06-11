#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <ctime>
#include <list>
#include "PledgeProperty.h"

using namespace std;

int main()
{
	srand(__time64_t(NULL));
	setlocale(LC_ALL, "rus");

	list<PledgeProperty*>add;
	Facility fac;
	EarthArea ear;
	
	add.push_back(new EarthArea(250000, 245000, "Production factory of oil", "Tirupati, Andhra Pradesh", "13.644460, 79.520892", 14, 548));
	fac.PrintInfo();
	ear.PrintInfo();

    return EXIT_SUCCESS;
}

