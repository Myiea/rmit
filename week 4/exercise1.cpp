#include <iostream>
#include <cmath>

using namespace std;

class ComplNum {
private:
    double real; // real part of complex number
    double imag; // imaginary part of complex number

public:
    // default constructor
    ComplNum() {
        real = 0.0;
        imag = 0.0;
    }

    // constructor to initialize real and imaginary parts
    ComplNum(double r, double i) {
        this->real = r;
        this->imag = i;
    }

    // getter for real part
    double getReal() {
        return real;
    }

    // getter for imaginary part
    double getImag() {
        return imag;
    }

    // overload - operator for another complex number
    ComplNum operator-(const ComplNum& obj) {
        ComplNum result;
        result.real = this->real - obj.real;
        result.imag = this->imag - obj.imag;
        return result;
    }

    // overload - operator for a real number
    ComplNum operator-(double num) {
        ComplNum result;
        result.real = this->real - num;
        result.imag = this->imag;
        return result;
    }

    // overload - operator for a real number with complex number
    friend ComplNum operator-(double num, const ComplNum& obj) {
        ComplNum result;
        result.real = num - obj.real;
        result.imag = -obj.imag;
        return result;
    }

    // overload -- operator (pre-decrement)
    ComplNum operator--() {
        this->real -= 1.0;
        return *this;
    }

    // overload -- operator (post-decrement)
    ComplNum operator--(int) {
        ComplNum temp(*this);
        this->real -= 1.0;
        return temp;
    }

    // friend function to calculate absolute value of complex number
    friend double abs(const ComplNum& obj) {
        return sqrt(obj.real * obj.real + obj.imag * obj.imag);
    }
};

int main() {
    ComplNum a(3.0, 2.0); // declare complex number a
    ComplNum b(1.5, 4.0); // declare complex number b
    double c = 2.0; // declare real number c

    ComplNum result1 = a - b; // subtract complex number b from a
    cout << "a - b = " << result1.getReal() << " + " << result1.getImag() << "i" << endl;

    ComplNum result2 = a - c; // subtract real number c from complex number a
    cout << "a - c = " << result2.getReal() << " + " << result2.getImag() << "i" << endl;

    ComplNum result3 = c - b; // subtract complex number b from real number c
    cout << "c - b = " << result3.getReal() << " + " << result3.getImag() << "i" << endl;

    ComplNum result4 = a--; // post-decrement complex number a
    cout << "a-- = " << result4.getReal() << " + " << result4.getImag() << "i" << endl;

    ComplNum result5 = --a; // pre-decrement complex number a
    cout << "--a = " << result5.getReal() << " + " << result5.getImag() << "i" << endl;

    double absoluteValue = abs(a); // calculate absolute value of complex number a
    cout << "Absolute value of a: " << absoluteValue << endl;

    return 0;
}
