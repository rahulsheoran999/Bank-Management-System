#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"
#define BG_BLUE "\033[44m"

string getCurrentTime();
string getMaskedInput();
void clearScreen();
void printBanner();
void printLine(char c = '-', int len = 58);

#endif