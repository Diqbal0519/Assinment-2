//
//  main.cpp
//  Assinment 2
//
//  Created by Duha Iqbal on 2/8/24.
//

#include <iostream>
#include <iomanip>
using namespace std;

void input(double &P, double &APR, int &n); //gets user input for balance, annual percent rate, and number of months
double monthly_interest_rate(double APR);// calculates the monthly interest rate
double monthly_payment_amount(double p, double r, int n);//calculates the monthly fixed payments
void monthly_interest(double P, double r, double &interest);//calculates the interest for each month
void monthly_principal_amount(double &interest, double P, double &principal); // calculates the principal amount for each month
void total_accumulated(double &total_payment, double &total_interest, double interest);// updates the total payments and interest
void table_output(double P_start, double APR, int n); // displays table of monthly information
void summary_output(); // displays overall loan information

int main() {
    double principal_amount, annual_percentage_rate;
    int number_of_months, repeat;
    do{
        input(principal_amount, annual_percentage_rate, number_of_months);
        table_output(principal_amount, annual_percentage_rate, number_of_months);
        cout << "Do you want to calculate another loan? (0 for no, 1 for yes): ";
        cin >> repeat;
    }while(repeat == 1);
    return 0;
}

void input(double &P, double &APR, int &n){
    cout << "Enter the original loan amount(P) in dollars and cents: $";
    cin >> P;
    
    cout << "Enter the annual percentage rate: ";
    cin >> APR;
    
    cout << "Enter the loan term in months: ";
    cin >> n;
}

double monthly_interest_rate(double APR){
    return pow(1 + (APR / 100), (1.0 / 12)) - 1;
}

double monthly_payment_amount(double p, double r, int n){
    return p * ((r * pow((1 + r) , n)) / (pow((1 + r) , n) - 1));
}

void monthly_interest(double P, double r, double &interest){
     interest = P * r;
}


void monthly_principal_amount(double &interest, double P, double &principal){
    principal = interest + P;
}

void total_accumulated(double &total_payment, double &total_interest, double APR, double m, double r, int n, double P){
    m = monthly_payment_amount(P, r, n);
    r = monthly_interest_rate(APR);
    total_payment = m * n;
    total_interest = total_payment - P;
}

void table_output(double P, double APR, int n){
    double monthly_percentage_rate, total_payment = 0.0, total_interest = 0.0, interest, principal, P_start, P_end = 0;
    monthly_percentage_rate = monthly_interest_rate(APR);
    cout << "Month\tBeginning Balance\tInterest\tPrincipal\tEnding Balance" << endl;
    for(int month = 1; month <= n; month++){
        if(month == 1){
            monthly_interest(P, monthly_percentage_rate, interest);
            principal = monthly_payment_amount(P, monthly_percentage_rate, n) - interest;
            total_accumulated(total_payment, total_interest, APR, monthly_payment_amount(P, monthly_percentage_rate, n), monthly_percentage_rate, n, P);
            P_end = P - principal;
            cout << month << "\t\t$" << fixed << setprecision(2) << P << "\t\t\t$ " << interest << "\t$" << principal << "\t\t\t$" << P_end << endl;
        }else{
            P_start = P_end;
            monthly_interest(P_end, monthly_percentage_rate, interest);
            principal = monthly_payment_amount(P, monthly_percentage_rate, n) - interest;
            total_accumulated(total_payment, total_interest, APR, monthly_payment_amount(P, monthly_percentage_rate, n), monthly_percentage_rate, n, P);
            P_end -= principal;
            
            cout << month << "\t\t$" << fixed << setprecision(2) << P_start << "\t\t\t$ " << interest << "\t$" << principal << "\t\t\t$" << P_end << endl;
        }
    }
    cout << "Payments Every Month: $" << fixed << setprecision(2) << monthly_payment_amount(P, monthly_percentage_rate, n) << endl;
    cout << "Total Payments: " << fixed << setprecision(2) << total_payment << endl;
    cout << "Total Interest: " << fixed << setprecision(2) << total_interest << endl;
}
