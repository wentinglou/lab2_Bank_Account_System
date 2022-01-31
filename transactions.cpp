//
// Created by Wenting Lou on 10/15/21.
//

#include "transactions.h"
#include <string>

transactions::transactions(string type, string date, int amount) {
    this->type = type;
    this->date = date;
    this->amount = amount;
}
const string &transactions::getType() const {
    return type;
}

const string &transactions::getDate() const {
    return date;
}

void transactions::setType(const string &type) {
    transactions::type = type;
}

void transactions::setDate(const string &date) {
    transactions::date = date;
}

int transactions::getAmount() const {
    return amount;
}

void transactions::setAmount(int amount) {
    transactions::amount = amount;
}

transactions::~transactions() {

}
