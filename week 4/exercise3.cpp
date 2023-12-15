// #include <iostream>
// #include <cstring>
// #include <string>

// using namespace std;

// void reverseCString(char* str) {
//     int length = strlen(str);
//     for (int i = 0; i < length / 2; i++) {
//         char temp = str[i];
//         str[i] = str[length - i - 1];
//         str[length - i - 1] = temp;
//     }
// }

// void reverseString(string& str) {
//     reverse(str.begin(), str.end());
// }

// void convertCase(char* str) {
//     int length = strlen(str);
//     for (int i = 0; i < length; i++) {
//         if (islower(str[i])) {
//             str[i] = toupper(str[i]);
//         } else if (isupper(str[i])) {
//             str[i] = tolower(str[i]);
//         }
//     }
// }

// void convertCaseString(string& str) {
//     for (char& c : str) {
//         if (islower(c)) {
//             c = toupper(c);
//         } else if (isupper(c)) {
//             c = tolower(c);
//         }
//     }
// }

// int main() {
//     char str1[100];
//     string str2;

//     cout << "Enter str1: ";
//     cin.getline(str1, sizeof(str1));

//     cout << "Enter str2: ";
//     getline(cin, str2);

//     // Reverse str1
//     reverseCString(str1);
//     cout << "Reversed str1 (using C-style string): " << str1 << endl;
//     reverseString(str2);
//     cout << "Reversed str2 (using C++ string): " << str2 << endl;

//     // Convert case of str2
//     convertCase(str1);
//     cout << "Converted case of str1 (using C-style string): " << str1 << endl;
//     convertCaseString(str2);
//     cout << "Converted case of str2 (using C++ string): " << str2 << endl;

//     return 0;
// }


#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void reverseCString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void reverseString(string& str) {
    reverse(str.begin(), str.end());
}

void convertCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

void convertCaseString(string& str) {
    int length = str.length();
    for (int i = 0; i < 
    length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main() {
    char str1[100];
    string str2;

    cout << "Enter str1: ";
    cin.getline(str1, sizeof(str1));

    cout << "Enter str2: ";
    getline(cin, str2);

    // Reverse str1
    reverseCString(str1);
    cout << "Reversed str1 (using C-style string): " << str1 << endl;
    reverseString(str2);
    cout << "Reversed str2 (using C++ string): " << str2 << endl;

    // Convert case of str2
    convertCase(str1);
    cout << "Converted case of str1 (using C-style string): " << str1 << endl;
    convertCaseString(str2);
    cout << "Converted case of str2 (using C++ string): " << str2 << endl;

    return 0;
}
