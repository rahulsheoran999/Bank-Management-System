#include "include/utils.h"
#include "include/account.h"
#include "include/transaction.h"
#include "include/filehandling.h"
#include "include/models.h"
#include <limits>

void showMenu() {
    printLine('=');
    cout << "  1. Create Account          2. Deposit Money\n";
    cout << "  3. Withdraw Money          4. Check Balance\n";
    cout << "  5. Account Details         6. Transaction History\n";
    cout << "  7. Fund Transfer           8. Mini Statement\n";
    cout << "  9. Change PIN              0. Exit\n";
    printLine('=');
    cout << "  Enter choice: ";
}

int main() {
    int choice;
    do {
        clearScreen();
        printBanner();
        cout << "  " << CYAN << "Date: " << RESET << getCurrentTime() << "\n";
        showMenu();

        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: displayAccountDetails(); break;
            case 6: showTransactionHistory(); break;
            case 7: fundTransfer(); break;
            case 8: miniStatement(); break;
            case 9: changePIN(); break;
        }
        
        if (choice != 0) {
            cout << "\n  Press Enter to return to menu...";
            cin.get();
        }
    } while (choice != 0);

    return 0;
}