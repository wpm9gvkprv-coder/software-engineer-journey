#include<iostream>
using namespace std;
class IntArray {
    int* data;
    int size;
public:
    IntArray(int n) {
        size = n;
        data = new int[n];      // 构造时分配
        cout << "构造: 申请了 " << n << " 个 int" << endl;
    }
    
    ~IntArray() {
        delete[] data;           // 析构时释放
        cout << "析构: 释放内存" << endl;
    }
    
    void set(int i, int v) { data[i] = v; }
    int get(int i) { return data[i]; }
};

int main() {
    IntArray arr(5);
    arr.set(0, 42);
    arr.set(1, 99);
    cout << arr.get(0) << " " << arr.get(1) << endl;
    // 不需要 delete[] —— 自动释放！
    return 0;
}
