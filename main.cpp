//Developer: Edgar Ramirez Aburto
//Date: 26 November, 2023

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "InvestmentData.h"
#include "BalanceCalculations.h"

void menu() {
	InvestmentData userInvestment; // Creates a investmentdata object
	BalanceCalculations balanceCalculations; // Creates a balancecalcalations object

	// local variables required
	double initialAmount;
	double monthlyDeposit;
	double interest;
	int years;
	string choice;	
	bool running = true;

	do {

		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "**********" << " Data Input" << "*************" << endl;

		cout << "Initial Investment Amount: ";
		cin >> initialAmount;
		cout << endl;

		cout << "Monthly Deposit: ";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: ";
		cin >> interest;
		cout << endl;

		cout << "Number of years: ";
		cin >> years;
		cout << endl;

		userInvestment.setInitialInvestment(initialAmount);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setNumOfYears(years);

		// displaying user inputs
		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "**********" << " Data Input" << "*************" << endl;
		cout << "Initial Investment Amount: $"  << userInvestment.getInitialInvestment() << endl;
		cout << "Monthly Deposit: $" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: %" << userInvestment.getAnnualInterest() << endl;
		cout << "Number of years: " << userInvestment.getNumOfYears() << endl;

		cout << endl;
		system("pause");


		// display balance and intrest earned
		balanceCalculations.BalanceWithoutMonthlyDeposits(userInvestment);
		balanceCalculations.BalanceWithMonthlyDeposits(userInvestment);

		cout << endl;

		// getting user input to stop or continue
		cout << "Continue? Enter:(y/n)" << endl;
		cin >> choice;
		if (choice == "n") {
			running = false;
		}
		else {
			continue;
		}

	} while (running == true);
}

int main() {
	menu();
}