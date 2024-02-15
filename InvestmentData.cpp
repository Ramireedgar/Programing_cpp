#include <iostream>
using namespace std;

#include "InvestmentData.h"

// initialize all the public methods of investmentdata
void InvestmentData::setInitialInvestment(double t_initialInvestment) { // setter for initial investment
	m_initialInvestment = t_initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double t_monthlyDeposit) { // setter for monthly desposits
	m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double t_annualInterest) { // setter for intrest rate
	m_annualInterest = t_annualInterest;
}

void InvestmentData::setNumOfYears(int t_numOfYears) { // setter for num of years
	m_numOfYears = t_numOfYears;
}

void InvestmentData::setTotalWithDeposits(double t_amount) { // setter for total with deposits
	m_totalWithDeposits += t_amount;
}

void InvestmentData::setTotalWithoutDeposits(double t_amount) { // setter for total without deposits
	m_totalWithoutDeposits += t_amount;
}

double InvestmentData::getInitialInvestment() { // getter for initial investment
	return m_initialInvestment;
}

double InvestmentData::getMonthlyDeposit() { // getter for monthlydeposit
	return m_monthlyDeposit;
}

double InvestmentData::getAnnualInterest() { // getter for annual intrest
	return m_annualInterest;
}

int InvestmentData::getNumOfYears() { // getter for num of years
	return m_numOfYears;
}

double InvestmentData::getTotalWithDeposits() { // getter for total with deposits
	return m_totalWithDeposits;
}

double InvestmentData::getTotalWithoutDeposits() { // getter for total without deposits
	return m_totalWithoutDeposits;
}

double InvestmentData::calcInterestWithDeposits() { // calculates interest with deposits
	return ((m_totalWithDeposits) * ((m_annualInterest / 100) / 12));
}

double InvestmentData::calcInterestWithoutDeposits() { // calculates interest without deposits
	return ((m_totalWithoutDeposits) * ((m_annualInterest / 100) / 12));
}