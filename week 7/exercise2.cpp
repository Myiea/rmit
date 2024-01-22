#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Staff {
public:
    string name;
    vector<string> departments;

    void printInfo() {
        cout << "Name: " << name << "\nDepartments: ";
        for (size_t i = 0; i < departments.size(); i++) {
            cout << departments[i] << " ";
        }
        cout << endl;
    }      

};

class Department {
public:
    string name;
    string location;

    virtual void printInfo() = 0;  // Make Department an abstract class
};

class AcademicDepartment : public Department {
public:
    int numberOfCourses;

    void printInfo() {
        cout << "Name: " << name << "\nLocation: " << location << "\nNumber of courses: " << numberOfCourses << std::endl;
    }
};

class NonAcademicDepartment : public Department {
public:
    int numberOfServices;

    void printInfo() {
        cout << "Name: " << name << "\nLocation: " << location << "\nNumber of services: " << numberOfServices << std::endl;
    }
};

int main() {
    // Create staff members
    Staff staff1;
    staff1.name = "John Doe";
    staff1.departments.push_back("Academic");

    Staff staff2;
    staff2.name = "Jane Smith";
    staff2.departments.push_back("Non-Academic");

    // Create departments
    AcademicDepartment academicDept;
    academicDept.name = "Mathematics";
    academicDept.location = "Building A";
    academicDept.numberOfCourses = 5;

    NonAcademicDepartment nonAcademicDept;
    nonAcademicDept.name = "Administration";
    nonAcademicDept.location = "Building B";
    nonAcademicDept.numberOfServices = 10;

    // Print information
    cout << "Staff 1 information\n";
    staff1.printInfo();
    cout << endl;

    cout << "Staff 2 information\n";
    staff2.printInfo();
    cout << endl;

    cout << "Academic Department information\n";
    academicDept.printInfo();
    cout << endl;

    cout << "Non Academic information\n";
    nonAcademicDept.printInfo();

    return 0;
}
