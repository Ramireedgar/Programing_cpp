#ifndef DATACALCULATIONS_H
#define DATACALCULATIONS_H

#include "InvestmentData.h"

//this class calculates the users balance
class BalanceCalculations {
public:
	void BalanceWithoutMonthlyDeposits(InvestmentData t_userInvestment);
	void BalanceWithMonthlyDeposits(InvestmentData t_userInvestment);
};
#endif 
