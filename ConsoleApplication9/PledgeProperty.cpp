#include "stdafx.h"
#include "PledgeProperty.h"

void PledgeProperty::InfoAboutCredit(string content, int date, float sum, float per_cent)
{
	BankLoan info(content, sum, date, per_cent);

	Credit.push_back(info);
}

PledgeProperty::PledgeProperty()
{
	BankLoan temp;
	PerCentCreditBet = temp.getPerCent();
}

PledgeProperty::~PledgeProperty()
{
}

Facility::Facility()
{
	FacilityRaiting = 0.54;

	GeneralSquare = 45000;
	UsefullSquare = 5000;
	Destination = "Homestead";
	Adress = "Pavlishev forest";
	GPS_Coordinates = "54.564660, 35.524297";
	Floor = 3;
	CountAccomondation = 24;
}

Facility::Facility(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinates, short int Floor, short int CountAccomondation) : Facility()
{
	this->GeneralSquare = GeneralSquare;
	this->UsefullSquare = UsefullSquare;
	this->Destination = Destination;
	this->Adress = Adress;
	this->GPS_Coordinates = GPS_Coordinates;
	this->Floor = Floor;
	this->CountAccomondation = CountAccomondation;
}

double Facility::SearchMinCreditValue()
{
	return (FacilityRaiting * (1 + ((LEVEL_INFLATION - LEVEL_WEAR) / 100))) / (1 + (PerCentCreditBet / 100) * KOEF);
}

double Facility::SearchMinMarketPriceValue(double sum)
{
	sum = (1 + (PerCentCreditBet / 100) * KOEF) / (FacilityRaiting * (1 + ((LEVEL_INFLATION - LEVEL_WEAR) / 100)));

	return sum;
}

void Facility::PrintInfo()
{
	cout << endl << "==============================" << endl;
	cout << "Facility: " << endl;
	cout << endl << "General square = " << GeneralSquare << endl;
	cout << "Usefull square = " << UsefullSquare << endl;
	cout << "Destination: " << Destination << endl;
	cout << "Adress: " << Adress << endl;
	cout << "GPS coordinates: " << GPS_Coordinates << endl;
	cout << "Count of floor = " << Floor << endl;
	cout << "Count of accomondation " << CountAccomondation << endl;
	cout << endl << "==============================" << endl;
}

bool Facility::CreditProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) < FacilityRaiting)
		return false;
	else
		return true;
}

bool Facility::CreditAdditioanalProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) > FacilityRaiting)
		return true;
	else
		return false;
}

double Facility::AdditionalProvideSum()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) > FacilityRaiting)
		return SearchMinMarketPriceValue(CreditSum) - FacilityRaiting;

	return EXIT_SUCCESS;
}

Facility::~Facility()
{
}

EarthArea::EarthArea()
{
	AreaRaiting = 0.64;

	GeneralSquare = 250000;
	UsefullSquare = 245000;
	Destination = "Production factory of oil";
	Adress = "Tirupati, Andhra Pradesh";
	GPS_Coordinates = "13.644460, 79.520892";
	Floor = 14;
	CountAccomondation = 548;
}

EarthArea::EarthArea(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinates, short int Floor, short int CountAccomondation) : EarthArea()
{
	this->GeneralSquare = GeneralSquare;
	this->UsefullSquare = UsefullSquare;
	this->Destination = Destination;
	this->Adress = Adress;
	this->GPS_Coordinates = GPS_Coordinates;
	this->Floor = Floor;
	this->CountAccomondation = CountAccomondation;
}

double EarthArea::SearchMinCreditValue()
{
	return (AreaRaiting * (1 + LEVEL_INFLATION / 100)) / (1 + (PerCentCreditBet / 100) * KOEF);
}

double EarthArea::SearchMinMarketPriceValue(double sum)
{
	sum = (1 + (PerCentCreditBet / 100) * KOEF) / (AreaRaiting * (1 + LEVEL_INFLATION / 100));

	return sum;
}

void EarthArea::PrintInfo()
{
	cout << endl << "==============================" << endl;
	cout << "Area: " << endl;
	cout << endl << "General square = " << GeneralSquare << endl;
	cout << "Usefull square = " << UsefullSquare << endl;
	cout << "Destination: " << Destination << endl;
	cout << "Adress: " << Adress << endl;
	cout << "GPS coordinates: " << GPS_Coordinates << endl;
	cout << "Count of floor = " << Floor << endl;
	cout << "Count of accomondation " << CountAccomondation << endl;
	cout << endl << "==============================" << endl;
}

bool EarthArea::CreditProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) < AreaRaiting)
		return false;
	else
		return true;
}

bool EarthArea::CreditAdditioanalProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) > AreaRaiting)
		return true;
	else
		return false;
}

double EarthArea::AdditionalProvideSum()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < Credit.size(); i++)
		CreditSum += Credit[i].getSum();

	if (SearchMinMarketPriceValue(CreditSum) > AreaRaiting)
		return SearchMinMarketPriceValue(CreditSum) - AreaRaiting;

	return EXIT_SUCCESS;
}


EarthArea::~EarthArea()
{
}