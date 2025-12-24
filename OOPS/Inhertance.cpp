#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    // Person(string name , int age){
    //     this->name = name;
    //     this->age = age;
    // }
    Person(){

    }
};
class student : public Person{
    public:
    int studentID;
    // student(string name, int age, int id) : Person(name, age){
    //     studentID = id;
    // }
    void getInfo(){
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        cout<<"Id:"<<studentID<<endl;
    }
};
int main(){
    student s1;
    s1.name = "Bob";
    s1.age = 20;
    s1.studentID = 101;

    // student s1("Bob", 20, 101);
   s1.getInfo();

    return 0;
}