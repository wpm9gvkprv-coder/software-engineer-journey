#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
public:
    Student(string n) {
        name = n;
    }
    
    void showThis() {
        cout << "对象的 this 地址: " << this << endl;
    }
    void setName(string name){
        this->name=name;
    }
    string getName() {
        return name;
    }
};

int main() {
    Student stu1("小明");
    Student stu2("小红");
    stu1.setName("xiaoming");
    cout << "stu1 的地址: " << &stu1 << endl;
    stu1.showThis();
    
    cout << "stu2 的地址: " << &stu2 << endl;
    stu2.showThis();
    cout<<stu1.getName()<<endl;
    cout<<stu2.getName()<<endl;
    return 0;
}
