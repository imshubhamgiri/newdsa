#include<iostream>
using namespace std;
class Shallow{
    
    public:
    double* marks;
    int data;
    string name;

    // Constructor
    public:
    Shallow(int d, string name){
        data = d;
        this->name = name;
        marks = new double;
        *marks = 95.5;
    }
    // Copy Constructor for Shallow Copy
    // Shallow(Shallow &obj) {
    //     data = obj.data;
    //     this->name = obj.name;
    //     marks = new double;
    //     *marks = *obj.marks; // Shallow copy of pointer
    // }
    // Destructor
    ~Shallow(){
        cout<<"deleting everything"<<endl;
        // delete marks;
    }

    // Method to display data
    void showData(){
        cout<<"Data: "<<data<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<*marks<<endl;
    }
};
int main(){
    // cout<<"Shallow Copy Example"<<endl;
    // Shallow obj1(5, "John");
    // Shallow obj2 (obj1); // Shallow copy
    // obj1.showData();
    // cout<<"After copying to obj2:"<<endl;
    // obj2.name = "Kaula";
    // *(obj2.marks) = 85.0; // Modifying the marks of obj2
    // obj1.showData();
    // cout<<"After modifying obj2's marks:"<<endl;
    // obj2.showData();

    //destructor example
    Shallow t1(10, "Alice");
    return 0;
}