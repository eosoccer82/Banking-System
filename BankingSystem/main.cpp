//*****************************************************************
//Author.....: Eric Ortega
//Assignment.: Banking System Project
//Description: We are to create a simulated Banking System project
//             that allows user to deposit and withdraw money, check
//             their balance, and exit the program.
//*****************************************************************


#include <iostream>
#include <cassert>

using namespace std;

int main() {
    double balance = 0.0;
    int choice;
    bool running = true;

    while (running) {
        // Display menu
        cout << "=== Banking System Menu ===" <<endl;
        cout << "1. Deposit Money" <<endl;
        cout << "2. Withdraw Money" <<endl;
        cout << "3. Check Balance" <<endl;
        cout << "4. Exit" <<endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: { // Deposits Money
                double deposit;
                cout << "Enter amount to deposit: ";
                cin >> deposit;

                if (deposit > 0) {
                    balance += deposit;
                    cout << "Successfully deposited $" << deposit << "." <<endl;
                } else {
                    cout << "Invalid deposit amount. Please enter a positive value." <<endl;
                }
                break;
            }
            case 2: { // Withdraws Money
                double withdraw;
                cout << "Enter amount to withdraw: ";
                cin >> withdraw;

                if (withdraw > 0 && withdraw <= balance) {
                    balance -= withdraw;
                    cout << "Successfully withdrew $" << withdraw << "." <<endl;
                } else if (withdraw <= 0) {
                    cout << "Invalid amount. Deposit must be positive." <<endl;
                } else {
                    cout << "Insufficient funds! Withdrawal failed." << balance << "." <<endl;
                }
                break;
            }
            case 3: { // Checks Balance
                cout << "Your current balance is $" << balance << "." <<endl;
                break;
            }
            case 4: { // Exits
                cout << "Exiting the banking system. Thank you for using our service!" <<endl;
                running = false;
                break;
            }
            default: { // Invalid Option
                cout << "Invalid option! Please choose a valid menu option." <<endl;
                break;
            }
        }

        // Assertion to make sure balance is never negative
        assert(balance >= 0 && "Balance should never be negative.");
    }

    return 0;
}