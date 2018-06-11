#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class BankLoan
{
private:
	float sum;
	int date;
	float per_cent;
	string content;
	static float koef_annuiteta(BankLoan obj);
public:
	BankLoan();

	BankLoan(string content, float sum, int date, float per_cent);
	void static getLoanRepaymentSchedule(BankLoan obj);
	BankLoan operator=(BankLoan obj);
	string getLoanName();
	float getKoef_An();
	float getSum();
	int getDate();
	float getPerCent();
	string getContent();

	virtual ~BankLoan();
};