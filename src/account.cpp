#include "../include/account.h"
#include "../include/utils.h"
#include "../include/filehandling.h"
#include <iostream>

using namespace std;

const double MIN_BALANCE = 500.0;
const int MAX_PIN_ATTEMPTS = 3;

string generateAccNo(const vector<Account>& accounts) {
    int maxNo = 1000;
    for (const auto& a : accounts) {
        try {
            int n = stoi(a.accNo.substr(4));
            if (n >= maxNo) maxNo = n + 1;
        } catch (...) {}
    }
    return "NOVA" + to_string(maxNo);
}

int findAccount(const vector<Account>& accounts, const string& accNo) {
    for (int i = 0; i < (int)accounts.size(); i++)
        if (accounts[i].accNo == accNo) return i;
    return -1;
}

bool verifyPIN(const Account& acc) {
    for (int attempt = 1; attempt <= MAX_PIN_ATTEMPTS; attempt++) {
        cout << YELLOW << "  Enter PIN (Attempt " << attempt << "/" << MAX_PIN_ATTEMPTS << "): " << RESET;
        string pin = getMaskedInput();
        if (pin == acc.pin) return true;
        cout << RED << "  ✗ Incorrect PIN!\n" << RESET;
    }
    cout << RED << "  ✗ Account locked!\n" << RESET;
    return false;
}

// ---- COPY YOUR ORIGINAL FUNCTIONS EXACTLY BELOW ----

void createAccount() {
    vector<Account> accounts = loadAccounts();
    Account a;
    a.accNo = generateAccNo(accounts);
    a.createdOn = getCurrentTime();

    cout << "Name: "; getline(cin, a.holderName);
    cout << "Email: "; getline(cin, a.email);
    cout << "Phone: "; getline(cin, a.phone);

    cout << "Deposit: ";
    cin >> a.balance; cin.ignore();

    cout << "PIN: ";
    a.pin = getMaskedInput();

    accounts.push_back(a);
    saveAccounts(accounts);

    cout << "Account Created: " << a.accNo << endl;
}

void checkBalance() {
    string accNo;
    cout << "Enter Acc No: ";
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    if (!verifyPIN(accs[idx])) return;

    cout << "Balance: " << accs[idx].balance << endl;
}

void displayAccountDetails() {
    string accNo;
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    if (!verifyPIN(accs[idx])) return;

    cout << accs[idx].holderName << endl;
}

void changePIN() {
    string accNo;
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    cout << "New PIN: ";
    accs[idx].pin = getMaskedInput();

    saveAccounts(accs);
}

void closeAccount() {
    string accNo;
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    accs[idx].isActive = false;
    saveAccounts(accs);
}