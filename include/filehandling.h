#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <vector>
#include "models.h"

extern const string ACCOUNTS_FILE;
extern const string TRANSACTIONS_FILE;

string serializeAccount(const Account& a);
Account deserializeAccount(const string& line);
vector<Account> loadAccounts();
void saveAccounts(const vector<Account>& accounts);
void logTransaction(const Transaction& t);
vector<Transaction> loadTransactions(const string& accNo);

#endif