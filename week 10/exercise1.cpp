#include <iostream>
using std::cout;

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}


int main() {
    int num1 = 5;
    int num2 = 10;

    cout << "Before swapping: " << num1 << ", " << num2 << "\n";

    swap(num1, num2);

    cout << "After swapping: " << num1 << ", " << num2 << "\n";

    return 0;
}
