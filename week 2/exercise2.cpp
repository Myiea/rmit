#include <iostream>
using namespace std;

void checkHex(string s){    
    if((s[0] == '0' && s[1] == 'x') || (s[0] == '0' && s[1] == 'X')) {
        int n = s.length(); 
        for(int i = 2; i < n; i++) { 
            char ch = s[i]; 

            if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F')){ 
                cout << "Invalid" << endl; 
                return; 
            } 
        } 
        cout << "Valid" << endl; 
    }else{
        cout << "Error!" << endl;
    }
}

int main(){
string s;
cout << "Please enter a string of hexadecimal to validate: ";
cin >> s;

checkHex(s);

return 0;
}