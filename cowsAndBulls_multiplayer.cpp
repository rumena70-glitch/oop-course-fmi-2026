#include <iostream>
#include <fstream>
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
    string inputNumber;
    string player1Number;
    string player2Number;
    fstream ifs("p1.txt");
    ifs >> player1Number;
    ifs.close();
    ifs.open("p2.txt");
    ifs >> player2Number;
    ifs.close();
    cout << player1Number << " " << player2Number << endl;
    int player = 0;
    bool wp[2]{false};
    const string nums[2] = {player1Number, player2Number};
    while (true) {
        println("Player {}, enter your guess: ", player % 2 + 1);
        cin >> inputNumber;
        if (!isValidInput(inputNumber)) {
            println("Invalid input");
            continue;
        }
        const string& s = nums[(player + 1) % 2];
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
        }
        else if (bulls == 4) {
            println("Guessed!");
            wp[player % 2] = true;
            player++;
            if (wp[0] && wp[1]) {
                break;
            }
        }
        if (bulls != 3) {
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
        if (!wp[0] && !wp[1]) {
            player++;
        }
    }
}