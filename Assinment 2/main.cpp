//
//  main.cpp
//  Assinment 2
//
//  Created by Duha Iqbal on 2/8/24.
//

#include <iostream>
using namespace std;

void input(double &P, double &APR, int &n);
double monthly_interest_rate(double APR);
double monthly_payment_amount(double p, double r, int n);
void monthly_principal_balance();
void total_accumulated();
void table_output();
void summary_output();

int main() {
    double principal_amount, annual_percentage_rate, monthly_percentage_rate;
    int number_of_months;
    input(principal_amount, annual_percentage_rate, number_of_months);
    //cout << principal_amount << endl << annual_percentage_rate << endl << number_of_months;
    monthly_percentage_rate = monthly_interest_rate(annual_percentage_rate);
    //cout << monthly_percentage_rate;
    
    return 0;
}

void input(double &P, double &APR, int &n){
    cout << "Enter the original loan amount(P) in dollars and cents: ";
    cin >> P;
    
    cout << "Enter the annual percentage rate: ";
    cin >> APR;
    
    cout << "Enter the loan term in months: ";
    cin >> n;
}

double monthly_interest_rate(double APR){
    return pow(1 + (APR / 100), (1.0 / 12)) - 1;
}
