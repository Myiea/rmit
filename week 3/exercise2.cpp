#include <iostream>
using namespace std;

// part a
class Student{
    public:
        string name;
        int score;

        Student(string StudentName, int StudentScore){
            name = StudentName;
            score = StudentScore;
        }

        void showInfo(){
            cout << "name " << name << " & score " << score << endl;
        }
};

int main(){
    // part b
    Student student1("Jayden", 98);
    Student student2("Layla", 80);
    cout << "Student 1 "; student1.showInfo();
    cout << "Student 2 "; student2.showInfo();

    cout << "**************************************" << endl;

    // part c
    Student students[3] ={
        Student("John", 80),
        Student("Emily", 98),
        Student("Park", 76)
    };

    int HighestStudentScore = students[0].score;
    int HighestStudentScoreIndex = 0;

    for(int i = 0; i < 3; i++){
        if (students[i].score > HighestStudentScore){
            HighestStudentScore = students[i].score;
            HighestStudentScoreIndex = i;
        }
    }

    cout << "Student with the highest score \n";
    cout << "Name: " << students[HighestStudentScoreIndex].name << endl;
    cout << "Score: " << students[HighestStudentScoreIndex].score << endl;
    
}