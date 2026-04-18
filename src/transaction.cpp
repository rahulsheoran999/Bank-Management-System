#include "../include/transaction.h"
#include "../include/utils.h"
#include "../include/filehandling.h"
#include "../include/account.h"

void depositMoney() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    
    if (idx == -1) { cout << RED << "  ✗ Account not found.\n" << RESET; return; }
    
    double amt;
    cout << "  Enter Amount: "; cin >> amt; cin.ignore();
    
    accs[idx].balance += amt;
    saveAccounts(accs);
    
    logTransaction({accNo, "DEPOSIT", amt, accs[idx].balance, getCurrentTime(), "Cash Deposit"});
    cout << GREEN << "  ✓ ₹" << amt << " deposited successfully.\n" << RESET;
}

void withdrawMoney() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Account> accs = loadAccounts();
    int idx = findAccount(accs, accNo);
    
    if (idx != -1 && verifyPIN(accs[idx])) {
        double amt;
        cout << "  Enter Amount: "; cin >> amt; cin.ignore();
        
        if (accs[idx].balance - amt < 500) {
            cout << RED << "  ✗ Insufficient Balance (Min 500 required).\n" << RESET;
            return;
        }
        
        accs[idx].balance -= amt;
        saveAccounts(accs);
        logTransaction({accNo, "WITHDRAW", amt, accs[idx].balance, getCurrentTime(), "ATM Withdrawal"});
        cout << GREEN << "  ✓ Transaction successful.\n" << RESET;
    }
}

void fundTransfer() {
    string fromAcc, toAcc;
    cout << "  Your Acc No: "; getline(cin, fromAcc);
    vector<Account> accs = loadAccounts();
    int sIdx = findAccount(accs, fromAcc);

    if (sIdx != -1 && verifyPIN(accs[sIdx])) {
        cout << "  Receiver Acc No: "; getline(cin, toAcc);
        int rIdx = findAccount(accs, toAcc);
        if (rIdx == -1) { cout << RED << "  ✗ Receiver not found.\n" << RESET; return; }

        double amt;
        cout << "  Amount to Transfer: "; cin >> amt; cin.ignore();

        if (accs[sIdx].balance - amt < 500) { cout << RED << "  ✗ Insufficient funds.\n" << RESET; return; }

        accs[sIdx].balance -= amt;
        accs[rIdx].balance += amt;
        
        saveAccounts(accs);
        logTransaction({fromAcc, "TRANSFER-OUT", amt, accs[sIdx].balance, getCurrentTime(), "To: " + toAcc});
        logTransaction({toAcc, "TRANSFER-IN", amt, accs[rIdx].balance, getCurrentTime(), "From: " + fromAcc});
        cout << GREEN << "  ✓ ₹" << amt << " transferred to " << toAcc << ".\n" << RESET;
    }
}

void showTransactionHistory() {
    string accNo;
    cout << "  Enter Account Number: "; getline(cin, accNo);
    vector<Transaction> txns = loadTransactions(accNo);
    
    if(txns.empty()) { cout << YELLOW << "  No transaction history found.\n" << RESET; return; }

    cout << "\n" << BOLD << "  DATE       | TYPE        | AMOUNT    | BALANCE" << RESET << endl;
    printLine('-');
    for (const auto& t : txns) {
        cout << "  " << t.timestamp.substr(0,10) << " | " << left << setw(11) << t.type 
             << " | " << setw(9) << t.amount << " | " << t.balAfter << endl;
    }
}

void miniStatement() {
    showTransactionHistory(); 
}