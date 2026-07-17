#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    string name;
    int score;
    public:
      Student(string n, int s) {
        name = n;
        if (s >= 0 && s <= 100) {
            score = s;
        } else {
            score = 0;
        }
    }
    void setName(string n){
        name=n;
    }
    string getName(){
        return name;
    }
    void setScore(int s){
        if(s>=0&&s<=100){
            score=s;
        }
    }
    int getScore(){
        return score;
    }
};
int main(){
    Student stu1("小明", 85);   // ✅ 创建即初始化
Student stu2("小红", -10);  // 不合法的分数会被设成 0
   
    return 0;
}