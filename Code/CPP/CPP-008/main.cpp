#include <iostream>
using namespace std;
int main(){
    int a;
    cout<<"请输入一个正整数：";
    cin>>a;
    int i=1;
  do{
    cout<<i<<" ";
    i++;
  }while(i<=a);
    return 0;
}