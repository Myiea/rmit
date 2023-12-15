#include <iostream>
#include <algorithm>
using namespace std;

class Cat {
public:
    string name;
    int age;

    Cat(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Person {
public:
    string name;
    Cat cat;

    Person(string name, Cat cat) : name(name), cat(cat) {
        this->name = name;
        this->cat = cat;
    };
};

bool compareAge(const Person& p1, const Person& p2) {
    return p1.cat.age < p2.cat.age;
}

int main() {
    // Initialize values for three persons
    Person persons[] = {
        Person("John", Cat("Fluffy", 3)),
        Person("Alice", Cat("Whiskers", 5)),
        Person("Mike", Cat("Mittens", 2))
    };

    // Find person with cat of highest age
    Person* highestAge = max_element(persons, persons + 3, compareAge);

    // Print the information of the person with the cat of highest age
    cout << "Person with cat of highest age: " << highestAge->name << endl;
    cout << "Cat name: " << highestAge->cat.name << endl;
    cout << "Cat age: " << highestAge->cat.age << endl;

    return 0;
}
