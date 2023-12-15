#include <iostream>
using namespace std;

int main(){
    int n, remainder, reversed_num = 0;

    cout << "Enter a series of intergers: ";
    cin >> n;

    while(n != 0){
        remainder = n % 10;
        reversed_num = reversed_num * 10 + remainder;
        n /= 10;
    }

    cout << "Reversed number: " << reversed_num << endl;
    
    return 0;
}