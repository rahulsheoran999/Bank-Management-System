#include "../include/filehandling.h"
#include "../include/utils.h"
#include <fstream>
#include <sstream>

const string ACCOUNTS_FILE = "accounts.dat";
const string TRANSACTIONS_FILE = "transactions.dat";

string serializeAccount(const Account& a) {
    return a.accNo + "|" + a.holderName + "|" + a.email + "|" +
           a.phone + "|" + a.accType + "|" +
           to_string(a.balance) + "|" + a.pin + "|" +
           a.createdOn + "|" + (a.isActive ? "1" : "0");
}

Account deserializeAccount(const string& line) {
    Account a;
    istringstream ss(line);
    string token;
    int idx = 0;
    while (getline(ss, token, '|')) {
        switch (idx++) {
            case 0: a.accNo = token; break;
            case 1: a.holderName = token; break;
            case 2: a.email = token; break;
            case 3: a.phone = token; break;
            case 4: a.accType = token; break;
            case 5: a.balance = stod(token); break;
            case 6: a.pin = token; break;
            case 7: a.createdOn = token; break;
            case 8: a.isActive = (token == "1"); break;
        }
    }
    return a;
}

vector<Account> loadAccounts() {
    vector<Account> accounts;
    ifstream file(ACCOUNTS_FILE);
    string line;
    while (getline(file, line))
        if (!line.empty())
            accounts.push_back(deserializeAccount(line));
    return accounts;
}

void saveAccounts(const vector<Account>& accounts) {
    ofstream file(ACCOUNTS_FILE, ios::trunc);
    for (const auto& a : accounts)
        file << serializeAccount(a) << "\n";
}

void logTransaction(const Transaction& t) {
    ofstream file(TRANSACTIONS_FILE, ios::app);
    file << t.accNo << "|" << t.type << "|"
         << t.amount << "|" << t.balAfter << "|"
         << t.timestamp << "|" << t.note << "\n";
}

vector<Transaction> loadTransactions(const string& accNo) {
    vector<Transaction> txns;
    ifstream file(TRANSACTIONS_FILE);
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        Transaction t;
        string token;
        int idx = 0;
        while (getline(ss, token, '|')) {
            switch (idx++) {
                case 0: t.accNo = token; break;
                case 1: t.type = token; break;
                case 2: t.amount = stod(token); break;
                case 3: t.balAfter = stod(token); break;
                case 4: t.timestamp = token; break;
                case 5: t.note = token; break;
            }
        }
        if (t.accNo == accNo) txns.push_back(t);
    }
    return txns;
}