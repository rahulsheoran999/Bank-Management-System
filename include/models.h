#ifndef MODELS_H
#define MODELS_H

#include <string>
using namespace std;

struct Transaction {
    string accNo;
    string type;
    double amount;
    double balAfter;
    string timestamp;
    string note;
};

struct Account {
    string accNo;
    string holderName;
    string email;
    string phone;
    string accType;
    double balance;
    string pin;
    string createdOn;
    bool isActive;

    Account() : balance(0), isActive(true) {}
};

#endif