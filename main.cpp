#include <iostream>
#include <string>
#include "stdlib.h"
#include "bankAccount.h"

string  gen_random(int len) {
    string s;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

int main() {
    int size = 10;
    bankAccount accounts[10];
    bankAccount* myAccount = new bankAccount(1, "123456", 5000);
    accounts[0] = *myAccount;
    for (int i = 1; i < size; i++) {
        int len = rand() % 25 + 8;
        string password = gen_random(len);
        bankAccount* newAccount = new bankAccount(i + 1, password, 5000);
        accounts[i] = *newAccount;
    }
    bool passed = false;
    cout << "Main Window" << endl;
    cout << "===========" << endl;
    int x;
    string password;
    while(!passed) {
        cout << "Enter your Account Number: ";
        cin >> x;
        cout << "Enter your password: ";
        cin >> password;
        if (x < 1 || x > size) {
            cout << "Invalid account" << endl;
            continue;
        } else {
            if (accounts[x - 1].getPassword().compare(password) == 0) {
                passed = true;
            } else {
                cout << "Wrong password" << endl;
            }
        }
    }
    cout << "Main Window" << endl;
    cout << "===========" << endl;
    bool exit = false;
    while(!exit) {
        int choice;
        bool validChoice = false;
        while (!validChoice) {
            cout << "Choose one of the following options: " << endl;
            cout << "(1) Show balance" << endl;
            cout << "(2) Deposit" << endl;
            cout << "(3) Withdraw" << endl;
            cout << "(4) Show all transactions" << endl;
            cout << "(5) Sign out" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice >= 1 && choice <= 5) {
                validChoice = true;
            } else {
                cout << "Invalid choice" << endl;
                cout << endl;
            }
        }
        if (choice == 1) {
            cout << "Main Window --> Show Balance" << endl;
            cout << "============================" << endl;
            cout << "Your balance is: " << accounts[x - 1].getBalance() << endl;
            cout << "----------------------------" << endl;
            cout << "Press enter to go back to the main window";
            cin.ignore();
            cin.ignore();
        } else if (choice == 2) {
            cout << "Main Window --> Deposit" << endl;
            cout << "============================" << endl;
            int depos;
            cout << "The amount you want to deposit: ";
            cin >> depos;
            while(depos < 0) {
                cout << "Invalid amount, please enter again: ";
                cin >> depos;
            }
            accounts[x - 1].deposit(depos);

            cout << "----------------------------" << endl;
            cout << "Well done. This was added to your balance successfully. Press enter to go back to the main window";
            cin.ignore();
            cin.ignore();
        } else if (choice == 3) {
            cout << "Main Window --> Withdraw" << endl;
            cout << "============================" << endl;
            int withd;
            cout << "The amount you want to withdraw: ";
            cin >> withd;
            while(withd > accounts[x].getBalance()) {
                cout << "Invalid amount, please enter again: ";
                cin >> withd;
            }
            accounts[x - 1].withdraw(withd);
            cout << "----------------------------" << endl;
            cout << "Please take your money. Press enter to go back to the main window";
            cin.ignore();
            cin.ignore();
        } else if (choice == 4){
            cout << "Main Window --> Show all transactions" << endl;
            cout << "=====================================" << endl;
            cout << endl;
            accounts[x - 1].displayHistory(x);
            cout << "Press enter to go back to the main window";
            cin.ignore();
            cin.ignore();
        } else {
            cout << "Thank you for using" << endl;
            exit = true;
        }
    }

    return 0;
}
