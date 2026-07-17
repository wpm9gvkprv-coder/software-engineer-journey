#include <iostream>
using namespace std;

class IntArray {
    int* data;
    int size;
public:
    IntArray(int n) : size(n) {
        data = new int[n];          // 构造函数里分配
        cout << "申请了 " << n << " 个 int" << endl;
    }
    
    ~IntArray() {
        delete[] data;              // 析构函数里释放
        cout << "释放了内存" << endl;
    }
    
    void set(int index, int val) { data[index] = val; }
    int get(int index) { return data[index]; }
};

int main() {
    IntArray arr(5);               // 这里 new
    arr.set(0, 42);
    cout << arr.get(0) << endl;
    // 不需要手动 delete！arr 出作用域自动释放
    return 0;
}
