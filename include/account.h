#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "models.h"

extern const double MIN_BALANCE;
extern const int MAX_PIN_ATTEMPTS;

string generateAccNo(const vector<Account>& accounts);
int findAccount(const vector<Account>& accounts, const string& accNo);
bool verifyPIN(const Account& acc);

void createAccount();
void checkBalance();
void displayAccountDetails();
void changePIN();
void closeAccount();

#endif