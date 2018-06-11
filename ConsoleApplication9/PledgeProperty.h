#pragma once
#include "BankLoan.h"

class PledgeProperty
{
private:
	double sumPledgeProperty;
	double marketPrice;
protected:
	BankLoan * credit;
	vector<BankLoan> Credit;

	float PerCentCreditBet;    //процентная ставка по кредиту
	virtual void InfoAboutCredit(string content, int date, float sum, float per_cent);  //вывод информации 
public:
	PledgeProperty();

	virtual double SearchMinCreditValue() = 0;
	virtual double SearchMinMarketPriceValue(double sum) = 0;

	virtual ~PledgeProperty();
};

class Facility : public PledgeProperty
{
private:
	double FacilityRaiting;
protected:
	int GeneralSquare; //общая площадь
	int UsefullSquare; //полезная площадь
	string Destination; //назначение
	string Adress; //адресс
	string GPS_Coordinates; //GPS координаты
	short int Floor;  //количество этажей
	short int CountAccomondation;  //количество помещений
public:
	Facility();
	Facility(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinate, short int Floor, short int CountAccomondation);

	double SearchMinCreditValue();
	double SearchMinMarketPriceValue(double sum);
	void PrintInfo();
	bool CreditProvide();
	bool CreditAdditioanalProvide();
	double AdditionalProvideSum();

	virtual ~Facility();
};

class EarthArea : public PledgeProperty
{
private:
	double AreaRaiting;  //оценка земельного участка
protected:
	enum{ Residential, General, Buiseness };
	int GeneralSquare; //общая площадь
	int UsefullSquare; //полезная площадь
	string Destination; //назначение
	string Adress; //адресс
	string GPS_Coordinates; //GPS координаты
	short int Floor;  //количество этажей
	short int CountAccomondation;  //количество помещений
public:
	EarthArea();
	EarthArea(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinate, short int Floor, short int CountAccomondation);

	double SearchMinCreditValue();
	double SearchMinMarketPriceValue(double sum);
	void PrintInfo();
	bool CreditProvide();
	bool CreditAdditioanalProvide();
	double AdditionalProvideSum();

	virtual ~EarthArea();
};