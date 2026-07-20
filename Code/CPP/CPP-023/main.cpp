#include<iostream>
#include<string>
using namespace std;
class Student{
    string name;
    static int count;
    public:
    Student(string n){
        name=n;
        count++;
    }
    ~Student(){
        count--;
    }
    static int getCount(){
        return count;
    }
};
int Student::count=0;
int main(){
    cout<<Student::getCount()<<endl;
    Student a("小明");
    Student b("小红");
    cout<<Student::getCount()<<endl;
    {
        Student c("小刚");
        cout<<Student::getCount()<<endl;
    }
    cout<<Student::getCount()<<endl;
}