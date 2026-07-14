#include <iostream>
using namespace std;
void swapwithPOINTER(int *p1, int *p2) {
   
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main() {
    int x = 5, y = 10;
    int *p1=&x;
    int *p2=&y;
    swapwithPOINTER(p1,p2);
    std::cout << "x = " << x << ", y = " << y << std::endl;
}




