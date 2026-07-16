#include <iostream>
using namespace std;
void swapWithPP(int** a,int** b);
int main(){
    int x = 5, y = 10;
int* pa = &x;
int* pb = &y;
swapWithPP(&pa, &pb);
cout<<x<<" "<<y;

}
void swapWithPP(int** a,int** b){
    int *p1=*a;
    int *p2=*b;
    int temp=0;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}