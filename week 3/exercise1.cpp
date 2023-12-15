#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
    int choice = 0;
    string password;
    cout << "Password management program" << endl;
    cout << "1. Save your password" << endl;
    cout << "2. Read your password" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character

    switch(choice){
        case 1:
        {
            cout << "Enter password: ";
            getline(cin, password);
            ofstream outFile("pwd.dat");
            if(outFile.is_open()){
                outFile << password;
                cout << "Password saved!" << endl;
            }else{
                cout << "Unable to open file." << endl;
            }
            outFile.close();
            break;
        }

        case 2:
            { 
            ifstream inFile("pwd.dat");
            if(inFile.is_open()){
                getline(inFile, password);
                cout << "Your password: " << password << endl;
            }else{
                cout << "No password saved." << endl;
            }
            inFile.close();
            break;
            }
    }
    return 0;
}