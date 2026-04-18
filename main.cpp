#include "include/utils.h"
#include "include/account.h"
#include "include/transaction.h"
#include "include/filehandling.h"
#include "include/models.h"

void showMenu() {
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display Account Details" << endl;
    cout << "6. Show Transaction History" << endl;
    cout << "7. Fund Transfer" << endl;
    cout << "8. Mini Statement" << endl;
    cout << "9. Change PIN" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    int choice;
    do {
        clearScreen();
        printBanner();
        cout << "  " << CYAN << "Date & Time: " << RESET << getCurrentTime() << "\n";
        showMenu();

        cin >> choice;
        cin.ignore(1000, '\n');

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

        cin.get();
    } while (choice != 0);

    return 0;
}