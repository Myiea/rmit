#include <iostream>
#include <vector>

template <typename T>
class MyVector {
private:
    std::vector<T> vec;

public:
    MyVector() {}

    MyVector(const std::vector<T>& v) : vec(v) {}

    void insert(const T& element) {
        vec.push_back(element);
    }

    void remove(const T& element) {
        for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it) {
            if (*it == element) {
                vec.erase(it);
                break;
            }
        }
    }

    bool find(const T& element) {
        for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
            if (*it == element) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Test for int type
    MyVector<int> intVector;
    intVector.insert(5);
    intVector.insert(10);
    intVector.insert(15);
    intVector.remove(10);
    std::cout << "Found 5: " << intVector.find(5) << std::endl;
    std::cout << "Found 10: " << intVector.find(10) << std::endl;

    // Test for double type
    MyVector<double> doubleVector;
    doubleVector.insert(3.14);
    doubleVector.insert(2.718);
    doubleVector.insert(1.618);
    doubleVector.remove(2.718);
    std::cout << "Found 3.14: " << doubleVector.find(3.14) << std::endl;
    std::cout << "Found 2.718: " << doubleVector.find(2.718) << std::endl;

    return 0;
}
