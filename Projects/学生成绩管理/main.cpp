#include<iostream>
using namespace std;
bool isPass(int score);
int main(){
    cout<<"=====成绩统计====="<<endl;
    cout<<"请输入学生成绩(输入-1结束):"<<endl;
    int score=0;
    double total=0;
    int person=0;
    double average=0;
    int highest=0;
    int lowest=0;
    int pass=0;
    int nopass=0;
   while(1){
    cout<<"分数：";
    cin>>score;
    if(score==-1){
        break;
    }else{
        total=total+score;
        person=person+1;
        if(person==1){
            highest=score;
            lowest=score;
        }else{
        if(highest<=score){
            highest=score;
        }
        if(lowest>=score){
            lowest=score;
        }
    }
        if(isPass(score)){
            pass=pass+1;
        }else{
            nopass=nopass+1;
        }
    }
   }
   if(person==0){
    average=0;
   }else{
    average=total/person;
   }
   cout<<"=====统计结果====="<<endl;
   cout<<"总人数："<<person<<endl;
   cout<<"总分："<<total<<endl;
   cout<<"平均分："<<average<<endl;
   cout<<"最高分："<<highest<<endl;
   cout<<"最低分："<<lowest<<endl;
   cout<<"及格(≥60):"<<pass<<"人"<<endl;
   cout<<"不及格："<<nopass<<"人"<<endl;
   return 0;
}
bool isPass(int score){
    if(score>=60){
        return 1;
    }else{
        return 0;
    }
}