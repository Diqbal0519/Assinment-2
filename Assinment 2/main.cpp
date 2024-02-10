/*
 COP3014: Programmming II
 Assignment 2 - Creating a loan calculator, which calculates the monthly payments and interest of a loan, using user-defiend and library functions
 Duha Iqbal
 02/09/2024
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void input(double &P, double &APR, int &n); //gets user input for balance, annual percent rate, and number of months
double monthly_interest_rate(double APR);// calculates the monthly interest rate
double monthly_payment_amount(double p, double r, int n);//calculates the monthly fixed payments
void monthly_interest(double P, double r, double &interest);//calculates the interest for each month
void monthly_principal_amount(double &interest, double m, double &principal); // calculates the principal amount for each month
void total_accumulated(double &total_payment, double &total_interest, double r, int n, double P);// updates the total payments and interest
void loan_output(double P, double APR, int n); // displays loan information

int main() {
    double principal_amount, annual_percentage_rate;
    int number_of_months, repeat;
    //welcome user to program
    cout << "Welcome to the loan summary calculator!" << endl << endl;
    do{
        //get loan information from user
        input(principal_amount, annual_percentage_rate, number_of_months);
        //display loan summary
        loan_output(principal_amount, annual_percentage_rate, number_of_months);
        //ask user if they want to calculate a new loan
        cout << "Do you want to calculate another loan? (0 for no, 1 for yes): ";
        cin >> repeat;
    }while(repeat == 1);
    return 0;
}

void input(double &P, double &APR, int &n){
    cout << "Enter the original loan amount(P) in dollars and cents(xx.xx): $";
    cin >> P;
    
    cout << "Enter the annual percentage rate(xx.xx): ";
    cin >> APR;
    
    cout << "Enter the loan term in months: ";
    cin >> n;
}

double monthly_interest_rate(double APR){
    // calculates the monthly interest rate
    return pow(1 + (APR / 100), (1.0 / 12)) - 1;
}

double monthly_payment_amount(double p, double r, int n){
    // calculates the monthly fixed payments
    return p * ((r * pow((1 + r) , n)) / (pow((1 + r) , n) - 1));
}

void monthly_interest(double P, double r, double &interest){
    //calculates the interest for each month
     interest = P * r;
}


void monthly_principal_amount(double &interest, double m, double &principal){
    // calculates the principal amount for each month
    principal = m - interest;
}

void total_accumulated(double &total_payment, double &total_interest, double r, int n, double P){
    //calculates and updates the total payments and interest
    double m = monthly_payment_amount(P, r, n);
    total_payment = m * n;
    total_interest = total_payment - P;
}

void loan_output(double P, double APR, int n){
    //displays loan summary
    double r, m, total_payment = 0.0, total_interest = 0.0, interest, principal, P_start, P_end = P;
    //saves the monthly interest rate to the variable r
    r = monthly_interest_rate(APR);
    //saves the monthly payment amount to the variable m
    m = monthly_payment_amount(P, r, n);
    cout << "Month\tBeginning Balance\tInterest\tPrincipal\tEnding Balance" << endl;
    for(int month = 1; month <= n; month++){
        //begining balance
        P_start = P_end;
        //interest
        monthly_interest(P_end, r, interest);
        //principal
        monthly_principal_amount(interest, m, principal);
        //total payments and interest
        total_accumulated(total_payment, total_interest, r, n, P);
        //end balance
        P_end -= principal;
        
        //displays loan monthly payment information in table format
        cout << month << "\t\t$" << fixed << setprecision(2) << P_start << "\t\t\t$ " << interest << "\t\t$" << principal << "\t\t$" << P_end << endl;
    }
    //display loan summary information
    cout << endl << "Payments Every Month: $" << fixed << setprecision(2) << m << endl;
    cout << "Total Payments: " << fixed << setprecision(2) << total_payment << endl;
    cout << "Total Interest: " << fixed << setprecision(2) << total_interest << endl;
}
