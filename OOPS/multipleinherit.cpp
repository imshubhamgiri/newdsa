#include<iostream>
using namespace std;
class person {
    public:
    string subject;
    double salary;

};

class Student {
    public:
    int rollno;
    string name;
};

class TA : public Student , public person {
    public:
    string researcharea;
    // Gradstudent(int age, string name, int id, string researcharea) {
    //     this->age = age;
    //     this->name = name;
    //     this->id = id;
    //     this->researcharea = researcharea;
    // }
};

int main() {
    // Gradstudent obj(30, "Alice", 101, "Machine Learning");
    TA obj;
    obj.subject = "Computer Science";
    obj.salary = 50000;
    obj.rollno = 101;
    obj.researcharea = "Machine Learning";

    cout << "Name: " << obj.name << endl;
    cout << "Subject: " << obj.subject << endl;
    cout << "Salary: " << obj.salary << endl;
    cout << "Roll No: " << obj.rollno << endl;
    cout << "Research Area: " << obj.researcharea << endl;

    return 0;
}