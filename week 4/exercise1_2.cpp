#include <iostream>
#include <cmath>

using namespace std;

// Class for complex numbers
class ComplNum {
private:
    double real; // real part
    double imag; // imaginary part

public:
    // default constructor
    ComplNum() {
        real = 0.0;
        imag = 0.0;
    }

    // constructor with two arguments
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

    // friend function to calculate absolute value
    friend double abs(const ComplNum& obj) {
        return sqrt(obj.real * obj.real + obj.imag * obj.imag);
    }
};

int main() {
    ComplNum a(3.0, 2.0); // create complex number a
    ComplNum b(1.5, 4.0); // create complex number b
    double c = 2.0; // real number c

    int choice;
    cout << "Enter choice (1: a-b, 2: a-c, 3: c-b, 4: a--, 5: --a, 6: abs(a)): ";
    cin >> choice;

    // switch case to perform operations based on the user choice
    switch(choice) {
        case 1: {
            ComplNum result = a - b;
            cout << "a - b = " << result.getReal() << " + " << result.getImag() << "i" << endl;
            break;
        }
        case 2: {
            ComplNum result = a - c;
            cout << "a - c = " << result.getReal() << " + " << result.getImag() << "i" << endl;
            break;
        }
        case 3: {
            ComplNum result = c - b;
            cout << "c - b = " << result.getReal() << " + " << result.getImag() << "i" << endl;
            break;
        }
        case 4: {
            ComplNum result = a--;
            cout << "a-- = " << result.getReal() << " + " << result.getImag() << "i" << endl;
            break;
        }
        case 5: {
            ComplNum result = --a;
            cout << "--a = " << result.getReal() << " + " << result.getImag() << "i" << endl;
            break;
        }
        case 6: {
            double absoluteValue = abs(a);
            cout << "Absolute value of a: " << absoluteValue << endl;
            break;
        }
        default: {
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}
