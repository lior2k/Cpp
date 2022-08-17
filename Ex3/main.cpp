#include <iostream>
#include "sources/Matrix.hpp"
using namespace std;
using namespace zich;

int main() {
    Matrix M;
    char mainController;
    char secondaryController;
    char trash;
    string menu = "---- MENU ----\n'M' to print menu, 'A' to create your matrix, 'B' to print your matrix\n'C' to increment or decrement matrix, 'D' to add or subtract new matrix, 'E' to multiple new matrix\nQ' to quit\n-----END MENU-----";
    cout << menu << endl;
    int run = 1;
    while (run) {
        mainController = '0';
        cout << "New Command: ";
        mainController = getchar();
        trash = '0';
        while (trash != '\n') {
            trash = getchar();
        }
        if (mainController == 'M') {
            cout << menu << endl;
        }
        if (mainController == 'A') {
            cout << "Enter values such as '[1 2 3], [4 5 6], [7 8 9]': ";
            cin >> M;
        }
        if (mainController == 'B') {
            cout << M << endl;
        }
        if (mainController == 'C') {
            cout << "Enter '+' to increment or '-' to decrement: ";
            cin >> secondaryController;
            trash = '0';
            while (trash != '\n') {
                trash = getchar();
            }
            if (secondaryController == '+') {
                M++;
            }
            if (secondaryController == '-') {
                M--;
            }
        }
        if (mainController == 'D') {
            cout << "To add enter '+', to subract enter '-': ";
            cin >> secondaryController;
            trash = '0';
            while (trash != '\n') {
                trash = getchar();
            }
            Matrix temp;
            cout << "Enter new matrix values: ";
            cin >> temp;
            if (secondaryController == '+') {
                M += temp;
            }
            if (secondaryController == '-') {
                M-= temp;
            }
        }

        if (mainController == 'Q') {
            run = 0;
        }
    }
}