#include <iostream>
#include <iomanip>
using namespace std;

// displays and formats details returned from withoutMontlhyDeposit and WithMonthlyDeposit functions
void printDetails(int year, double yearEndBalance, double interestEarned) {

    cout << setw(6) << year
        << setw(22) << "$" << fixed << setprecision(2) << yearEndBalance
        << setw(28) << "$" << fixed << setprecision(2) << interestEarned << endl;
}

// used to get values without consideration for monthly deposit
void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

    // keeps track of investment value 
    double balance = initialInvestment;
    // calculates monthly interest rate
    double monthlyInterestRate = (interestRate / 100.0) / 12.0;
    // loops through each year
    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarnedThisYear = 0.0;
        // loops through all 12 months
        for (int month = 1; month <= 12; ++month) {
            // monthly interest is calculated as the product of balance and monthly interest rate
            double monthlyInterest = balance * monthlyInterestRate;
            // monthly interest is added to total balance
            balance += monthlyInterest;
            // monthly interest is also added to total interest eanred in the year
            interestEarnedThisYear += monthlyInterest;
        }
        //calls printDetails function to output these finanical details for each year
        printDetails(year, balance, interestEarnedThisYear);
    }


}
// used to get values with known monthly deposit
void balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {

    double balance = initialInvestment;
    double monthlyInterestRate = (interestRate / 100.0) / 12.0;
    double interestEarnedThisYear;
    double monthlyInterest;

    // loops through the number of years inputted
    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarnedThisYear = 0.0;
        // loops through each month in the year 
        for (int month = 1; month <= 12; ++month) {
            // adds the inputted monthly deposit amount to the balance
            balance += monthlyDeposit;
            // monthly interest is calculated by multiplying the balance and monthly rate
            monthlyInterest = balance * monthlyInterestRate;
            // this value is added to balance
            balance += monthlyInterest;
            // the monthly interest value is also added to the total interest earned this year
            interestEarnedThisYear += monthlyInterest;
        }
        // calls the print details function to display financial details for each year in the loop
        printDetails(year, balance, interestEarnedThisYear);
    }

}

int main() {
    double initialInvestment, monthlyDeposit, interestRate;
    int numberOfYears;

    cout << "******************************" << endl;
    cout << "********* Data Input *********" << endl;
    // gets values from user 
    cout << "initial Investment Amount: " << endl;
    cin >> initialInvestment;
    cout << "Monthly Deposit: " << endl;
    cin >> monthlyDeposit;
    cout << "Annual Interest: " << endl;
    cin >> interestRate;
    cout << "Number of Years: " << endl;
    cin >> numberOfYears;

    //waits for user to press any key to display results
    cout << "Press Any Key to continue . . .";
    cin.ignore();
    cin.get();
    // displays information from the calculateBalanceWithoutMonthlyDeposit function and formats it into a readable table
    cout << "  Balance and Interest Additional Monthly Deposits  " << endl;
    cout << "=======================================================================" << endl;
    cout << setw(6) << "Year" << setw(22) << "Year End Balance" << setw(28) << "Year End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

    // displays information from the balanceWithMonthlyDeposit
    cout << "  Balance and Interest With Additional Monthly Deposits  " << endl;
    cout << "=======================================================================" << endl;
    cout << setw(6) << "Year" << setw(22) << "Year End Balance" << setw(28) << "Year End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    return 0;
}