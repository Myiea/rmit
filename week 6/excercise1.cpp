#include <iostream>
#include <sstream> // Added include for stringstream
using namespace std;

class Student {
protected:
    string name;
    int studentID;

public:
    Student(string nameVal = " ", int studentIDval = 0)
        : name(nameVal), studentID(studentIDval) {
        cout << "Constructor of Student class\n";
    }

    ~Student() {
        cout << "Destructor of Student class\n";
    }

    virtual string toString() {
        stringstream sstr;
        sstr << "name = " << Student::name << ", studentID = " << studentID;
        return sstr.str();
    }
};

class Staff {
protected:
    string name;
    int staffID;

public:
    Staff(string nameVal = " ", int staffIDval = 0)
        : name(nameVal), staffID(staffIDval) {
        cout << "Constructor of Staff class\n";
    }

    ~Staff() {
        cout << "Destructor of Staff class\n";
    }

    virtual string toString() {
        stringstream sstr;
        sstr << "name = " << Staff::name << ", staffID = " << staffID;
        return sstr.str();
    }
};

class Tutor : public Staff, public Student {
public:
    Tutor(string nameVal = " ", int studentVal = 0, int staffIDval = 0)
        : Student(nameVal, studentVal), Staff(nameVal, staffIDval) {
        cout << "Constructor of Tutor class\n";
    }

    ~Tutor() {
        cout << "Destructor of Tutor class\n";
    }

    virtual string toString() {
        stringstream sstr;
        sstr << "name = " << Student::name << ", staffID = " << staffID << ", studentID = " << studentID;
        return sstr.str();
    }

    void consultation() {
        cout << "Doing consultation!\n";
    }

    void setName(string nameVal) {
        Student::name = nameVal;
        Staff::name = nameVal;
    }

    void showInfoStudent(Student& stu) {
        cout << stu.toString() << "\n";
    }

    void showInfoStaff(Staff& staff) {
        cout << staff.toString() << "\n";
    }
};

class SchoolSystem{
    private: 
        vector<Student> students;

    public:
        SchoolSystem(){ }
        bool addStudent(){
            string name;
            cout << "Input student name: ";
            getline(cin >> ws, name);

            int id;
            cout << "Input student id: ";
            cin >> id;

            students.push_back(Student(name, id));
        }
};

int main() {
    Student stu1("Harry", 123);
    Staff sta1("CIv", 23434);
    Tutor tutor1("John", 12345);
    return 0;
}