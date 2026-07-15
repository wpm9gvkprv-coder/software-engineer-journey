#include <iostream>
using namespace std;

void swap(int &a, int &b) {   // 注意 & 的位置
    int temp = a;
    a = b;
    b = temp;
}

int main() {
  int x = 42;
int &r = x;    // r 是 x 的引用

int y = 99;
r = y;         // 这是把 r 改成指向 y，还是把 x 改成 99？
cout<<x;
}
