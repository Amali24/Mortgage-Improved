#ifndef MORTGAGEHEADER_H_INCLUDED
#define MORTGAGEHEADER_H_INCLUDED
#include <iostream>

using namespace std;

class Mortgage
{
public:    Mortgage();

           Mortgage(double, double, int);

private:
    double loanAmount;
    double annualInterestRate;
    double monthlyInterestRate;
    double term;
    int totalYearsToRepay;
    int numberOfPayments;

public:

           ///SETTERS///
    void setLoanAmount(double);
    void setAnnualInterestRate(double);
    void calcMonthlyInterestRate();
    void setTotalYearsToRepay(int);
    void calcNumberOfPayments();

           ///GETTERS///
    double getLoanAmount(){return loanAmount;}
    double getAnnualInterestRate(){return annualInterestRate;}
    double getMonthlyInterestRate(){return monthlyInterestRate;}
    int getTotalYearsToRepay(){return totalYearsToRepay;}
    int getNumberOfPayments(){return numberOfPayments;}
    double getTerm(){return term;}

    double calcMonthlyPayment();
    void calcTerm();
    double calcTotalPayment();
	void outputPaymentSchedule(ostream&);

};

double getNum();
int getInt();

#endif // MORTGAGEHEADER_H_INCLUDED
