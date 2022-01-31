//
// Created by Wenting Lou on 10/15/21.
//
#include <string>
using namespace std;
#ifndef LAB2_TRANSACTIONS_H
#define LAB2_TRANSACTIONS_H


class transactions {
private:
    string type;
    string date;
    int amount;
public:
    transactions(string type, string date, int amount);

    const string &getType() const;
    const string &getDate() const;
    int getAmount() const;

    void setType(const string &type);
    void setDate(const string &date);
    void setAmount(int amount);

    ~transactions();


};


#endif //LAB2_TRANSACTIONS_H
