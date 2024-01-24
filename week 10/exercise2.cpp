#include <iostream>
#include <string>

template<typename T>
T min(T a, T b, T c) {
    T minVal = a;
    if (b < minVal) {
        minVal = b;
    }
    if (c < minVal) {
        minVal = c;
    }
    return minVal;
}

int main() {
    int intMin = min(1, 0, 2);
    std::cout << "The min of 1, 0, 2 is " << intMin << std::endl;

    double doubleMin = min(1.5, 0.5, 3.0);
    std::cout << "The min of 1.5, 0.5, 3.0 is " << doubleMin << std::endl;

    std::string stringMin = min(std::string("Hello"), std::string("Hi"), std::string("Morning"));
    std::cout << "The min of Hello, Hi, Morning is " << stringMin << std::endl;

    return 0;
}
