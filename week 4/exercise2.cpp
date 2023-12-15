#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// BankAcc class definition
class BankAcc {
public:
    string name;  // name of the account holder
    float amount; // account balance

    // Constructor
    // Initializes the account with a name and an initial amount
    BankAcc(string n, float a) {
        name = n;
        amount = a;
    }

    // Withdraw method
    // Allows the user to withdraw money from their account
    // Returns 0 if successful, -1 if there are insufficient funds
    int withdraw(float num) {
        if (amount >= num) {
            amount -= num;
        } else {
            cout << "Error: Insufficient funds\n";
            return -1;
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    // Create accounts and initialize data
    BankAcc acc1("John Doe", 5000);
    BankAcc acc2("Jane Smith", 7000);
    BankAcc acc3("Robert Brown", 3000);

    // Print account information
    cout << acc1.name << ": $" << acc1.amount << endl;
    cout << acc2.name << ": $" << acc2.amount << endl;
    cout << acc3.name << ": $" << acc3.amount << endl;

    // Test withdraw method
    acc1.withdraw(2000);
    acc2.withdraw(2000);
    acc3.withdraw(1000);

    // Save data to file
    // If a command line argument is given, it is used as the filename
    // Otherwise, prompt the user to enter the filename
    string filename;
    if (argc > 1) {
        filename = argv[1];
    } else {
        cout << "Enter the filename: ";
        cin >> filename;
    }

    ofstream dataFile(filename);
    if (dataFile.is_open()) {
        dataFile << acc1.name << ": " << acc1.amount << "\n";
        dataFile << acc2.name << ": " << acc2.amount << "\n";
        dataFile << acc3.name << ": " << acc3.amount << "\n";
        dataFile.close();
    } else {
        cout << "Error: Unable to open file\n";
    }

    return 0;
}
