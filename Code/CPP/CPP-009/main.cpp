#include <iostream>
using namespace std;
int add(int x,int y);
int diff(int x,int y);
int product(int x,int y);
int quotient(int x,int y);
int remainder(int x,int y);
int main(){
    int a;
    int b;
    cout<<"请输入第一个数：";
    cin>>a;
    cout<<"请输入第二个数：";
    cin>>b;
    cout<<a<<"+"<<b<<"="<<add(a,b)<<endl;
     cout<<a<<"-"<<b<<"="<<diff(a,b)<<endl;
      cout<<a<<"*"<<b<<"="<<product(a,b)<<endl;
       cout<<a<<"/"<<b<<"="<<quotient(a,b)<<endl;
        cout<<a<<"%"<<b<<"="<<remainder(a,b)<<endl;
    return 0;
}
int add(int x,int y){
    return (x+y);
}
int diff(int x,int y){
    return(x-y);
}
int product(int x,int y){
    return(x*y);
}
int quotient(int x,int y){
    return(x/y);
}
int remainder(int x,int y){
    return(x%y);
}