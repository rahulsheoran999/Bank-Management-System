#include "../include/transaction.h"
#include "../include/utils.h"
#include "../include/filehandling.h"
#include "../include/account.h"

using namespace std;

void depositMoney() {
    string accNo;
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    if (!verifyPIN(accs[idx])) return;

    double amt;
    cin >> amt; cin.ignore();

    accs[idx].balance += amt;
    saveAccounts(accs);

    cout << "Deposited\n";
}

void withdrawMoney() {
    string accNo;
    getline(cin, accNo);

    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    if (idx == -1) return;

    if (!verifyPIN(accs[idx])) return;

    double amt;
    cout << "Enter amount to withdraw: ";
    cin >> amt; 
    cin.ignore(1000, '\n');

    if (accs[idx].balance - amt < MIN_BALANCE) {
        cout << RED << "  ✗ Insufficient funds!" << RESET << endl;
        cout << YELLOW << "  Minimum balance of " << MIN_BALANCE << " must be maintained." << RESET << endl;
        return; 
    }

    accs[idx].balance -= amt;
    saveAccounts(accs);

    cout << GREEN << "  ✓ Withdrawn successfully! New Balance: " << accs[idx].balance << RESET << endl;
}

void showTransactionHistory() {
    cout << "History\n";
}

void fundTransfer() {
    cout << "Transfer\n";
}

void miniStatement() {
    cout << "Mini Statement\n";
}