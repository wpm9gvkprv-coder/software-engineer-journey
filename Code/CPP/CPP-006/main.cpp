#include <iostream>
using namespace std;
int main(){
    bool r1 = (5> 3) && (10 > 5);      // ?
bool r2 = (5 > 3) && (10 < 5);      // ?
bool r3 = (5 > 3) || (10 < 5);      // ?
bool r4 = !(5 > 3);                  // ?
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
    return 0;
}