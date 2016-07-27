#include <iostream>
#include <iomanip>
#include "MortgageHeader.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
	bool quit = false;
	string fileName;
	ofstream fileOut;
	Mortgage mort1;

	do{
		cout << "Enter output filename: ";
		getline(cin, fileName);

		fileOut.open(fileName.c_str());

		while (!fileOut){
			cout << "ERROR creating output file. Try again: ";
			getline(cin, fileName);
			fileOut.open(fileName.c_str());
		}

		cout << "Enter the amount of the loan: ";
		double loanAmount = getNum();

		cout << "Enter the annual interest rate in decimal form (example .075 means 7.5%): ";
		double interestRate = getNum();

		while (interestRate > 1){
			cout << "ERROR: Interest rate must be between 0 and 1. Remember to use decimal form: ";
			double interestRate = getNum();
		}

		cout << "Enter the length of the loan in years: ";
		int numYears = getInt();

		mort1.setLoanAmount(loanAmount);
		mort1.setAnnualInterestRate(interestRate);
		mort1.calcMonthlyInterestRate();
		mort1.setTotalYearsToRepay(numYears);
		mort1.calcNumberOfPayments();
		mort1.calcTerm();

		cout << endl << fixed << showpoint << setprecision(2)
			<< "Loan Amount: $" << mort1.getLoanAmount() << endl
			<< setprecision(5)
			<< "Annual Interest Rate: " << mort1.getAnnualInterestRate() << endl
			<< noshowpoint << setprecision(0)
			<< "Years to repay: " << mort1.getTotalYearsToRepay() << endl
			<< showpoint << setprecision(2)
			<< "Monthly Payment: $" << mort1.calcMonthlyPayment() << endl
			<< "Total Pay Back: $" << mort1.calcTotalPayment() << endl << endl;
				
		mort1.outputPaymentSchedule(fileOut);
		
		cout << "Do you wish to process another loan? (Y/N): ";
		char c;
		cin >> c; cin.ignore(80, '\n');
		if (c == 'N' || c == 'n'){
			quit = true;
		}
	} while (!quit);
	system("pause");
	return 0;
}
