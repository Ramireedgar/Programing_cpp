#ifndef INVESTMENTDATA_H
#define INVESTMENTDATA_H

//this class gathers and sets all the private class memebers as well as allow for getting private member data
class InvestmentData {
public:
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterest(double t_annualInterest);
	void setNumOfYears(int t_years);
	void setTotalWithDeposits(double t_amount);
	void setTotalWithoutDeposits(double t_amount);
	double getInitialInvestment();
	double getMonthlyDeposit();
	double getAnnualInterest();
	int getNumOfYears();
	double getTotalWithDeposits();
	double getTotalWithoutDeposits();
	double calcInterestWithDeposits();
	double calcInterestWithoutDeposits();
private:
	double m_initialInvestment = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_annualInterest = 0.0;
	int m_numOfYears = 0;
	double m_totalWithDeposits = 0.0;
	double m_totalWithoutDeposits = 0.0;
};
#endif