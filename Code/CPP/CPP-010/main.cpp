#include <iostream>
using namespace std;
int main() {
    int x = 10;
    if (x > 5) {
        int x = 99;          // 里面又声明了一个叫 x 的变量
        cout << x << endl;   // 输出多少？
    }
    cout << x << endl;       // 这里呢？
}
