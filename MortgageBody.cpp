#include "MortgageHeader.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

Mortgage::Mortgage()
{
    setLoanAmount(0);
    setAnnualInterestRate(0);
    setTotalYearsToRepay(0);
}

Mortgage::Mortgage(double amount, double apr, int years)
{
    setLoanAmount(amount);
    setAnnualInterestRate(apr);
    setTotalYearsToRepay(years);
}


///SETTERS///
void Mortgage::setLoanAmount(double amount)
{
    if (amount < 0) amount = 0;
    loanAmount = amount;
}
void Mortgage::setAnnualInterestRate(double apr)
{
    if (apr < 0) apr = 0;
    annualInterestRate = apr;
    this->calcMonthlyInterestRate();
}

void Mortgage::calcMonthlyInterestRate()
{
    monthlyInterestRate = annualInterestRate / 12;
}

void Mortgage::setTotalYearsToRepay(int years)
{
    if (years < 0) years = 0;
    totalYearsToRepay = years;
    this->calcNumberOfPayments();
}

void Mortgage::calcNumberOfPayments()
{
    numberOfPayments = totalYearsToRepay * 12;
}

void Mortgage::calcTerm()
{
    this->term = pow((1 + this->monthlyInterestRate), this->numberOfPayments);
}

double Mortgage::calcMonthlyPayment()
{
    double monthlyPayment;

    monthlyPayment = (loanAmount * monthlyInterestRate * term) / (term - 1);

    return monthlyPayment;
}

double Mortgage::calcTotalPayment()
{
    return calcMonthlyPayment() * numberOfPayments;
}

void Mortgage::outputPaymentSchedule(ostream& out)
{
	out << endl << fixed << showpoint << setprecision(2)
		<< "Loan Amount: $" << getLoanAmount() << endl
		<< setprecision(5)
		<< "Annual Interest Rate: " << getAnnualInterestRate() << endl
		<< "Monthly interest rate = " << getMonthlyInterestRate() << endl
		<< "Term = " << getTerm() << endl
		<< noshowpoint << setprecision(0)
		<< "Years to repay: " << getTotalYearsToRepay() << endl
		<< showpoint << setprecision(2)
		<< "Monthly Payment: $" << calcMonthlyPayment() << endl
		<< "Total Pay Back: $" << calcTotalPayment() << endl << endl;

	out << " Pmt#    Payment Amount          Interest   Contrib to Principle Remaining balance" << endl;
	
	double remBalance = getLoanAmount();
	double monthlyPayment = calcMonthlyPayment();
	double contribPrin, interestPaid;
	

	for (int i = 0; i < getNumberOfPayments(); i++)
	{
		interestPaid = monthlyInterestRate * remBalance;
		contribPrin = monthlyPayment - interestPaid;
		out << setw(4) << i + 1 << setw(18) << monthlyPayment << setw(18)
			<< interestPaid << setw(23) << contribPrin;
		remBalance -= contribPrin;
		out << remBalance << endl;
	}
}

double getNum()
{
    double x;		// Holds user input and will be returned
    while (!(cin >> x))  // While cin object is broken
    {
        cin.clear();
        cin.ignore(80, '\n'); // Clear it and remove everything from buffer
        cout << "ERROR: PLEASE PROVIDE A NUMBER. TRY AGAIN: "; // And print error message
    }
    cin.ignore(80, '\n'); // Clear keyboard buffer
    return x;	// And return validated number
}

int getInt()
{
    double x = getNum(); // validate input is number
    while (int(x) != x)  // while not int
    {
        cout << "ERROR: INPUT MUST BE INTEGER. TRY AGAIN: "; // print error
        x = getNum(); // get new number
    }
    return int(x); // return valid int (typecasted to supress errors)
}
