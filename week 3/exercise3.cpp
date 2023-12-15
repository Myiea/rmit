#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int score;
    string password;

    Student(string StudentName, int StudentScore) {
        name = StudentName;
        score = StudentScore;
        password = "";

        // Check if password file exists
        ifstream file(name + ".dat");
        if (file.good()) {
            getline(file, password);
        }
        file.close();
    }

    void changePwd() {
        if (password.empty()) {
            cout << "Set a new password: ";
            cin >> password;
            savePwdToFile();
            cout << "Password has been set successfully." << endl;
        }
        else {
            string prevPwd;
            cout << "Enter previous password: ";
            cin >> prevPwd;
            if (prevPwd == password) {
                cout << "Set a new password: ";
                cin >> password;
                savePwdToFile();
                cout << "Password has been changed successfully." << endl;
            } 
            else {
                cout << "Previous password is incorrect." << endl;
            }
        }
    }

private:
    void savePwdToFile() {
        ofstream file(name + ".dat");
        file << password;
        file.close();
    }
};

int main() {
    Student student1("Jayden", 98);

    // Test changePwd() method
    student1.changePwd();

    return 0;
}