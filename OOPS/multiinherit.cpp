#include<iostream>
using namespace std;
class person {
    public:
    int age;
    string name;

};

class Student : public person {
    public:
    int id;
};

class Gradstudent :public Student {
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
    Gradstudent obj;
    obj.age = 30;
    obj.name = "Alice";
    obj.id = 101;
    obj.researcharea = "Machine Learning";

    cout << "Name: " << obj.name << endl;
    cout << "Age: " << obj.age << endl;
    cout << "ID: " << obj.id << endl;
    cout << "Research Area: " << obj.researcharea << endl;

    return 0;
}