#include<iostream>
using namespace std;
class Deep{
    private:
    int* data;
    public:
    // Constructor
    Deep(int d){
        data = new int;
        *data = d;
    }
    // Copy Constructor for Deep Copy
    Deep(const Deep &source){
        data = new int;
        *data = *(source.data);
    }
    // Method to display data
    void showData(){
        cout<<"Data: "<<*data<<endl;
    }
    // Destructor
    ~Deep(){
        delete data;
    }
};
int main(){
    cout<<"Deep Copy Example"<<endl;
    Deep obj1(5);
    obj1.showData();
    Deep obj2 = obj1; // Deep copy
    obj2.showData();
    return 0;
}