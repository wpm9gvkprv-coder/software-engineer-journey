#include <iostream>
using namespace std;
int main(){
    double a;
    cout<<"请输入你的分数：";
    cin>>a;
    if(a>=60){
        cout<<"及格";
    }else{
        cout<<"不及格";
    }
    return 0;
}