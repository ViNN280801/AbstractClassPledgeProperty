#include "stdafx.h"
#include "BankLoan.h"

float BankLoan::koef_annuiteta(BankLoan obj)
{
	float koef;

	koef = ((obj.per_cent / 12) * pow(1 + (obj.per_cent / 12), obj.date)) / (pow(1 + (obj.per_cent / 12), obj.date) - 1);

	float monthAnunPayment = koef * obj.sum;
	return monthAnunPayment;
}

BankLoan::BankLoan()
{
	sum = 0;
	date = 0;
	per_cent = 0.0;
	content = "";
}

BankLoan::BankLoan(string content, float sum, int date, float per_cent)
{
	this->content = content;
	this->sum = sum;
	this->date = date;
	this->per_cent = per_cent;
}


void BankLoan::getLoanRepaymentSchedule(BankLoan obj)
{
	float OverPayment = koef_annuiteta(obj) * obj.date;
	OverPayment = OverPayment - obj.sum;

	cout << "Loan name: " << obj.content << endl;
	cout << "Loan sum: " << obj.sum << endl;
	cout << "---------- ---------- ---------- " << endl;
	cout << "Month       Amount " << endl;

	for (short int i = 1; i <= obj.date; i++)
		cout << i << "       " << koef_annuiteta(obj) << endl;

	cout << "---------- ---------- ---------- " << endl;
	cout << "Overpayment = " << OverPayment << endl;
}

BankLoan BankLoan::operator=(BankLoan obj)
{
	sum = obj.sum;
	date = obj.date;
	per_cent = obj.per_cent;
	content = obj.content;

	return *this;
}

string BankLoan::getLoanName()
{
	return content;
}

float BankLoan::getKoef_An()
{
	return koef_annuiteta(*this);
}

float BankLoan::getSum()
{
	return sum;
}

int BankLoan::getDate()
{
	return date;
}

float BankLoan::getPerCent()
{
	return per_cent;
}

string BankLoan::getContent()
{
	return content;
}


BankLoan::~BankLoan()
{
}