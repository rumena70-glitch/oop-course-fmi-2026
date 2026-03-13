#include <iostream>
using namespace std;

bool allDifferent(const int d1, const int d2, const int d3, const int d4) {
    return d1 != d2 &&
           d1 != d3 &&
           d1 != d4 &&
           d2 != d3 &&
           d2 != d4 &&
           d3 != d4;
}
bool isValidInput(const string& s) {
    return s.size() == 4 && !s.starts_with("0") && allDifferent(s[0], s[1], s[2], s[3]);
}
int main() {
    srand(time(nullptr));
    int d1, d2, d3, d4;
    do {
        d1 = rand() % 9 + 1;
        d2 = rand() % 10;
        d3 = rand() % 10;
        d4 = rand() % 10;
    } while (!allDifferent(d1, d2, d3, d4));
    const string s = format("{}{}{}{}", d1, d2, d3, d4);
    string inputNumber;
    while (true) {
        cin >> inputNumber;
        if (!isValidInput(inputNumber)) {
            println("Invalid input");
            continue;
        }
        int bulls = 0, cows = 0;
        for (int i = 0; i < 4; i++) {
            if (s[i] == inputNumber[i]) {
                bulls++;
            }
            const char currentChar = inputNumber[i];
            for (int j = 0; j < 4; j++) {
                if (currentChar == s[j] && j != i) {
                    cows++;
                }
            }
        }
        if (bulls == 1) {
            print("1 bull ");
        }
        else if (bulls == 2) {
            print("2 bulls ");
        }
        else if (bulls == 3) {
            println("3 bulls");
            continue;
        }
        else if (bulls == 4) {
            println("Guessed!");
            break;
        }
        if (cows == 0 && bulls == 0) {
            println("Nothing");
        }
        else if (cows == 1) {
            println("1 cow");
        }
        else if (cows == 2) {
            println("2 cows");
        }
        else if (cows == 3) {
            println("3 cows");
        }
        else if (cows == 4) {
            println("4 cows");
        }
        else {
            println();
        }
    }
}