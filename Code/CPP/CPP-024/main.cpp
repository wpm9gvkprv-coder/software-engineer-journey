#include<iostream>
#include<string>
using namespace std;
class Student {
    friend ostream& operator<<(ostream& os, const Student& stu);
private:
    string name;
    int score;
    public:
    Student(string n, int s) : name(n), score(s) {}
    bool operator>(const Student& other) const {
        return score>other.score;
    }
};

ostream& operator<<(ostream& os, const Student& stu) {
    os << stu.name << ": " << stu.score;
    return os;
}

int main() {
    Student stu("小明", 85);
    Student stu1("小红",80);
    cout << stu << endl;   // 直接输出！
    int result=stu>stu1;
    cout<<result<<endl;
}
