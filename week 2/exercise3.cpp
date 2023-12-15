#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
    // part a
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100 + 1);

    cout << "Characters of the string: ";
    for (int i = 0; i < strlen(str); i++) {
        cout << str[i] << " " ;
    }
    cout << endl;


    // part b
    double number = 1.234;
    cout << setw(9) << setfill('0') << fixed << setprecision(3) << number << endl;

    // part c
    cout << setprecision(3) << number << endl;

    // part d
    string input;

    cout << "Input: ";
    cin >> input;

    string hexStr = input.substr(2);
    int decimal = stoi(hexStr, nullptr, 16);

    cout << "Output: " << decimal << " ";
    cout << "0x" << hex << uppercase << decimal << endl;


    return 0;
}
