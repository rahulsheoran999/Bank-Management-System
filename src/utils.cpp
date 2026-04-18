#include "../include/utils.h"

string getCurrentTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", localtime(&now));
    return string(buf);
}

string getMaskedInput() {
    string pin = "";
    char ch;
    while ((ch = cin.get()) != '\n') {
        if (ch == 8 || ch == 127) {
            if (!pin.empty()) { pin.pop_back(); cout << "\b \b"; }
        } else {
            pin += ch;
            cout << '*';
        }
    }
    cout << endl;
    return pin;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printBanner() {
    cout << CYAN << BOLD;
    cout << "\n";
    cout << "  ╔══════════════════════════════════════════════════════╗\n";
    cout << "  ║          🏦  NOVA BANK MANAGEMENT SYSTEM  🏦          ║\n";
    cout << "  ║              Secure · Reliable · Modern               ║\n";
    cout << "  ╚══════════════════════════════════════════════════════╝\n";
    cout << RESET << "\n";
}

void printLine(char c, int len) {
    cout << CYAN;
    for (int i = 0; i < len; i++) cout << c;
    cout << RESET << "\n";
}