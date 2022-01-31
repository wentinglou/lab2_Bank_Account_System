//
// Created by Wenting Lou on 10/15/21.
//
#include <string>
#include <vector>
#include "transactions.h"
using namespace std;
#ifndef LAB2_BANKACCOUNT_H
#define LAB2_BANKACCOUNT_H


class bankAccount {
private:
    int id;
    string password;
    int balance;
    std::vector<transactions> history;

public:
    bankAccount();
    bankAccount(int id, string password, int balance);
    const string &getPassword() const;
    int getBalance() const;
    int getId() const;

    void setId(int id);
    void setPassword(const string &password);
    void setBalance(int balance);

    ~bankAccount();

    void deposit(int deposit);
    void withdraw(int withdraw);
    void displayHistory(int x);


};


#endif //LAB2_BANKACCOUNT_H
