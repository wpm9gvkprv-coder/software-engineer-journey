#include <iostream>
using namespace std;
int main(){
    int a;
    int b;
    double sum;
    double diff;
    double product;
    double quotient;
    double remainder;
    cout<<"请输入第一个数：";
    cin>>a;
    cout<<"请输入第二个数：";
    cin>>b;
    sum=a+b;
    diff=a-b;
    product=a*b;
    quotient=static_cast<double>(a)/b;
    remainder=a%b;
    cout<<a<<"+"<<b<<"="<<sum<<endl;
    cout<<a<<"-"<<b<<"="<<diff<<endl;
    cout<<a<<"*"<<b<<"="<<product<<endl;
    cout<<a<<"/"<<b<<"="<<quotient<<endl;
    cout<<a<<"%"<<b<<"="<<remainder<<endl;
    return 0;
}