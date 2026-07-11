#include <iostream>
using namespace std;
int main(){
    int a=1;
    float b=2.0;
    double c=3.00;
    char d[6]="apple";
    bool e=0;
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
    cout<<sizeof(a)<<" "<<sizeof(b)<<" "<<sizeof(c)<<" "<<sizeof(d)<<" "<<sizeof(e)<<" "<<endl;
    return 0;
}