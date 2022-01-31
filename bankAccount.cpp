//
// Created by Wenting Lou on 10/15/21.
//
#include <iostream>
#include "bankAccount.h"
#include "transactions.h"
#include <string>
#include <vector>
#include <ctime>
using namespace std;

bankAccount::bankAccount() {
    this->id = 0;
    this->password = "";
    this->balance = 0;
}
bankAccount::bankAccount(int account, string password, int balance) {
    this->id = account;
    this->password = password;
    this->balance = balance;
}

int bankAccount::getId() const {
    return id;
}

const string &bankAccount::getPassword() const {
    return password;
}

int bankAccount::getBalance() const {
    return balance;
}


void bankAccount::setId(int id) {
    bankAccount::id = id;
}

void bankAccount::setPassword(const string &password) {
    bankAccount::password = password;
}

void bankAccount::setBalance(int balance) {
    bankAccount::balance = balance;
}


void bankAccount::deposit(int deposit) {
    bankAccount::setBalance(bankAccount::balance + deposit);
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    transactions* trans = new transactions("deposit",dt, deposit);
    bankAccount::history.push_back(*trans);

}

void bankAccount::withdraw(int withdraw) {
    bankAccount::setBalance(bankAccount::balance - withdraw);
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    transactions* trans = new transactions("withdraw",dt, withdraw);
    bankAccount::history.push_back(*trans);
}

void bankAccount::displayHistory(int x) {
    cout << "Account Number: " << x << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    printf("%-40s |%-30s |%-20s\n", "Date", "Type", "Amount");
    cout << "-------------------------------------------------------------------------------------" << endl;
    for (transactions i : bankAccount::history) {

        printf("%-40s |%-30s |%-20d\n", i.getDate().c_str(), i.getType().c_str(), i.getAmount());
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

bankAccount::~bankAccount() {
    this->history.clear();
}
