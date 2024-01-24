#include <iostream>

template<int N> class factorial;

template<> class factorial<0> {
public:
    static const int value = 1;
};

template<int N> class factorial {
public:
    static const int value = N * factorial<N - 1>::value;
};


int main() {
    std::cout << "Factorial of 5: " << factorial<5>::value << std::endl;
    std::cout << "Factorial of 0: " << factorial<0>::value << std::endl;
    return 0;
}
