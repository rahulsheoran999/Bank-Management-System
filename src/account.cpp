#include "../include/account.h"
#include "../include/utils.h"
#include "../include/filehandling.h"
#include <iostream>

const double MIN_BALANCE = 500.0;
const int MAX_PIN_ATTEMPTS = 3;

string generateAccNo(const vector<Account>& accounts) {
    // Generates a unique number based on total account count
    int maxNo = 1000 + accounts.size();
    return "NOVA" + to_string(maxNo);
}

int findAccount(const vector<Account>& accounts, const string& accNo) {
    for (int i = 0; i < (int)accounts.size(); i++)
        if (accounts[i].accNo == accNo && accounts[i].isActive) return i;
    return -1;
}

bool verifyPIN(const Account& acc) {
    for (int attempt = 1; attempt <= MAX_PIN_ATTEMPTS; attempt++) {
        cout << YELLOW << "  Enter PIN: " << RESET;
        string pin = getMaskedInput();
        if (pin == acc.pin) return true;
        cout << RED << "  ✗ Incorrect PIN (" << attempt << "/" << MAX_PIN_ATTEMPTS << ")\n" << RESET;
    }
    cout << RED << "  ✗ Access Denied.\n" << RESET;
    return false;
}

void createAccount() {
    vector<Account> accounts = loadAccounts();
    Account a;
    a.accNo = generateAccNo(accounts);
    a.createdOn = getCurrentTime();

    cout << "  Full Name: "; getline(cin, a.holderName);
    cout << "  Email: "; getline(cin, a.email);
    cout << "  Phone: "; getline(cin, a.phone);
    cout << "  Account Type (Savings/Current): "; getline(cin, a.accType);
    
    cout << "  Initial Deposit (Min 500): ";
    cin >> a.balance; cin.ignore();

    if (a.balance < MIN_BALANCE) {
        cout << RED << "  ✗ Error: Initial deposit must be at least 500.\n" << RESET;
        return;
    }

    cout << "  Set 4-Digit PIN: ";
    a.pin = getMaskedInput();

    accounts.push_back(a);
    saveAccounts(accounts);
    cout << GREEN << "  ✓ Account Created! Your Account No: " << BOLD << a.accNo << RESET << endl;
}

void checkBalance() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx != -1 && verifyPIN(accs[idx])) {
        cout << CYAN << "  Current Balance: ₹" << accs[idx].balance << RESET << endl;
    } else if (idx == -1) cout << RED << "  ✗ Account not found.\n" << RESET;
}

void displayAccountDetails() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx != -1 && verifyPIN(accs[idx])) {
        printLine('-');
        cout << "  NAME:    " << accs[idx].holderName << "\n";
        cout << "  EMAIL:   " << accs[idx].email << "\n";
        cout << "  PHONE:   " << accs[idx].phone << "\n";
        cout << "  TYPE:    " << accs[idx].accType << "\n";
        cout << "  OPENED:  " << accs[idx].createdOn << "\n";
        printLine('-');
    }
}

void changePIN() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx != -1 && verifyPIN(accs[idx])) {
        cout << "  Enter New PIN: ";
        accs[idx].pin = getMaskedInput();
        saveAccounts(accs);
        cout << GREEN << "  ✓ PIN Updated Successfully!\n" << RESET;
    }
}